# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dima/projects/ORSE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dima/projects/ORSE/build

# Include any dependencies generated for this target.
include CMakeFiles/OrseMain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OrseMain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OrseMain.dir/flags.make

CMakeFiles/OrseMain.dir/src/node.cpp.o: CMakeFiles/OrseMain.dir/flags.make
CMakeFiles/OrseMain.dir/src/node.cpp.o: ../src/node.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dima/projects/ORSE/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/OrseMain.dir/src/node.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OrseMain.dir/src/node.cpp.o -c /home/dima/projects/ORSE/src/node.cpp

CMakeFiles/OrseMain.dir/src/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrseMain.dir/src/node.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dima/projects/ORSE/src/node.cpp > CMakeFiles/OrseMain.dir/src/node.cpp.i

CMakeFiles/OrseMain.dir/src/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrseMain.dir/src/node.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dima/projects/ORSE/src/node.cpp -o CMakeFiles/OrseMain.dir/src/node.cpp.s

CMakeFiles/OrseMain.dir/src/node.cpp.o.requires:
.PHONY : CMakeFiles/OrseMain.dir/src/node.cpp.o.requires

CMakeFiles/OrseMain.dir/src/node.cpp.o.provides: CMakeFiles/OrseMain.dir/src/node.cpp.o.requires
	$(MAKE) -f CMakeFiles/OrseMain.dir/build.make CMakeFiles/OrseMain.dir/src/node.cpp.o.provides.build
.PHONY : CMakeFiles/OrseMain.dir/src/node.cpp.o.provides

CMakeFiles/OrseMain.dir/src/node.cpp.o.provides.build: CMakeFiles/OrseMain.dir/src/node.cpp.o

CMakeFiles/OrseMain.dir/src/root.cpp.o: CMakeFiles/OrseMain.dir/flags.make
CMakeFiles/OrseMain.dir/src/root.cpp.o: ../src/root.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dima/projects/ORSE/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/OrseMain.dir/src/root.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OrseMain.dir/src/root.cpp.o -c /home/dima/projects/ORSE/src/root.cpp

CMakeFiles/OrseMain.dir/src/root.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrseMain.dir/src/root.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dima/projects/ORSE/src/root.cpp > CMakeFiles/OrseMain.dir/src/root.cpp.i

CMakeFiles/OrseMain.dir/src/root.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrseMain.dir/src/root.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dima/projects/ORSE/src/root.cpp -o CMakeFiles/OrseMain.dir/src/root.cpp.s

CMakeFiles/OrseMain.dir/src/root.cpp.o.requires:
.PHONY : CMakeFiles/OrseMain.dir/src/root.cpp.o.requires

CMakeFiles/OrseMain.dir/src/root.cpp.o.provides: CMakeFiles/OrseMain.dir/src/root.cpp.o.requires
	$(MAKE) -f CMakeFiles/OrseMain.dir/build.make CMakeFiles/OrseMain.dir/src/root.cpp.o.provides.build
.PHONY : CMakeFiles/OrseMain.dir/src/root.cpp.o.provides

CMakeFiles/OrseMain.dir/src/root.cpp.o.provides.build: CMakeFiles/OrseMain.dir/src/root.cpp.o

CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o: CMakeFiles/OrseMain.dir/flags.make
CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o: ../src/resourcemgr.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dima/projects/ORSE/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o -c /home/dima/projects/ORSE/src/resourcemgr.cpp

CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dima/projects/ORSE/src/resourcemgr.cpp > CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.i

CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dima/projects/ORSE/src/resourcemgr.cpp -o CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.s

CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.requires:
.PHONY : CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.requires

CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.provides: CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.requires
	$(MAKE) -f CMakeFiles/OrseMain.dir/build.make CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.provides.build
.PHONY : CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.provides

CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.provides.build: CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o

# Object files for target OrseMain
OrseMain_OBJECTS = \
"CMakeFiles/OrseMain.dir/src/node.cpp.o" \
"CMakeFiles/OrseMain.dir/src/root.cpp.o" \
"CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o"

# External object files for target OrseMain
OrseMain_EXTERNAL_OBJECTS =

libOrseMain.so: CMakeFiles/OrseMain.dir/src/node.cpp.o
libOrseMain.so: CMakeFiles/OrseMain.dir/src/root.cpp.o
libOrseMain.so: CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o
libOrseMain.so: /usr/lib/x86_64-linux-gnu/libOgreMain.so
libOrseMain.so: /usr/local/lib/OGRE/Plugin_CgProgramManager.so
libOrseMain.so: CMakeFiles/OrseMain.dir/build.make
libOrseMain.so: CMakeFiles/OrseMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libOrseMain.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OrseMain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OrseMain.dir/build: libOrseMain.so
.PHONY : CMakeFiles/OrseMain.dir/build

CMakeFiles/OrseMain.dir/requires: CMakeFiles/OrseMain.dir/src/node.cpp.o.requires
CMakeFiles/OrseMain.dir/requires: CMakeFiles/OrseMain.dir/src/root.cpp.o.requires
CMakeFiles/OrseMain.dir/requires: CMakeFiles/OrseMain.dir/src/resourcemgr.cpp.o.requires
.PHONY : CMakeFiles/OrseMain.dir/requires

CMakeFiles/OrseMain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OrseMain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OrseMain.dir/clean

CMakeFiles/OrseMain.dir/depend:
	cd /home/dima/projects/ORSE/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dima/projects/ORSE /home/dima/projects/ORSE /home/dima/projects/ORSE/build /home/dima/projects/ORSE/build /home/dima/projects/ORSE/build/CMakeFiles/OrseMain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OrseMain.dir/depend

