cmake_minimum_required( VERSION 3.14...3.27 )
project( guil VERSION 0.0.0 LANGUAGES C )
set( A7_LIB a7__${PROJECT_NAME} )

if( NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" )
    message( FATAL_ERROR "${A7_LIB}: unsupported platform '${CMAKE_SYSTEM_NAME}' (currently Linux only)" )
endif( )

find_package( SDL2 REQUIRED )
add_subdirectory( source )
add_library( a7::${PROJECT_NAME} ALIAS ${A7_LIB} )
target_include_directories( ${A7_LIB} PUBLIC include )
# TODO: remove below - temporary
add_subdirectory( example )

# Apache License 2.0
# NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
# SPDX-License-Identifier: Apache-2.0
# lib: `guil` C90 Detached Process GUI Library
# Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ
