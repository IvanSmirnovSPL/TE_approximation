# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ivan/TE_approximation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/TE_approximation/build

# Include any dependencies generated for this target.
include utils/CMakeFiles/lib.dir/depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/lib.dir/flags.make

utils/CMakeFiles/lib.dir/make_grid.cpp.o: utils/CMakeFiles/lib.dir/flags.make
utils/CMakeFiles/lib.dir/make_grid.cpp.o: ../utils/make_grid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/TE_approximation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object utils/CMakeFiles/lib.dir/make_grid.cpp.o"
	cd /home/ivan/TE_approximation/build/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/make_grid.cpp.o -c /home/ivan/TE_approximation/utils/make_grid.cpp

utils/CMakeFiles/lib.dir/make_grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/make_grid.cpp.i"
	cd /home/ivan/TE_approximation/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/TE_approximation/utils/make_grid.cpp > CMakeFiles/lib.dir/make_grid.cpp.i

utils/CMakeFiles/lib.dir/make_grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/make_grid.cpp.s"
	cd /home/ivan/TE_approximation/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/TE_approximation/utils/make_grid.cpp -o CMakeFiles/lib.dir/make_grid.cpp.s

utils/CMakeFiles/lib.dir/test_boost.cpp.o: utils/CMakeFiles/lib.dir/flags.make
utils/CMakeFiles/lib.dir/test_boost.cpp.o: ../utils/test_boost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/TE_approximation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object utils/CMakeFiles/lib.dir/test_boost.cpp.o"
	cd /home/ivan/TE_approximation/build/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/test_boost.cpp.o -c /home/ivan/TE_approximation/utils/test_boost.cpp

utils/CMakeFiles/lib.dir/test_boost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/test_boost.cpp.i"
	cd /home/ivan/TE_approximation/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/TE_approximation/utils/test_boost.cpp > CMakeFiles/lib.dir/test_boost.cpp.i

utils/CMakeFiles/lib.dir/test_boost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/test_boost.cpp.s"
	cd /home/ivan/TE_approximation/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/TE_approximation/utils/test_boost.cpp -o CMakeFiles/lib.dir/test_boost.cpp.s

# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/make_grid.cpp.o" \
"CMakeFiles/lib.dir/test_boost.cpp.o"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

utils/liblib.a: utils/CMakeFiles/lib.dir/make_grid.cpp.o
utils/liblib.a: utils/CMakeFiles/lib.dir/test_boost.cpp.o
utils/liblib.a: utils/CMakeFiles/lib.dir/build.make
utils/liblib.a: utils/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/TE_approximation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblib.a"
	cd /home/ivan/TE_approximation/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean_target.cmake
	cd /home/ivan/TE_approximation/build/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/lib.dir/build: utils/liblib.a

.PHONY : utils/CMakeFiles/lib.dir/build

utils/CMakeFiles/lib.dir/clean:
	cd /home/ivan/TE_approximation/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/lib.dir/clean

utils/CMakeFiles/lib.dir/depend:
	cd /home/ivan/TE_approximation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/TE_approximation /home/ivan/TE_approximation/utils /home/ivan/TE_approximation/build /home/ivan/TE_approximation/build/utils /home/ivan/TE_approximation/build/utils/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/lib.dir/depend
