# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wang/github/LearnOpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wang/github/LearnOpenGL/build

# Utility rule file for ContinuousUpdate.

# Include the progress variables for this target.
include assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/progress.make

assimp-4.0.1/test/CMakeFiles/ContinuousUpdate:
	cd /home/wang/github/LearnOpenGL/build/assimp-4.0.1/test && /usr/local/bin/ctest -D ContinuousUpdate

ContinuousUpdate: assimp-4.0.1/test/CMakeFiles/ContinuousUpdate
ContinuousUpdate: assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/build.make

.PHONY : ContinuousUpdate

# Rule to build all files generated by this target.
assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/build: ContinuousUpdate

.PHONY : assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/build

assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/clean:
	cd /home/wang/github/LearnOpenGL/build/assimp-4.0.1/test && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousUpdate.dir/cmake_clean.cmake
.PHONY : assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/clean

assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/depend:
	cd /home/wang/github/LearnOpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wang/github/LearnOpenGL /home/wang/github/LearnOpenGL/assimp-4.0.1/test /home/wang/github/LearnOpenGL/build /home/wang/github/LearnOpenGL/build/assimp-4.0.1/test /home/wang/github/LearnOpenGL/build/assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : assimp-4.0.1/test/CMakeFiles/ContinuousUpdate.dir/depend

