set( CMAKE_C_STANDARD 90 )
set( CMAKE_C_STANDARD_REQUIRED ON)
set( CMAKE_C_EXTENSIONS OFF )

add_library( ${A7_LIB} )
target_sources( ${A7_LIB} PRIVATE guil.c )
target_link_libraries( ${A7_LIB} PRIVATE SDL2::SDL2 )

# Apache License 2.0
# NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
# SPDX-License-Identifier: Apache-2.0
# lib: `guil` C90 Detached Process GUI Library
# Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ
