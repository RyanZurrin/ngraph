# ******************************************************************************
# Copyright 2017-2020 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ******************************************************************************

add_definitions(-DIN_NGRAPH_LIBRARY)

include_directories(ngraph)

add_subdirectory(resource)

# This must be added before any backend that uses MLIR
if (NGRAPH_MLIR_ENABLE)
    add_subdirectory(${NGRAPH_MLIR_SOURCE_DIR})
endif()

add_subdirectory(ngraph)

add_subdirectory(runtime)

if (NGRAPH_TOOLS_ENABLE)
    add_subdirectory(tools)
    message(STATUS "tools enabled")
else()
    message(STATUS "tools disabled")
endif()
