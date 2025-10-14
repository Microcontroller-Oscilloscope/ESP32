# CMakeLsts.txt - cmake for testing
# Copyright (C) 2025 Camren Chraplak

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html

cmake_minimum_required(VERSION 3.5)
include($ENV{IDF_PATH}/tools/cmake/version.cmake)

add_compile_definitions(ARDUINO_ESP32_DEV=1)
add_compile_definitions(OSC_BOARD_MAJOR_VERSION=0)
add_compile_definitions(OSC_BOARD_MINOR_VERSION=3)
add_compile_definitions(OSC_BOARD_PATCH_VERSION=0)
add_compile_definitions(DEFAULT_BAUD_RATE=9600)
add_compile_definitions(__ENABLED_ENV__=1)
add_compile_definitions(__ENABLED_TEST__=1)
add_compile_definitions(__NVM_BEGIN__=1)
add_compile_definitions(__NVM_BEGIN_RETURN__=1)
add_compile_definitions(BAUD_RATE=115200)
add_compile_definitions(__ENABLED_BASE__=1)
add_compile_definitions(__ENABLED_DEV_TEST__=1)
add_compile_definitions(__IGNORE_WARNINGS__=1)
add_compile_definitions(ESP32=1)
add_compile_definitions(__TEST_CASES__=1)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../components/Core/src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../components/UnityTests/src)

# Add newly added components to one of these lines:
# 1. Add here if the component is compatible with IDF >= v4.3
set(EXTRA_COMPONENT_DIRS "../components")

set(TEST_COMPONENTS "")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(unit_test)