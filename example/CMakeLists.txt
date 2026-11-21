cmake_minimum_required( VERSION 3.14...3.27 )
project( example VERSION 0.0.0 LANGUAGES CXX )
set( A7_APP ${PROJECT_NAME} )

if( NOT TARGET son8__windowed )
   include( FetchContent )
   message( STATUS "${A7_APP}: FetchContent `soneight/windowed`" )
   fetchcontent_declare(
      son8__windowed
      GIT_REPOSITORY https://github.com/soneight/windowed.git
      GIT_TAG        main
   )
   fetchcontent_makeavailable( son8__windowed )
endif( )
message( STATUS "${A7_APP}: target `son8__windowed` found" )

add_executable( ${A7_APP} main.cxx )
target_link_libraries( ${A7_APP} PRIVATE son8::windowed a7::guil )

# Apache License 2.0
# NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
# SPDX-License-Identifier: Apache-2.0
# lib: `guil` C90 Detached Process GUI Library
# Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ
