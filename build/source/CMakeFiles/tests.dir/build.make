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
CMAKE_SOURCE_DIR = /home/judith/Dokumente/Uni/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/judith/Dokumente/Uni/final_raytracer/build
=======
CMAKE_SOURCE_DIR = /home/IN/wobi3451/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/IN/wobi3451/final_raytracer/build
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8

# Include any dependencies generated for this target.
include source/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/tests.dir/flags.make

source/CMakeFiles/tests.dir/tests.cpp.o: source/CMakeFiles/tests.dir/flags.make
source/CMakeFiles/tests.dir/tests.cpp.o: ../source/tests.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/tests.dir/tests.cpp.o"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/tests.cpp.o -c /home/judith/Dokumente/Uni/final_raytracer/source/tests.cpp

source/CMakeFiles/tests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests.cpp.i"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judith/Dokumente/Uni/final_raytracer/source/tests.cpp > CMakeFiles/tests.dir/tests.cpp.i

source/CMakeFiles/tests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests.cpp.s"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judith/Dokumente/Uni/final_raytracer/source/tests.cpp -o CMakeFiles/tests.dir/tests.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/tests.dir/tests.cpp.o"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/tests.cpp.o -c /home/IN/wobi3451/final_raytracer/source/tests.cpp

source/CMakeFiles/tests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests.cpp.i"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/IN/wobi3451/final_raytracer/source/tests.cpp > CMakeFiles/tests.dir/tests.cpp.i

source/CMakeFiles/tests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests.cpp.s"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/IN/wobi3451/final_raytracer/source/tests.cpp -o CMakeFiles/tests.dir/tests.cpp.s
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8

source/CMakeFiles/tests.dir/tests.cpp.o.requires:

.PHONY : source/CMakeFiles/tests.dir/tests.cpp.o.requires

source/CMakeFiles/tests.dir/tests.cpp.o.provides: source/CMakeFiles/tests.dir/tests.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/tests.dir/build.make source/CMakeFiles/tests.dir/tests.cpp.o.provides.build
.PHONY : source/CMakeFiles/tests.dir/tests.cpp.o.provides

source/CMakeFiles/tests.dir/tests.cpp.o.provides.build: source/CMakeFiles/tests.dir/tests.cpp.o


source/CMakeFiles/tests.dir/__/framework/box.cpp.o: source/CMakeFiles/tests.dir/flags.make
source/CMakeFiles/tests.dir/__/framework/box.cpp.o: ../framework/box.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/CMakeFiles/tests.dir/__/framework/box.cpp.o"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/box.cpp.o -c /home/judith/Dokumente/Uni/final_raytracer/framework/box.cpp

source/CMakeFiles/tests.dir/__/framework/box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/box.cpp.i"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judith/Dokumente/Uni/final_raytracer/framework/box.cpp > CMakeFiles/tests.dir/__/framework/box.cpp.i

source/CMakeFiles/tests.dir/__/framework/box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/box.cpp.s"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judith/Dokumente/Uni/final_raytracer/framework/box.cpp -o CMakeFiles/tests.dir/__/framework/box.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/CMakeFiles/tests.dir/__/framework/box.cpp.o"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/box.cpp.o -c /home/IN/wobi3451/final_raytracer/framework/box.cpp

source/CMakeFiles/tests.dir/__/framework/box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/box.cpp.i"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/IN/wobi3451/final_raytracer/framework/box.cpp > CMakeFiles/tests.dir/__/framework/box.cpp.i

source/CMakeFiles/tests.dir/__/framework/box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/box.cpp.s"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/IN/wobi3451/final_raytracer/framework/box.cpp -o CMakeFiles/tests.dir/__/framework/box.cpp.s
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8

source/CMakeFiles/tests.dir/__/framework/box.cpp.o.requires:

.PHONY : source/CMakeFiles/tests.dir/__/framework/box.cpp.o.requires

source/CMakeFiles/tests.dir/__/framework/box.cpp.o.provides: source/CMakeFiles/tests.dir/__/framework/box.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/tests.dir/build.make source/CMakeFiles/tests.dir/__/framework/box.cpp.o.provides.build
.PHONY : source/CMakeFiles/tests.dir/__/framework/box.cpp.o.provides

source/CMakeFiles/tests.dir/__/framework/box.cpp.o.provides.build: source/CMakeFiles/tests.dir/__/framework/box.cpp.o


source/CMakeFiles/tests.dir/__/framework/material.cpp.o: source/CMakeFiles/tests.dir/flags.make
source/CMakeFiles/tests.dir/__/framework/material.cpp.o: ../framework/material.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/CMakeFiles/tests.dir/__/framework/material.cpp.o"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/material.cpp.o -c /home/judith/Dokumente/Uni/final_raytracer/framework/material.cpp

source/CMakeFiles/tests.dir/__/framework/material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/material.cpp.i"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judith/Dokumente/Uni/final_raytracer/framework/material.cpp > CMakeFiles/tests.dir/__/framework/material.cpp.i

source/CMakeFiles/tests.dir/__/framework/material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/material.cpp.s"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judith/Dokumente/Uni/final_raytracer/framework/material.cpp -o CMakeFiles/tests.dir/__/framework/material.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/CMakeFiles/tests.dir/__/framework/material.cpp.o"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/material.cpp.o -c /home/IN/wobi3451/final_raytracer/framework/material.cpp

source/CMakeFiles/tests.dir/__/framework/material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/material.cpp.i"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/IN/wobi3451/final_raytracer/framework/material.cpp > CMakeFiles/tests.dir/__/framework/material.cpp.i

source/CMakeFiles/tests.dir/__/framework/material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/material.cpp.s"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/IN/wobi3451/final_raytracer/framework/material.cpp -o CMakeFiles/tests.dir/__/framework/material.cpp.s
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8

source/CMakeFiles/tests.dir/__/framework/material.cpp.o.requires:

.PHONY : source/CMakeFiles/tests.dir/__/framework/material.cpp.o.requires

source/CMakeFiles/tests.dir/__/framework/material.cpp.o.provides: source/CMakeFiles/tests.dir/__/framework/material.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/tests.dir/build.make source/CMakeFiles/tests.dir/__/framework/material.cpp.o.provides.build
.PHONY : source/CMakeFiles/tests.dir/__/framework/material.cpp.o.provides

source/CMakeFiles/tests.dir/__/framework/material.cpp.o.provides.build: source/CMakeFiles/tests.dir/__/framework/material.cpp.o


source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o: source/CMakeFiles/tests.dir/flags.make
source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o: ../framework/sphere.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/sphere.cpp.o -c /home/judith/Dokumente/Uni/final_raytracer/framework/sphere.cpp

source/CMakeFiles/tests.dir/__/framework/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/sphere.cpp.i"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judith/Dokumente/Uni/final_raytracer/framework/sphere.cpp > CMakeFiles/tests.dir/__/framework/sphere.cpp.i

source/CMakeFiles/tests.dir/__/framework/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/sphere.cpp.s"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judith/Dokumente/Uni/final_raytracer/framework/sphere.cpp -o CMakeFiles/tests.dir/__/framework/sphere.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/sphere.cpp.o -c /home/IN/wobi3451/final_raytracer/framework/sphere.cpp

source/CMakeFiles/tests.dir/__/framework/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/sphere.cpp.i"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/IN/wobi3451/final_raytracer/framework/sphere.cpp > CMakeFiles/tests.dir/__/framework/sphere.cpp.i

source/CMakeFiles/tests.dir/__/framework/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/sphere.cpp.s"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/IN/wobi3451/final_raytracer/framework/sphere.cpp -o CMakeFiles/tests.dir/__/framework/sphere.cpp.s
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8

source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.requires:

.PHONY : source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.requires

source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.provides: source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/tests.dir/build.make source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.provides.build
.PHONY : source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.provides

source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.provides.build: source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o


source/CMakeFiles/tests.dir/__/framework/shape.cpp.o: source/CMakeFiles/tests.dir/flags.make
source/CMakeFiles/tests.dir/__/framework/shape.cpp.o: ../framework/shape.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object source/CMakeFiles/tests.dir/__/framework/shape.cpp.o"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/shape.cpp.o -c /home/judith/Dokumente/Uni/final_raytracer/framework/shape.cpp

source/CMakeFiles/tests.dir/__/framework/shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/shape.cpp.i"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judith/Dokumente/Uni/final_raytracer/framework/shape.cpp > CMakeFiles/tests.dir/__/framework/shape.cpp.i

source/CMakeFiles/tests.dir/__/framework/shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/shape.cpp.s"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judith/Dokumente/Uni/final_raytracer/framework/shape.cpp -o CMakeFiles/tests.dir/__/framework/shape.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object source/CMakeFiles/tests.dir/__/framework/shape.cpp.o"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/framework/shape.cpp.o -c /home/IN/wobi3451/final_raytracer/framework/shape.cpp

source/CMakeFiles/tests.dir/__/framework/shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/framework/shape.cpp.i"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/IN/wobi3451/final_raytracer/framework/shape.cpp > CMakeFiles/tests.dir/__/framework/shape.cpp.i

source/CMakeFiles/tests.dir/__/framework/shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/framework/shape.cpp.s"
	cd /home/IN/wobi3451/final_raytracer/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/IN/wobi3451/final_raytracer/framework/shape.cpp -o CMakeFiles/tests.dir/__/framework/shape.cpp.s
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8

source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.requires:

.PHONY : source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.requires

source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.provides: source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/tests.dir/build.make source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.provides.build
.PHONY : source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.provides

source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.provides.build: source/CMakeFiles/tests.dir/__/framework/shape.cpp.o


# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/tests.cpp.o" \
"CMakeFiles/tests.dir/__/framework/box.cpp.o" \
"CMakeFiles/tests.dir/__/framework/material.cpp.o" \
"CMakeFiles/tests.dir/__/framework/sphere.cpp.o" \
"CMakeFiles/tests.dir/__/framework/shape.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

source/tests: source/CMakeFiles/tests.dir/tests.cpp.o
source/tests: source/CMakeFiles/tests.dir/__/framework/box.cpp.o
source/tests: source/CMakeFiles/tests.dir/__/framework/material.cpp.o
source/tests: source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o
source/tests: source/CMakeFiles/tests.dir/__/framework/shape.cpp.o
source/tests: source/CMakeFiles/tests.dir/build.make
source/tests: source/CMakeFiles/tests.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/judith/Dokumente/Uni/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tests"
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tests"
	cd /home/IN/wobi3451/final_raytracer/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8

# Rule to build all files generated by this target.
source/CMakeFiles/tests.dir/build: source/tests

.PHONY : source/CMakeFiles/tests.dir/build

source/CMakeFiles/tests.dir/requires: source/CMakeFiles/tests.dir/tests.cpp.o.requires
source/CMakeFiles/tests.dir/requires: source/CMakeFiles/tests.dir/__/framework/box.cpp.o.requires
source/CMakeFiles/tests.dir/requires: source/CMakeFiles/tests.dir/__/framework/material.cpp.o.requires
source/CMakeFiles/tests.dir/requires: source/CMakeFiles/tests.dir/__/framework/sphere.cpp.o.requires
source/CMakeFiles/tests.dir/requires: source/CMakeFiles/tests.dir/__/framework/shape.cpp.o.requires

.PHONY : source/CMakeFiles/tests.dir/requires

source/CMakeFiles/tests.dir/clean:
<<<<<<< HEAD
	cd /home/judith/Dokumente/Uni/final_raytracer/build/source && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/tests.dir/clean

source/CMakeFiles/tests.dir/depend:
	cd /home/judith/Dokumente/Uni/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/judith/Dokumente/Uni/final_raytracer /home/judith/Dokumente/Uni/final_raytracer/source /home/judith/Dokumente/Uni/final_raytracer/build /home/judith/Dokumente/Uni/final_raytracer/build/source /home/judith/Dokumente/Uni/final_raytracer/build/source/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /home/IN/wobi3451/final_raytracer/build/source && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/tests.dir/clean

source/CMakeFiles/tests.dir/depend:
	cd /home/IN/wobi3451/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/IN/wobi3451/final_raytracer /home/IN/wobi3451/final_raytracer/source /home/IN/wobi3451/final_raytracer/build /home/IN/wobi3451/final_raytracer/build/source /home/IN/wobi3451/final_raytracer/build/source/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> f8e4304dc790ba012a7e0deb36c39b857f1549b8
.PHONY : source/CMakeFiles/tests.dir/depend

