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
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /home/IN/wobi3451/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/IN/wobi3451/final_raytracer/build
=======
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /home/judith/Dokumente/Uni/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/judith/Dokumente/Uni/final_raytracer/build
=======
CMAKE_SOURCE_DIR = /home/valentina/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valentina/final_raytracer/build
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790

# Include any dependencies generated for this target.
include source/CMakeFiles/example.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/example.dir/flags.make

source/CMakeFiles/example.dir/example.cpp.o: source/CMakeFiles/example.dir/flags.make
source/CMakeFiles/example.dir/example.cpp.o: ../source/example.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/example.dir/example.cpp.o"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/example.cpp.o -c /home/IN/wobi3451/final_raytracer/source/example.cpp
=======
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/example.dir/example.cpp.o"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/example.cpp.o -c /home/judith/Dokumente/Uni/final_raytracer/source/example.cpp

source/CMakeFiles/example.dir/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/example.cpp.i"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judith/Dokumente/Uni/final_raytracer/source/example.cpp > CMakeFiles/example.dir/example.cpp.i

source/CMakeFiles/example.dir/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/example.cpp.s"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judith/Dokumente/Uni/final_raytracer/source/example.cpp -o CMakeFiles/example.dir/example.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentina/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/example.dir/example.cpp.o"
	cd /home/valentina/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/example.cpp.o -c /home/valentina/final_raytracer/source/example.cpp
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790

source/CMakeFiles/example.dir/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/example.cpp.i"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/IN/wobi3451/final_raytracer/source/example.cpp > CMakeFiles/example.dir/example.cpp.i

source/CMakeFiles/example.dir/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/example.cpp.s"
<<<<<<< HEAD
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/IN/wobi3451/final_raytracer/source/example.cpp -o CMakeFiles/example.dir/example.cpp.s
=======
	cd /home/valentina/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valentina/final_raytracer/source/example.cpp -o CMakeFiles/example.dir/example.cpp.s
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790

source/CMakeFiles/example.dir/example.cpp.o.requires:

.PHONY : source/CMakeFiles/example.dir/example.cpp.o.requires

source/CMakeFiles/example.dir/example.cpp.o.provides: source/CMakeFiles/example.dir/example.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/example.dir/build.make source/CMakeFiles/example.dir/example.cpp.o.provides.build
.PHONY : source/CMakeFiles/example.dir/example.cpp.o.provides

source/CMakeFiles/example.dir/example.cpp.o.provides.build: source/CMakeFiles/example.dir/example.cpp.o


# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/example.cpp.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

source/example: source/CMakeFiles/example.dir/example.cpp.o
source/example: source/CMakeFiles/example.dir/build.make
source/example: framework/libframework.a
source/example: external/glfw-3.2.1/src/libglfw3.a
<<<<<<< HEAD
source/example: /usr/lib/libGL.so
source/example: /usr/lib/libGLU.so
source/example: /usr/lib/librt.so
source/example: /usr/lib/libm.so
source/example: /usr/lib/libX11.so
source/example: /usr/lib/libXrandr.so
source/example: /usr/lib/libXinerama.so
source/example: /usr/lib/libXxf86vm.so
source/example: /usr/lib/libXcursor.so
source/example: source/CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example"
	cd /home/IN/wobi3451/final_raytracer/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)
=======
<<<<<<< HEAD
source/example: /usr/lib/x86_64-linux-gnu/libGL.so
source/example: /usr/lib/x86_64-linux-gnu/libGLU.so
=======
source/example: /usr/lib/x86_64-linux-gnu/libGLU.so
source/example: /usr/lib/x86_64-linux-gnu/libGL.so
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
source/example: /usr/lib/x86_64-linux-gnu/librt.so
source/example: /usr/lib/x86_64-linux-gnu/libm.so
source/example: /usr/lib/x86_64-linux-gnu/libX11.so
source/example: /usr/lib/x86_64-linux-gnu/libXrandr.so
source/example: /usr/lib/x86_64-linux-gnu/libXinerama.so
source/example: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
source/example: /usr/lib/x86_64-linux-gnu/libXcursor.so
source/example: source/CMakeFiles/example.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valentina/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example"
	cd /home/valentina/final_raytracer/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790

# Rule to build all files generated by this target.
source/CMakeFiles/example.dir/build: source/example

.PHONY : source/CMakeFiles/example.dir/build

source/CMakeFiles/example.dir/requires: source/CMakeFiles/example.dir/example.cpp.o.requires

.PHONY : source/CMakeFiles/example.dir/requires

source/CMakeFiles/example.dir/clean:
<<<<<<< HEAD
	cd /home/IN/wobi3451/final_raytracer/build/source && $(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/example.dir/clean

source/CMakeFiles/example.dir/depend:
	cd /home/IN/wobi3451/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/IN/wobi3451/final_raytracer /home/IN/wobi3451/final_raytracer/source /home/IN/wobi3451/final_raytracer/build /home/IN/wobi3451/final_raytracer/build/source /home/IN/wobi3451/final_raytracer/build/source/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
=======
<<<<<<< HEAD
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && $(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/example.dir/clean

source/CMakeFiles/example.dir/depend:
	cd /home/judith/Dokumente/Uni/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/judith/Dokumente/Uni/final_raytracer /home/judith/Dokumente/Uni/final_raytracer/source /home/judith/Dokumente/Uni/final_raytracer/build /home/judith/Dokumente/Uni/final_raytracer/build/source /home/judith/Dokumente/Uni/final_raytracer/build/source/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /home/valentina/final_raytracer/build/source && $(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/example.dir/clean

source/CMakeFiles/example.dir/depend:
	cd /home/valentina/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valentina/final_raytracer /home/valentina/final_raytracer/source /home/valentina/final_raytracer/build /home/valentina/final_raytracer/build/source /home/valentina/final_raytracer/build/source/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790
.PHONY : source/CMakeFiles/example.dir/depend

