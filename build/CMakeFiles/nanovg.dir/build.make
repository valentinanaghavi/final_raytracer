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
CMAKE_SOURCE_DIR = /home/IN/wobi3451/final_raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/IN/wobi3451/final_raytracer/build

# Include any dependencies generated for this target.
include CMakeFiles/nanovg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nanovg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nanovg.dir/flags.make

CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o: CMakeFiles/nanovg.dir/flags.make
CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o: ../external/nanovg/src/nanovg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wno-unused-result -o CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o   -c /home/IN/wobi3451/final_raytracer/external/nanovg/src/nanovg.c

CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wno-unused-result -E /home/IN/wobi3451/final_raytracer/external/nanovg/src/nanovg.c > CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.i

CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wno-unused-result -S /home/IN/wobi3451/final_raytracer/external/nanovg/src/nanovg.c -o CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.s

CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.requires:

.PHONY : CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.requires

CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.provides: CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.requires
	$(MAKE) -f CMakeFiles/nanovg.dir/build.make CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.provides.build
.PHONY : CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.provides

CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.provides.build: CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o


# Object files for target nanovg
nanovg_OBJECTS = \
"CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o"

# External object files for target nanovg
nanovg_EXTERNAL_OBJECTS =

libnanovg.a: CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o
libnanovg.a: CMakeFiles/nanovg.dir/build.make
libnanovg.a: CMakeFiles/nanovg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/IN/wobi3451/final_raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libnanovg.a"
	$(CMAKE_COMMAND) -P CMakeFiles/nanovg.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nanovg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nanovg.dir/build: libnanovg.a

.PHONY : CMakeFiles/nanovg.dir/build

CMakeFiles/nanovg.dir/requires: CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o.requires

.PHONY : CMakeFiles/nanovg.dir/requires

CMakeFiles/nanovg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nanovg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nanovg.dir/clean

CMakeFiles/nanovg.dir/depend:
	cd /home/IN/wobi3451/final_raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/IN/wobi3451/final_raytracer /home/IN/wobi3451/final_raytracer /home/IN/wobi3451/final_raytracer/build /home/IN/wobi3451/final_raytracer/build /home/IN/wobi3451/final_raytracer/build/CMakeFiles/nanovg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nanovg.dir/depend

