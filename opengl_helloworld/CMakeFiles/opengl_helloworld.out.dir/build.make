# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/choyg/Desktop/workspace/opengl/opengl_helloworld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/choyg/Desktop/workspace/opengl/opengl_helloworld

# Include any dependencies generated for this target.
include CMakeFiles/opengl_helloworld.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl_helloworld.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl_helloworld.out.dir/flags.make

CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o: CMakeFiles/opengl_helloworld.out.dir/flags.make
CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o: opengl_helloworld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/choyg/Desktop/workspace/opengl/opengl_helloworld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o -c /home/choyg/Desktop/workspace/opengl/opengl_helloworld/opengl_helloworld.cpp

CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/choyg/Desktop/workspace/opengl/opengl_helloworld/opengl_helloworld.cpp > CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.i

CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/choyg/Desktop/workspace/opengl/opengl_helloworld/opengl_helloworld.cpp -o CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.s

CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.requires:

.PHONY : CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.requires

CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.provides: CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.requires
	$(MAKE) -f CMakeFiles/opengl_helloworld.out.dir/build.make CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.provides.build
.PHONY : CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.provides

CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.provides.build: CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o


# Object files for target opengl_helloworld.out
opengl_helloworld_out_OBJECTS = \
"CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o"

# External object files for target opengl_helloworld.out
opengl_helloworld_out_EXTERNAL_OBJECTS =

opengl_helloworld.out: CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o
opengl_helloworld.out: CMakeFiles/opengl_helloworld.out.dir/build.make
opengl_helloworld.out: /usr/local/lib/libglfw3.a
opengl_helloworld.out: /usr/lib/x86_64-linux-gnu/libGL.so
opengl_helloworld.out: /usr/lib/x86_64-linux-gnu/librt.so
opengl_helloworld.out: /usr/lib/x86_64-linux-gnu/libm.so
opengl_helloworld.out: /usr/lib/x86_64-linux-gnu/libX11.so
opengl_helloworld.out: CMakeFiles/opengl_helloworld.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/choyg/Desktop/workspace/opengl/opengl_helloworld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opengl_helloworld.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl_helloworld.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl_helloworld.out.dir/build: opengl_helloworld.out

.PHONY : CMakeFiles/opengl_helloworld.out.dir/build

CMakeFiles/opengl_helloworld.out.dir/requires: CMakeFiles/opengl_helloworld.out.dir/opengl_helloworld.cpp.o.requires

.PHONY : CMakeFiles/opengl_helloworld.out.dir/requires

CMakeFiles/opengl_helloworld.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl_helloworld.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl_helloworld.out.dir/clean

CMakeFiles/opengl_helloworld.out.dir/depend:
	cd /home/choyg/Desktop/workspace/opengl/opengl_helloworld && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/choyg/Desktop/workspace/opengl/opengl_helloworld /home/choyg/Desktop/workspace/opengl/opengl_helloworld /home/choyg/Desktop/workspace/opengl/opengl_helloworld /home/choyg/Desktop/workspace/opengl/opengl_helloworld /home/choyg/Desktop/workspace/opengl/opengl_helloworld/CMakeFiles/opengl_helloworld.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl_helloworld.out.dir/depend

