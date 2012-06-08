set(PROJECT ORSE)

project(${PROJECT})
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

find_package(OGRE REQUIRED)
if(${OGRE_FOUND}) 
  message(STATUS "Found Ogre")
else()
  message(FATAL_ERROR "Ogre NOT found")
endif()
find_package(Bullet REQUIRED)
if(${BULLET_FOUND}) 
  message(STATUS "Found Bullet")
else()
  message(FATAL_ERROR "Bullet NOT found")
endif()
find_package(OpenAL REQUIRED)
if(${OPENAL_FOUND}) 
  message(STATUS "Found OpenAL")
else()
  message(FATAL_ERROR "OpenAL NOT found")
endif()
find_package(Boost COMPONENTS system REQUIRED)
if(${Boost_FOUND}) 
  message(STATUS "Found Boost")
else()
  message(FATAL_ERROR "Boost NOT found")
endif()
find_package(Ogg)
if(${Ogg_FOUND}) 
  message(STATUS "Found Ogg")
else()
  message(FATAL_ERROR "Ogg NOT found")
endif()
find_package(Vorbis)
if(${Vorbis_FOUND}) 
  message(STATUS "Found Vorbis")
else()
  message(FATAL_ERROR "Vorbis NOT found")
endif()

include_directories(
  ${Ogg_INCLUDE_DIR}
  ${BULLET_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${OGRE_Plugin_CgProgramManager_INCLUDE_DIRS}
)
include_directories(${ORSE_SOURCE_DIR}/include)
include_directories(${ORSE_SOURCE_DIR}/include/physics/collisions)
include_directories(${ORSE_SOURCE_DIR}/include/physics/dynamics)
include_directories(${ORSE_SOURCE_DIR}/include/sound)
include_directories(
  ${OGRE_INCLUDE_DIRS}
  ${OPENAL_INCLUDE_DIRS}
  ${OGG_INCLUDE_DIRS}
  ${VORBISFILE_INCLUDE_DIRS}
)

aux_source_directory(src ORSE_LIB_SOURCES)
aux_source_directory(src/physics/collisions ORSE_Physics_Coll_LIB_SOURCES)
aux_source_directory(src/physics/collisions/Debug ORSE_Physics_Coll_Debug_LIB_SOURCES)
aux_source_directory(src/physics/collisions/Shapes ORSE_Physics_Coll_Shapes_LIB_SOURCES)
aux_source_directory(src/physics/collisions/Utils ORSE_Physics_Coll_Utils_LIB_SOURCES)
aux_source_directory(src/physics/dynamics ORSE_Physics_Dyn_LIB_SOURCES)
aux_source_directory(src/physics/dynamics/Constraints ORSE_Physics_Dyn_Constraints_LIB_SOURCES)
aux_source_directory(src/physics/dynamics/Prefab ORSE_Physics_Dyn_Prefab_LIB_SOURCES)
set(ORSE_Physics_LIB_SOURCES ${ORSE_Physics_Coll_LIB_SOURCES}
			     ${ORSE_Physics_Coll_Debug_LIB_SOURCES}
			     ${ORSE_Physics_Coll_Shapes_LIB_SOURCES}
			     ${ORSE_Physics_Coll_Utils_LIB_SOURCES}
			     ${ORSE_Physics_Dyn_LIB_SOURCES}
			     ${ORSE_Physics_Dyn_Constraints_LIB_SOURCES}
			     ${ORSE_Physics_Dyn_Prefab_LIB_SOURCES}
)
aux_source_directory(src/sound ORSE_Sound_LIB_SOURCES)

add_library(OrseMain SHARED ${ORSE_LIB_SOURCES})
add_library(OrsePhysics SHARED ${ORSE_Physics_LIB_SOURCES})
add_library(OrseSound SHARED ${ORSE_Sound_LIB_SOURCES})

target_link_libraries(OrseMain
  ${OGRE_LIBRARIES},
  ${OGRE_Plugin_CgProgramManager_LIBRARIES}
)
target_link_libraries(OrsePhysics
  ${OGRE_LIBRARIES},
  ${BULLET_LIBRARIES}
)
target_link_libraries(OrseSound
  ${OGRE_LIBRARIES},
#  ${Ogg_LIBRARIES},
  ${Vorbis_LIBRARIES}
)
add_definitions(-logg)
#orse_sound deps
#  boost::thread
#  openal
#  ogg
#  vorbis
#  ogre

install(TARGETS OrseMain OrsePhysics OrseSound
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(FILES
  ${ORSE_SOURCE_DIR}/include/common.h
  ${ORSE_SOURCE_DIR}/include/node.h
  ${ORSE_SOURCE_DIR}/include/resourcemgr.h
  ${ORSE_SOURCE_DIR}/include/root.h
DESTINATION /usr/include/orse
)
install(DIRECTORY include/sound DESTINATION /usr/include/orse)
install(DIRECTORY include/physics DESTINATION /usr/include/orse)

if(${APPLE})
  #хз
elseif(${UNIX} AND NOT ${APPLE})
  #CPack
  #making deb or rpm packs
elseif(${CYGWIN})
  #main on windows
elseif(${WIN32})
  #installer ?)
endif()
