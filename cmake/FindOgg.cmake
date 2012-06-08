# Copyright (c) 2009, Whispersoft s.r.l.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
# * Neither the name of Whispersoft s.r.l. nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# Finds Ogg library
#
#  Ogg_INCLUDE_DIR - where to find ogg.h, etc.
#  Ogg_LIBRARIES   - List of libraries when using Ogg.
#  Ogg_FOUND       - True if Ogg found.
#

if (Ogg_INCLUDE_DIR)
  # Already in cache, be silent
  set(Ogg_FIND_QUIETLY TRUE)
endif (Ogg_INCLUDE_DIR)

find_path(Ogg_INCLUDE_DIR ogg/ogg.h
  /opt/local/include
  /usr/local/include
  /usr/include
)

set(Ogg_NAMES ogg)
find_library(Ogg_LIBRARY
  NAMES ${Ogg_NAMES}
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)

if (Ogg_INCLUDE_DIR AND Ogg_LIBRARY)
   set(Ogg_FOUND TRUE)
   set( Ogg_LIBRARIES ${Ogg_LIBRARY} )
else (Ogg_INCLUDE_DIR AND Ogg_LIBRARY)
   set(Ogg_FOUND FALSE)
   set(Ogg_LIBRARIES)
endif (Ogg_INCLUDE_DIR AND Ogg_LIBRARY)

if (Ogg_FOUND)
   if (NOT Ogg_FIND_QUIETLY)
      message(STATUS "Found Ogg: ${Ogg_LIBRARY}")
   endif (NOT Ogg_FIND_QUIETLY)
else (Ogg_FOUND)
   if (Ogg_FIND_REQUIRED)
      message(STATUS "Looked for Ogg libraries named ${Ogg_NAMES}.")
      message(STATUS "Include file detected: [${Ogg_INCLUDE_DIR}].")
      message(STATUS "Lib file detected: [${Ogg_LIBRARY}].")
      message(FATAL_ERROR "=========> Could NOT find Ogg library")
   endif (Ogg_FIND_REQUIRED)
endif (Ogg_FOUND)

mark_as_advanced(
  Ogg_LIBRARY
  Ogg_INCLUDE_DIR
)