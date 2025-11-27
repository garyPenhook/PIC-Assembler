cmake_minimum_required(VERSION 3.20)
project(PIC_Assembler)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optimization flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Source files
set(SOURCES
    src/lexer.cpp
    src/parser.cpp
    src/instruction.cpp
    src/assembler.cpp
    src/hex_generator.cpp
    src/symbol_table.cpp
    src/error_reporter.cpp
    src/cli.cpp
    main.cpp
)

# Header files
set(HEADERS
    src/lexer.h
    src/parser.h
    src/instruction.h
    src/assembler.h
    src/hex_generator.h
    src/symbol_table.h
    src/cli.h
)

# Create executable
add_executable(gnsasm ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(gnsasm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Install executable
install(TARGETS gnsasm DESTINATION bin)
