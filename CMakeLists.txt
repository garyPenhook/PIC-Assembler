cmake_minimum_required(VERSION 3.20)
project(PIC_Assembler)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optimization flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Source files (common to all targets)
set(COMMON_SOURCES
    src/lexer.cpp
    src/parser.cpp
    src/instruction.cpp
    src/assembler.cpp
    src/hex_generator.cpp
    src/symbol_table.cpp
    src/error_reporter.cpp
    src/device_specs.cpp
    src/expression.cpp
    src/cli.cpp
    src/macro_table.cpp
    src/preprocessor.cpp
)

# Main app sources
set(SOURCES ${COMMON_SOURCES} main.cpp)

# Header files
set(HEADERS
    src/lexer.h
    src/parser.h
    src/instruction.h
    src/assembler.h
    src/hex_generator.h
    src/symbol_table.h
    src/device_specs.h
    src/expression.h
    src/cli.h
    src/macro_table.h
    src/preprocessor.h
)

# Create executable
add_executable(gnsasm ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(gnsasm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Install executable
install(TARGETS gnsasm DESTINATION bin)

# Test executable for instruction encoding verification (optional - disabled if file missing)
# if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_instruction_encoding.cpp")
#     add_executable(test_instruction_encoding test_instruction_encoding.cpp ${COMMON_SOURCES} ${HEADERS})
#     target_include_directories(test_instruction_encoding PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
#     enable_testing()
#     add_test(NAME InstructionEncoding COMMAND test_instruction_encoding)
# endif()


