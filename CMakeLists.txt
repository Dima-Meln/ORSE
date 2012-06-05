

project(ORSE)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")

find_package(Bullet REQUIRED)
if(${BULLET_FOUND}) 
  message("Bullet found")
endif()
find_package(OGRE REQUIRED)
if(${OGRE_FOUND}) 
  message("Ogre found")
endif()
find_package(OpenAL REQUIRED)
if(${OpenAL_FOUND}) 
  message("openal found")
endif()
find_package(Boost COMPONENTS system REQUIRED)
if(${BOOST_FOUND}) 
  message("Boost found")
endif()

include_directories(
  ${BULLET_INCLUDE_DIRS},
  ${OGRE_INCLUDE_DIR}
)

set(ORSE_LIB_SOURCES src/root.cpp
		     src/resourcemgr.cpp
		     src/viewport.cpp
		     src/scenemanager.cpp
		     src/window.cpp
		     src/network/connection.cpp
		     src/network/auth.cpp
		     src/node.cpp
		     src/entity.cpp)
add_library(${PROJECT} SHARED ${ORSE_LIB_SOURCES})

target_link_libraries(${PROJECT} 
  ${BULLET_LIBRARIES},
  ${SDL_LIBRARY}
)

install(TARGETS ${PROJECT}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

if(${APPLE})
  #хз
elseif(${UNIX})
  #CPack
  #making deb or rpm packs
elseif(${WIN32})
  #installer ?)
endif()
add_subdirectory(include)
add_subdirectory(src)