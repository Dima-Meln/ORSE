set(PROJECT ORSE)

project(${PROJECT})
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules/;${CMAKE_MODULE_PATH}")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

find_package(OGRE REQUIRED)
if(${OGRE_FOUND}) 
  message(STATUS "Found Ogre")
else()
  message(FATAL_ERROR "Ogre NOT found")
endif()
find_package(OIS REQUIRED)
if(${OIS_FOUND}) 
  message(STATUS "Found OIS")
else()
  message(FATAL_ERROR "OIS NOT found")
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
find_package(VORBISFILE)
if(${Vorbis_FOUND}) 
  message(STATUS "Found Vorbis")
else()
  message(FATAL_ERROR "Vorbis NOT found")
endif()

include_directories(
  ${Ogg_INCLUDE_DIR}
  #${BULLET_INCLUDE_DIRS}
  /usr/local/include/bullet/
  ${OIS_INCLUDE_DIRS}
)
include_directories(${ORSE_SOURCE_DIR}/include)
include_directories(${ORSE_SOURCE_DIR}/include/physics/collisions)
include_directories(${ORSE_SOURCE_DIR}/include/physics/dynamics)
include_directories(${ORSE_SOURCE_DIR}/include/sound)
include_directories(
  ${OGRE_INCLUDE_DIRS}
  ${OPENAL_INCLUDE_DIR}
  ${OGG_INCLUDE_DIRS}
  ${VORBISFILE_INCLUDE_DIRS}
)

aux_source_directory(src ORSE_LIB_SOURCES)
aux_source_directory(src/physics ORSE_Physics_LIB_SOURCES)
aux_source_directory(src/sound ORSE_Sound_LIB_SOURCES)

add_library(OrseMain SHARED ${ORSE_LIB_SOURCES})
add_library(OrsePhysics SHARED ${ORSE_Physics_LIB_SOURCES})
add_library(OrseSound SHARED ${ORSE_Sound_LIB_SOURCES})

target_link_libraries(OrseMain
  ${OGRE_LIBRARIES}
  ${OIS_LIBRARY_REL}
)
set(bullet libBulletCollision.so libBulletDynamics.so libBulletMultiThreaded.so libBulletSoftBody.so libBulletSoftBodySolvers_OpenCL_Mini.so libLinearMath.so)
target_link_libraries(OrsePhysics
  ${OGRE_LIBRARIES}
  ${BULLET_LIBRARIES}
  #${bullet}
)
target_link_libraries(OrseSound
  ${OGRE_LIBRARIES}
  ${Ogg_LIBRARIES}
  ${Vorbis_LIBRARIES}
  ${VORBISFILE_LIBRARIES}
  ${OPENAL_LIBRARY}
)

install(TARGETS OrseMain OrsePhysics OrseSound
#  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(FILES
  ${ORSE_SOURCE_DIR}/include/OrseCommon.h
  ${ORSE_SOURCE_DIR}/include/OrsePreRequisites.h
  ${ORSE_SOURCE_DIR}/include/OrseInputManager.h
  ${ORSE_SOURCE_DIR}/include/OrseNode.h
  ${ORSE_SOURCE_DIR}/include/OrseResourceMgr.h
  ${ORSE_SOURCE_DIR}/include/OrseRoot.h
  ${ORSE_SOURCE_DIR}/include/OrsePhysicsManager.h
  ${ORSE_SOURCE_DIR}/include/OrseWorld.h
  ${ORSE_SOURCE_DIR}/include/OrseGameObject.h
  ${ORSE_SOURCE_DIR}/include/OrseStatesManager.h
DESTINATION /usr/include/orse
)
install(FILES ${ORSE_SOURCE_DIR}/cmake/ORSE/FindOrse.cmake ${ORSE_SOURCE_DIR}/cmake/FindCEGUI.cmake DESTINATION /usr/share/cmake-2.8/Modules)
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
