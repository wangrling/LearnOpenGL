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

# Include any dependencies generated for this target.
include 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/depend.make

# Include the progress variables for this target.
include 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/progress.make

# Include the compile flags for this target's objects.
include 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/flags.make

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/flags.make
03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o: ../03ModelLoading/22nanosuit_loading.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wang/github/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o -c /home/wang/github/LearnOpenGL/03ModelLoading/22nanosuit_loading.cpp

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.i"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wang/github/LearnOpenGL/03ModelLoading/22nanosuit_loading.cpp > CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.i

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.s"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wang/github/LearnOpenGL/03ModelLoading/22nanosuit_loading.cpp -o CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.s

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.requires:

.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.requires

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.provides: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.requires
	$(MAKE) -f 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/build.make 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.provides.build
.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.provides

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.provides.build: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o


03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/flags.make
03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o: ../stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wang/github/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o -c /home/wang/github/LearnOpenGL/stb_image.cpp

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.i"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wang/github/LearnOpenGL/stb_image.cpp > CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.i

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.s"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wang/github/LearnOpenGL/stb_image.cpp -o CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.s

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.requires:

.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.requires

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.provides: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.requires
	$(MAKE) -f 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/build.make 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.provides.build
.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.provides

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.provides.build: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o


03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/flags.make
03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o: ../glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wang/github/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o   -c /home/wang/github/LearnOpenGL/glad/src/glad.c

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.i"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wang/github/LearnOpenGL/glad/src/glad.c > CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.i

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.s"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wang/github/LearnOpenGL/glad/src/glad.c -o CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.s

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.requires:

.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.requires

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.provides: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.requires
	$(MAKE) -f 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/build.make 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.provides.build
.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.provides

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.provides.build: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o


# Object files for target 22nanosuit_loading
22nanosuit_loading_OBJECTS = \
"CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o" \
"CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o" \
"CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o"

# External object files for target 22nanosuit_loading
22nanosuit_loading_EXTERNAL_OBJECTS =

03ModelLoading/22nanosuit_loading: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o
03ModelLoading/22nanosuit_loading: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o
03ModelLoading/22nanosuit_loading: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o
03ModelLoading/22nanosuit_loading: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/build.make
03ModelLoading/22nanosuit_loading: /usr/lib/x86_64-linux-gnu/libGLU.so
03ModelLoading/22nanosuit_loading: /usr/local/lib/libGL.so
03ModelLoading/22nanosuit_loading: /usr/local/lib/libglfw.so.3.3
03ModelLoading/22nanosuit_loading: assimp-4.0.1/code/libassimp.so.4.0.1
03ModelLoading/22nanosuit_loading: /usr/lib/x86_64-linux-gnu/libz.so
03ModelLoading/22nanosuit_loading: assimp-4.0.1/contrib/irrXML/libIrrXML.a
03ModelLoading/22nanosuit_loading: /usr/lib/x86_64-linux-gnu/librt.so
03ModelLoading/22nanosuit_loading: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wang/github/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable 22nanosuit_loading"
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/22nanosuit_loading.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
03ModelLoading/CMakeFiles/22nanosuit_loading.dir/build: 03ModelLoading/22nanosuit_loading

.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/build

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/requires: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/22nanosuit_loading.cpp.o.requires
03ModelLoading/CMakeFiles/22nanosuit_loading.dir/requires: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/stb_image.cpp.o.requires
03ModelLoading/CMakeFiles/22nanosuit_loading.dir/requires: 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/__/glad/src/glad.c.o.requires

.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/requires

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/clean:
	cd /home/wang/github/LearnOpenGL/build/03ModelLoading && $(CMAKE_COMMAND) -P CMakeFiles/22nanosuit_loading.dir/cmake_clean.cmake
.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/clean

03ModelLoading/CMakeFiles/22nanosuit_loading.dir/depend:
	cd /home/wang/github/LearnOpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wang/github/LearnOpenGL /home/wang/github/LearnOpenGL/03ModelLoading /home/wang/github/LearnOpenGL/build /home/wang/github/LearnOpenGL/build/03ModelLoading /home/wang/github/LearnOpenGL/build/03ModelLoading/CMakeFiles/22nanosuit_loading.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 03ModelLoading/CMakeFiles/22nanosuit_loading.dir/depend

