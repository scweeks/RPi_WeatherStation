# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build

# Include any dependencies generated for this target.
include CMakeFiles/WeatherStation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WeatherStation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WeatherStation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WeatherStation.dir/flags.make

CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o: CMakeFiles/WeatherStation.dir/flags.make
CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o: /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/WeatherStation.cpp
CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o: CMakeFiles/WeatherStation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o -MF CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o.d -o CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o -c /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/WeatherStation.cpp

CMakeFiles/WeatherStation.dir/WeatherStation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeatherStation.dir/WeatherStation.cpp.i"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/WeatherStation.cpp > CMakeFiles/WeatherStation.dir/WeatherStation.cpp.i

CMakeFiles/WeatherStation.dir/WeatherStation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeatherStation.dir/WeatherStation.cpp.s"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/WeatherStation.cpp -o CMakeFiles/WeatherStation.dir/WeatherStation.cpp.s

CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o: CMakeFiles/WeatherStation.dir/flags.make
CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o: /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Concrete/WeatherData.cpp
CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o: CMakeFiles/WeatherStation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o -MF CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o.d -o CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o -c /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Concrete/WeatherData.cpp

CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.i"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Concrete/WeatherData.cpp > CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.i

CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.s"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Concrete/WeatherData.cpp -o CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.s

CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o: CMakeFiles/WeatherStation.dir/flags.make
CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o: /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Managers/SensorManager.cpp
CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o: CMakeFiles/WeatherStation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o -MF CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o.d -o CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o -c /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Managers/SensorManager.cpp

CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.i"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Managers/SensorManager.cpp > CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.i

CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.s"
	/root/tools-master/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/Managers/SensorManager.cpp -o CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.s

# Object files for target WeatherStation
WeatherStation_OBJECTS = \
"CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o" \
"CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o" \
"CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o"

# External object files for target WeatherStation
WeatherStation_EXTERNAL_OBJECTS =

WeatherStation: CMakeFiles/WeatherStation.dir/WeatherStation.cpp.o
WeatherStation: CMakeFiles/WeatherStation.dir/Concrete/WeatherData.cpp.o
WeatherStation: CMakeFiles/WeatherStation.dir/Managers/SensorManager.cpp.o
WeatherStation: CMakeFiles/WeatherStation.dir/build.make
WeatherStation: CMakeFiles/WeatherStation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable WeatherStation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WeatherStation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WeatherStation.dir/build: WeatherStation
.PHONY : CMakeFiles/WeatherStation.dir/build

CMakeFiles/WeatherStation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WeatherStation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WeatherStation.dir/clean

CMakeFiles/WeatherStation.dir/depend:
	cd /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build /mnt/e/DevRepos/SWENG452w/WeatherStation/RPi_WeatherStation/build/CMakeFiles/WeatherStation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WeatherStation.dir/depend

