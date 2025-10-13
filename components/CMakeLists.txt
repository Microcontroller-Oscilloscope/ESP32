# CMakeLsts.txt - cmake for general Core files
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

idf_component_register(
    SRC_DIRS "Core/src" "Core/src/boards" "Core/src/boards/esp32" "Core/src/comm/hard_serial" "Core/src/nvm" "Core/src/osc_err" "Core/src/status"
    REQUIRES nvs_flash esp_timer
)