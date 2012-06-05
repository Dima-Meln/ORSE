set(PROJECT ORSE)

project(${PROJECT})
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")

find_package(Bullet REQUIRED)
if(${BULLET_FOUND}) 
  message("Bullet found")
else()
  message(FATAL_ERROR "Bullet NOT found")
endif()
find_package(OGRE REQUIRED)
if(${OGRE_FOUND}) 
  message("Ogre found")
else()
  message(FATAL_ERROR "Ogre NOT found")
endif()
find_package(OpenAL REQUIRED)
if(${OPENAL_FOUND}) 
  message("OpenAL found")
else()
  message(FATAL_ERROR "OpenAL NOT found")
endif()
find_package(Boost COMPONENTS system REQUIRED)
if(${Boost_FOUND}) 
  message("Boost found")
else()
  message(FATAL_ERROR "Boost NOT found")
endif()

include_directories(
  ${BULLET_INCLUDE_DIRS},
  ${OGRE_INCLUDE_DIRS},
  ${OGRE_Plugin_CgProgramManager_INCLUDE_DIRS},
  ${ORSE_SOURCE_DIR}/include
)

aux_source_directory(src ORSE_LIB_SOURCES)
aux_source_directory(src/physics/collisions ORSE_Physics_Coll_LIB_SOURCES)
aux_source_directory(src/physics/dynamics ORSE_Physics_Dyn_LIB_SOURCES)
set(ORSE_Physics_LIB_SOURCES ${ORSE_Physics_Coll_LIB_SOURCES} ${ORSE_Physics_Dyn_LIB_SOURCES})
aux_source_directory(src/sound ORSE_Sound_LIB_SOURCES)

add_library(OrseMain SHARED ${ORSE_LIB_SOURCES})
add_library(OrsePhysics SHARED ${ORSE_Physics_LIB_SOURCES})
add_library(OrseSound SHARED ${ORSE_Sound_LIB_SOURCES})

target_link_libraries(OrseMain
  ${BULLET_LIBRARIES},
  ${OGRE_LIBRARIES},
  ${OGRE_Plugin_CgProgramManager_LIBRARIES}
)

install(TARGETS OrseMain OrsePhysics OrseSound
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

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
add_subdirectory(include)
add_subdirectory(src)