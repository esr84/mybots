# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/esr/git/mybots/myBots/src/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/esr/git/mybots/myBots/src/test

# Include any dependencies generated for this target.
include CMakeFiles/test_boost.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_boost.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_boost.dir/flags.make

CMakeFiles/test_boost.dir/test_boost.cpp.o: CMakeFiles/test_boost.dir/flags.make
CMakeFiles/test_boost.dir/test_boost.cpp.o: test_boost.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/esr/git/mybots/myBots/src/test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_boost.dir/test_boost.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_boost.dir/test_boost.cpp.o -c /home/esr/git/mybots/myBots/src/test/test_boost.cpp

CMakeFiles/test_boost.dir/test_boost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_boost.dir/test_boost.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/esr/git/mybots/myBots/src/test/test_boost.cpp > CMakeFiles/test_boost.dir/test_boost.cpp.i

CMakeFiles/test_boost.dir/test_boost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_boost.dir/test_boost.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/esr/git/mybots/myBots/src/test/test_boost.cpp -o CMakeFiles/test_boost.dir/test_boost.cpp.s

CMakeFiles/test_boost.dir/test_boost.cpp.o.requires:
.PHONY : CMakeFiles/test_boost.dir/test_boost.cpp.o.requires

CMakeFiles/test_boost.dir/test_boost.cpp.o.provides: CMakeFiles/test_boost.dir/test_boost.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_boost.dir/build.make CMakeFiles/test_boost.dir/test_boost.cpp.o.provides.build
.PHONY : CMakeFiles/test_boost.dir/test_boost.cpp.o.provides

CMakeFiles/test_boost.dir/test_boost.cpp.o.provides.build: CMakeFiles/test_boost.dir/test_boost.cpp.o

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o: CMakeFiles/test_boost.dir/flags.make
CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o: /home/esr/git/mybots/myBots/src/MiniMaxState.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/esr/git/mybots/myBots/src/test/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o -c /home/esr/git/mybots/myBots/src/MiniMaxState.cpp

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/esr/git/mybots/myBots/src/MiniMaxState.cpp > CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.i

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/esr/git/mybots/myBots/src/MiniMaxState.cpp -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.s

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.requires:
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.requires

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.provides: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_boost.dir/build.make CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.provides.build
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.provides

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.provides.build: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o: CMakeFiles/test_boost.dir/flags.make
CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o: /home/esr/git/mybots/myBots/src/bots/bot.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/esr/git/mybots/myBots/src/test/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o -c /home/esr/git/mybots/myBots/src/bots/bot.cpp

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/esr/git/mybots/myBots/src/bots/bot.cpp > CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.i

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/esr/git/mybots/myBots/src/bots/bot.cpp -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.s

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.requires:
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.requires

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.provides: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_boost.dir/build.make CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.provides.build
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.provides

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.provides.build: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o: CMakeFiles/test_boost.dir/flags.make
CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o: /home/esr/git/mybots/myBots/src/bots/bots.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/esr/git/mybots/myBots/src/test/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o -c /home/esr/git/mybots/myBots/src/bots/bots.cpp

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/esr/git/mybots/myBots/src/bots/bots.cpp > CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.i

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/esr/git/mybots/myBots/src/bots/bots.cpp -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.s

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.requires:
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.requires

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.provides: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_boost.dir/build.make CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.provides.build
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.provides

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.provides.build: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o: CMakeFiles/test_boost.dir/flags.make
CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o: /home/esr/git/mybots/myBots/src/BotMiniMax.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/esr/git/mybots/myBots/src/test/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o -c /home/esr/git/mybots/myBots/src/BotMiniMax.cpp

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/esr/git/mybots/myBots/src/BotMiniMax.cpp > CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.i

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/esr/git/mybots/myBots/src/BotMiniMax.cpp -o CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.s

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.requires:
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.requires

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.provides: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_boost.dir/build.make CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.provides.build
.PHONY : CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.provides

CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.provides.build: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o

# Object files for target test_boost
test_boost_OBJECTS = \
"CMakeFiles/test_boost.dir/test_boost.cpp.o" \
"CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o" \
"CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o" \
"CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o" \
"CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o"

# External object files for target test_boost
test_boost_EXTERNAL_OBJECTS =

test_boost: CMakeFiles/test_boost.dir/test_boost.cpp.o
test_boost: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o
test_boost: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o
test_boost: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o
test_boost: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o
test_boost: CMakeFiles/test_boost.dir/build.make
test_boost: /usr/lib64/libboost_filesystem-mt.so
test_boost: /usr/lib64/libboost_system-mt.so
test_boost: /usr/lib64/libboost_unit_test_framework-mt.so
test_boost: CMakeFiles/test_boost.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test_boost"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_boost.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_boost.dir/build: test_boost
.PHONY : CMakeFiles/test_boost.dir/build

CMakeFiles/test_boost.dir/requires: CMakeFiles/test_boost.dir/test_boost.cpp.o.requires
CMakeFiles/test_boost.dir/requires: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/MiniMaxState.cpp.o.requires
CMakeFiles/test_boost.dir/requires: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bot.cpp.o.requires
CMakeFiles/test_boost.dir/requires: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/bots/bots.cpp.o.requires
CMakeFiles/test_boost.dir/requires: CMakeFiles/test_boost.dir/home/esr/git/mybots/myBots/src/BotMiniMax.cpp.o.requires
.PHONY : CMakeFiles/test_boost.dir/requires

CMakeFiles/test_boost.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_boost.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_boost.dir/clean

CMakeFiles/test_boost.dir/depend:
	cd /home/esr/git/mybots/myBots/src/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/esr/git/mybots/myBots/src/test /home/esr/git/mybots/myBots/src/test /home/esr/git/mybots/myBots/src/test /home/esr/git/mybots/myBots/src/test /home/esr/git/mybots/myBots/src/test/CMakeFiles/test_boost.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_boost.dir/depend

