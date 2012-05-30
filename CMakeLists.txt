set(PROJECT ORSE)

project(${PROJECT})
cmake_minimum_required(VERSION 2.8)

find_package(Bullet REQUIRED)
if(${BULLET_FOUND}) 
  message("Bullet found")
endif()
find_package(Ogre REQUIRED)
if(${OGRE_FOUND}) 
  message("Ogre found")
endif()
find_package(OpenAL REQUIRED)
if(${OpenAL_FOUND}) 
  message("OGRE found")
endif()
include(${QT_USE_FILE})
find_package(Boost COMPONENTS asio REQUIRED)
if(${BOOST_FOUND}) 
  message("Boost found")
endif()
find_package(SDL REQUIRED)
if(${SDL_FOUND}) 
  message("SDL found")
endif()

include_directories(SYSTEM
  ${BULLET_INCLUDE_DIRS},
  ${SDL_INCLUDE_DIR}
)

set(ORSE_LIB_SOURCES root.cpp
		     resourcemgr.cpp
		     viewport.cpp
		     scenemanager.cpp
		     window.cpp
		     network/connection.cpp
		     network/auth.cpp
		     video.cpp
		     audio.cpp
		     node.cpp
		     entity.cpp)
add_library(${PROJECT} ${ORSE_LIB_SOURCES})

target_link_libraries(${PROJECT} 
  ${BULLET_LIBRARIES},
  ${SDL_LIBRARY}
)

install(TARGETS /usr/lib/ORSE ${PROJECT})

if(${APPLE})
  #хз
elseif(${UNIX})
  #CPack
  #making deb or rpm packs
elseif(${WIN32})
  #installer ?)
endif()
add_subdirectory(input)
add_subdirectory(include)
add_subdirectory(src)