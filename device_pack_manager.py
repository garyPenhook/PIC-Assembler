#!/usr/bin/env python3
"""
Device Pack Manager for gnsasm
==============================

Utility to extract and organize Microchip device family pack (DFP) files
for use with the gnsasm PIC assembler.

Features:
- Scans all downloaded device packs
- Extracts .inc (assembly header) files
- Parses device definitions
- Generates device catalogs
- Creates gnsasm-compatible include directories

Usage:
    python3 device_pack_manager.py --scan <downloads_dir>
    python3 device_pack_manager.py --extract <downloads_dir> --output ./device_includes
    python3 device_pack_manager.py --catalog <downloads_dir>
"""

import os
import sys
import json
import re
import shutil
import argparse
from pathlib import Path
from typing import Dict, List, Tuple
import xml.etree.ElementTree as ET

class DevicePackManager:
    """Manages Microchip device family packs for gnsasm."""

    def __init__(self, verbose=False):
        self.verbose = verbose
        self.devices = {}  # device_name -> info
        self.packs = {}    # pack_name -> info

    def log(self, msg):
        """Print if verbose mode enabled."""
        if self.verbose:
            print(msg)

    def scan_packs(self, downloads_dir: str) -> Dict:
        """
        Scan downloads directory for device packs.

        Args:
            downloads_dir: Directory containing .atpack_FILES directories

        Returns:
            Dictionary of found packs
        """
        print(f"Scanning {downloads_dir} for device packs...")
        downloads = Path(downloads_dir)

        packs_found = {}

        # Look for directories matching *_DFP.*_FILES pattern
        for item in downloads.iterdir():
            if item.is_dir() and "_DFP." in item.name and "_FILES" in item.name:
                pack_name = item.name.replace("_FILES", "")
                self.log(f"Found pack: {pack_name}")

                # Extract pack info
                info = {
                    'name': pack_name,
                    'path': item,
                    'inc_files': [],
                    'pic_files': [],
                    'config_files': []
                }

                # Find .inc files
                xc8_path = item / "xc8" / "pic" / "include" / "proc"
                if xc8_path.exists():
                    for inc_file in xc8_path.glob("*.inc"):
                        info['inc_files'].append(inc_file)
                        device_name = inc_file.stem
                        if device_name not in self.devices:
                            self.devices[device_name] = {
                                'name': device_name,
                                'pack': pack_name,
                                'inc_file': str(inc_file),
                                'h_file': None,
                                'pic_file': None,
                                'config_file': None
                            }

                # Find .PIC files
                edc_path = item / "edc"
                if edc_path.exists():
                    for pic_file in edc_path.glob("*.PIC"):
                        info['pic_files'].append(pic_file)
                        device_name = pic_file.stem
                        if device_name not in self.devices:
                            self.devices[device_name] = {'name': device_name, 'pack': pack_name}
                        self.devices[device_name]['pic_file'] = str(pic_file)

                # Find config files
                config_path = item / "xc8" / "pic" / "dat" / "cfgdata"
                if config_path.exists():
                    for cfg_file in config_path.glob("*.cfgdata"):
                        info['config_files'].append(cfg_file)

                packs_found[pack_name] = info
                self.packs[pack_name] = info

        print(f"Found {len(packs_found)} device packs with {len(self.devices)} unique devices")
        return packs_found

    def list_devices(self, pack_filter: str = None) -> None:
        """
        List all discovered devices.

        Args:
            pack_filter: Optional pack name to filter results
        """
        if not self.devices:
            print("No devices found. Run --scan first.")
            return

        print("\nDiscovered Devices:")
        print("=" * 80)

        for device_name in sorted(self.devices.keys()):
            dev = self.devices[device_name]

            if pack_filter and pack_filter not in dev['pack']:
                continue

            print(f"\n{device_name.upper()}")
            print(f"  Pack: {dev['pack']}")
            print(f"  .inc file: {'✓' if dev.get('inc_file') else '✗'}")
            print(f"  .PIC file: {'✓' if dev.get('pic_file') else '✗'}")

    def extract_includes(self, output_dir: str) -> None:
        """
        Extract all .inc files to a convenient location.

        Args:
            output_dir: Output directory for .inc files
        """
        if not self.devices:
            print("No devices found. Run --scan first.")
            return

        output_path = Path(output_dir)
        output_path.mkdir(parents=True, exist_ok=True)

        print(f"\nExtracting .inc files to {output_dir}...")

        copied = 0
        for device_name, dev in self.devices.items():
            if dev.get('inc_file'):
                src = Path(dev['inc_file'])
                if src.exists():
                    dst = output_path / src.name
                    shutil.copy2(src, dst)
                    self.log(f"Copied {src.name}")
                    copied += 1

        print(f"Extracted {copied} .inc files")

        # Create an index file
        index_file = output_path / "INDEX.md"
        with open(index_file, 'w') as f:
            f.write("# Device Include Files\n\n")
            f.write("## Usage with gnsasm\n\n")
            f.write("Add this directory to your include path or use relative paths:\n\n")
            f.write("```asm\n")
            f.write("#include \"device_includes/pic16f18076.inc\"\n")
            f.write("```\n\n")
            f.write("## Available Devices\n\n")

            for device_name in sorted(self.devices.keys()):
                dev = self.devices[device_name]
                if dev.get('inc_file'):
                    f.write(f"- `{device_name}.inc` - {dev['pack']}\n")

    def generate_catalog(self, output_file: str = None) -> str:
        """
        Generate a JSON catalog of all devices and their locations.

        Args:
            output_file: Optional file to write catalog to

        Returns:
            JSON string of catalog
        """
        if not self.devices:
            print("No devices found. Run --scan first.")
            return "{}"

        catalog = {
            'version': '1.0',
            'generated': __import__('datetime').datetime.now().isoformat(),
            'pack_count': len(self.packs),
            'device_count': len(self.devices),
            'packs': {},
            'devices': self.devices
        }

        for pack_name, pack_info in self.packs.items():
            catalog['packs'][pack_name] = {
                'inc_files': len(pack_info['inc_files']),
                'pic_files': len(pack_info['pic_files']),
                'config_files': len(pack_info['config_files'])
            }

        catalog_json = json.dumps(catalog, indent=2, default=str)

        if output_file:
            Path(output_file).write_text(catalog_json)
            print(f"Catalog written to {output_file}")

        return catalog_json

    def create_device_header(self, device_name: str, output_file: str) -> bool:
        """
        Create a gnsasm-compatible device header file.

        Args:
            device_name: Device name (e.g., 'PIC16F18076')
            output_file: Output .asm or .inc file

        Returns:
            True if successful
        """
        if device_name.lower() not in self.devices:
            print(f"Device {device_name} not found in database")
            return False

        dev = self.devices[device_name.lower()]
        inc_file = dev.get('inc_file')

        if not inc_file or not Path(inc_file).exists():
            print(f"Include file not found for {device_name}")
            return False

        # Create header that includes the device .inc file
        with open(output_file, 'w') as f:
            f.write(f"; Device Header for {device_name.upper()}\n")
            f.write(f"; Auto-generated by device_pack_manager.py\n\n")
            f.write(f"PROCESSOR {device_name.upper()}\n\n")
            f.write(f"; Include device register definitions from Microchip\n")
            f.write(f"#include \"{inc_file}\"\n\n")
            f.write(f"; Add your code below:\n\n")

        print(f"Created header file: {output_file}")
        return True

    def get_device_info(self, device_name: str) -> Dict:
        """
        Get detailed info about a device.

        Args:
            device_name: Device name

        Returns:
            Device information dictionary
        """
        key = device_name.lower()
        return self.devices.get(key, {})


def main():
    parser = argparse.ArgumentParser(
        description='Microchip Device Pack Manager for gnsasm',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Scan Downloads folder for device packs
  python3 device_pack_manager.py --scan ~/Downloads

  # Extract all .inc files to local directory
  python3 device_pack_manager.py --scan ~/Downloads --extract ./device_includes

  # Generate device catalog
  python3 device_pack_manager.py --scan ~/Downloads --catalog device_catalog.json

  # List all devices from PIC16F1xxxx pack
  python3 device_pack_manager.py --scan ~/Downloads --list --filter PIC16F1xxxx
        """
    )

    parser.add_argument('--scan', type=str, required=False,
                       help='Directory containing device packs')
    parser.add_argument('--extract', type=str, required=False,
                       help='Extract .inc files to this directory')
    parser.add_argument('--catalog', type=str, required=False,
                       help='Generate catalog JSON file')
    parser.add_argument('--list', action='store_true',
                       help='List all discovered devices')
    parser.add_argument('--filter', type=str,
                       help='Filter results by pack name')
    parser.add_argument('--device', type=str,
                       help='Get info about specific device')
    parser.add_argument('--create-header', type=str,
                       help='Create device header for gnsasm (device name)')
    parser.add_argument('--output', type=str, default='device.h',
                       help='Output file for --create-header')
    parser.add_argument('-v', '--verbose', action='store_true',
                       help='Verbose output')

    args = parser.parse_args()

    # Validate that scan is provided when needed
    if (args.list or args.catalog or args.extract or args.device or args.create_header) and not args.scan:
        parser.error("--scan is required for this operation")

    manager = DevicePackManager(verbose=args.verbose)

    # Scan packs
    if args.scan:
        manager.scan_packs(args.scan)

    # List devices
    if args.list:
        manager.list_devices(args.filter)

    # Extract includes
    if args.extract:
        manager.extract_includes(args.extract)

    # Generate catalog
    if args.catalog:
        manager.generate_catalog(args.catalog)

    # Get device info
    if args.device:
        info = manager.get_device_info(args.device)
        if info:
            print(f"\nDevice: {args.device.upper()}")
            print(json.dumps(info, indent=2, default=str))
        else:
            print(f"Device {args.device} not found")

    # Create header
    if args.create_header:
        manager.create_device_header(args.create_header, args.output)


if __name__ == '__main__':
    main()
