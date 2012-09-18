include(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)
set(ORSE_LIBRARIES 
  /usr/local/lib/libOrseMain.so
  /usr/local/lib/libOrsePhysics.so
#  /usr/local/lib/libOrseSound.so
)
set(ORSE_INCLUDE_DIRS 
  /usr/include/orse
  /usr/include/orse/physics/collisions
  /usr/include/orse/physics/dynamics
)
set(ORSE_FOUND true)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(ORSE "fail ORSE" ORSE_LIBRARIES ORSE_INCLUDE_DIRS
                                  VERSION_VAR "0.0.1")