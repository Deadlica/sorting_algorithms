# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/samuel/Downloads/clion-2021.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/samuel/Downloads/clion-2021.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samuel/Documents/c++/DT064G/sorting_algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sorting_algorithms.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/sorting_algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sorting_algorithms.dir/flags.make

CMakeFiles/sorting_algorithms.dir/main.cpp.o: CMakeFiles/sorting_algorithms.dir/flags.make
CMakeFiles/sorting_algorithms.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sorting_algorithms.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sorting_algorithms.dir/main.cpp.o -c /home/samuel/Documents/c++/DT064G/sorting_algorithms/main.cpp

CMakeFiles/sorting_algorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sorting_algorithms.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/Documents/c++/DT064G/sorting_algorithms/main.cpp > CMakeFiles/sorting_algorithms.dir/main.cpp.i

CMakeFiles/sorting_algorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sorting_algorithms.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/Documents/c++/DT064G/sorting_algorithms/main.cpp -o CMakeFiles/sorting_algorithms.dir/main.cpp.s

CMakeFiles/sorting_algorithms.dir/timer.cpp.o: CMakeFiles/sorting_algorithms.dir/flags.make
CMakeFiles/sorting_algorithms.dir/timer.cpp.o: ../timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sorting_algorithms.dir/timer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sorting_algorithms.dir/timer.cpp.o -c /home/samuel/Documents/c++/DT064G/sorting_algorithms/timer.cpp

CMakeFiles/sorting_algorithms.dir/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sorting_algorithms.dir/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/Documents/c++/DT064G/sorting_algorithms/timer.cpp > CMakeFiles/sorting_algorithms.dir/timer.cpp.i

CMakeFiles/sorting_algorithms.dir/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sorting_algorithms.dir/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/Documents/c++/DT064G/sorting_algorithms/timer.cpp -o CMakeFiles/sorting_algorithms.dir/timer.cpp.s

# Object files for target sorting_algorithms
sorting_algorithms_OBJECTS = \
"CMakeFiles/sorting_algorithms.dir/main.cpp.o" \
"CMakeFiles/sorting_algorithms.dir/timer.cpp.o"

# External object files for target sorting_algorithms
sorting_algorithms_EXTERNAL_OBJECTS =

sorting_algorithms: CMakeFiles/sorting_algorithms.dir/main.cpp.o
sorting_algorithms: CMakeFiles/sorting_algorithms.dir/timer.cpp.o
sorting_algorithms: CMakeFiles/sorting_algorithms.dir/build.make
sorting_algorithms: CMakeFiles/sorting_algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sorting_algorithms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sorting_algorithms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sorting_algorithms.dir/build: sorting_algorithms
.PHONY : CMakeFiles/sorting_algorithms.dir/build

CMakeFiles/sorting_algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sorting_algorithms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sorting_algorithms.dir/clean

CMakeFiles/sorting_algorithms.dir/depend:
	cd /home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samuel/Documents/c++/DT064G/sorting_algorithms /home/samuel/Documents/c++/DT064G/sorting_algorithms /home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug /home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug /home/samuel/Documents/c++/DT064G/sorting_algorithms/cmake-build-debug/CMakeFiles/sorting_algorithms.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sorting_algorithms.dir/depend

