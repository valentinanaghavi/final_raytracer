# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/judith/Dokumente/Uni/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/judith/Dokumente/Uni/final_raytracer/build
=======
CMAKE_SOURCE_DIR = /home/valentina/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valentina/final_raytracer/build
>>>>>>> b3f05f70ab594639923f6260e031785a9c2aa3d1

# Include any dependencies generated for this target.
include source/CMakeFiles/raytracer.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/raytracer.dir/flags.make

source/CMakeFiles/raytracer.dir/raytracer.cpp.o: source/CMakeFiles/raytracer.dir/flags.make
source/CMakeFiles/raytracer.dir/raytracer.cpp.o: ../source/raytracer.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/raytracer.dir/raytracer.cpp.o"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/raytracer.cpp.o -c /home/judith/Dokumente/Uni/final_raytracer/source/raytracer.cpp

source/CMakeFiles/raytracer.dir/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/raytracer.cpp.i"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judith/Dokumente/Uni/final_raytracer/source/raytracer.cpp > CMakeFiles/raytracer.dir/raytracer.cpp.i

source/CMakeFiles/raytracer.dir/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/raytracer.cpp.s"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judith/Dokumente/Uni/final_raytracer/source/raytracer.cpp -o CMakeFiles/raytracer.dir/raytracer.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentina/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/raytracer.dir/raytracer.cpp.o"
	cd /home/valentina/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/raytracer.cpp.o -c /home/valentina/final_raytracer/source/raytracer.cpp

source/CMakeFiles/raytracer.dir/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/raytracer.cpp.i"
	cd /home/valentina/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valentina/final_raytracer/source/raytracer.cpp > CMakeFiles/raytracer.dir/raytracer.cpp.i

source/CMakeFiles/raytracer.dir/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/raytracer.cpp.s"
	cd /home/valentina/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valentina/final_raytracer/source/raytracer.cpp -o CMakeFiles/raytracer.dir/raytracer.cpp.s
>>>>>>> b3f05f70ab594639923f6260e031785a9c2aa3d1

source/CMakeFiles/raytracer.dir/raytracer.cpp.o.requires:

.PHONY : source/CMakeFiles/raytracer.dir/raytracer.cpp.o.requires

source/CMakeFiles/raytracer.dir/raytracer.cpp.o.provides: source/CMakeFiles/raytracer.dir/raytracer.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/raytracer.dir/build.make source/CMakeFiles/raytracer.dir/raytracer.cpp.o.provides.build
.PHONY : source/CMakeFiles/raytracer.dir/raytracer.cpp.o.provides

source/CMakeFiles/raytracer.dir/raytracer.cpp.o.provides.build: source/CMakeFiles/raytracer.dir/raytracer.cpp.o


# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/raytracer.cpp.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

source/raytracer: source/CMakeFiles/raytracer.dir/raytracer.cpp.o
source/raytracer: source/CMakeFiles/raytracer.dir/build.make
source/raytracer: framework/libframework.a
source/raytracer: external/glfw-3.2.1/src/libglfw3.a
source/raytracer: external/glfw-3.2.1/src/libglfw3.a
<<<<<<< HEAD
source/raytracer: /usr/lib/x86_64-linux-gnu/libGL.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libGLU.so
=======
source/raytracer: /usr/lib/x86_64-linux-gnu/libGLU.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libGL.so
>>>>>>> b3f05f70ab594639923f6260e031785a9c2aa3d1
source/raytracer: /usr/lib/x86_64-linux-gnu/librt.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libm.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libX11.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libXrandr.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libXinerama.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
source/raytracer: /usr/lib/x86_64-linux-gnu/libXcursor.so
source/raytracer: source/CMakeFiles/raytracer.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raytracer"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valentina/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raytracer"
	cd /home/valentina/final_raytracer/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)
>>>>>>> b3f05f70ab594639923f6260e031785a9c2aa3d1

# Rule to build all files generated by this target.
source/CMakeFiles/raytracer.dir/build: source/raytracer

.PHONY : source/CMakeFiles/raytracer.dir/build

source/CMakeFiles/raytracer.dir/requires: source/CMakeFiles/raytracer.dir/raytracer.cpp.o.requires

.PHONY : source/CMakeFiles/raytracer.dir/requires

source/CMakeFiles/raytracer.dir/clean:
<<<<<<< HEAD
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && $(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/raytracer.dir/clean

source/CMakeFiles/raytracer.dir/depend:
	cd /home/judith/Dokumente/Uni/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/judith/Dokumente/Uni/final_raytracer /home/judith/Dokumente/Uni/final_raytracer/source /home/judith/Dokumente/Uni/final_raytracer/build /home/judith/Dokumente/Uni/final_raytracer/build/source /home/judith/Dokumente/Uni/final_raytracer/build/source/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /home/valentina/final_raytracer/build/source && $(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/raytracer.dir/clean

source/CMakeFiles/raytracer.dir/depend:
	cd /home/valentina/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valentina/final_raytracer /home/valentina/final_raytracer/source /home/valentina/final_raytracer/build /home/valentina/final_raytracer/build/source /home/valentina/final_raytracer/build/source/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> b3f05f70ab594639923f6260e031785a9c2aa3d1
.PHONY : source/CMakeFiles/raytracer.dir/depend

