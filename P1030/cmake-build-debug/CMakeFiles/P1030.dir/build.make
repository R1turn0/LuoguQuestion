# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/r1turn0/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/r1turn0/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/r1turn0/WorkSpace/C++/P1030

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/r1turn0/WorkSpace/C++/P1030/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P1030.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P1030.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P1030.dir/flags.make

CMakeFiles/P1030.dir/main.cpp.o: CMakeFiles/P1030.dir/flags.make
CMakeFiles/P1030.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/r1turn0/WorkSpace/C++/P1030/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P1030.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P1030.dir/main.cpp.o -c /home/r1turn0/WorkSpace/C++/P1030/main.cpp

CMakeFiles/P1030.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P1030.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/r1turn0/WorkSpace/C++/P1030/main.cpp > CMakeFiles/P1030.dir/main.cpp.i

CMakeFiles/P1030.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P1030.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/r1turn0/WorkSpace/C++/P1030/main.cpp -o CMakeFiles/P1030.dir/main.cpp.s

# Object files for target P1030
P1030_OBJECTS = \
"CMakeFiles/P1030.dir/main.cpp.o"

# External object files for target P1030
P1030_EXTERNAL_OBJECTS =

P1030: CMakeFiles/P1030.dir/main.cpp.o
P1030: CMakeFiles/P1030.dir/build.make
P1030: CMakeFiles/P1030.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/r1turn0/WorkSpace/C++/P1030/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P1030"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P1030.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P1030.dir/build: P1030

.PHONY : CMakeFiles/P1030.dir/build

CMakeFiles/P1030.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P1030.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P1030.dir/clean

CMakeFiles/P1030.dir/depend:
	cd /home/r1turn0/WorkSpace/C++/P1030/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/r1turn0/WorkSpace/C++/P1030 /home/r1turn0/WorkSpace/C++/P1030 /home/r1turn0/WorkSpace/C++/P1030/cmake-build-debug /home/r1turn0/WorkSpace/C++/P1030/cmake-build-debug /home/r1turn0/WorkSpace/C++/P1030/cmake-build-debug/CMakeFiles/P1030.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P1030.dir/depend

