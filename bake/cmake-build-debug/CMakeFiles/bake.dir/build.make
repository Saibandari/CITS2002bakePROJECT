# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\yasom\CLionProjects\bake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yasom\CLionProjects\bake\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bake.dir/flags.make

CMakeFiles/bake.dir/main.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bake.dir/main.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\main.c.obj   -c C:\Users\yasom\CLionProjects\bake\main.c

CMakeFiles/bake.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/main.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\main.c > CMakeFiles\bake.dir\main.c.i

CMakeFiles/bake.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/main.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\main.c -o CMakeFiles\bake.dir\main.c.s

CMakeFiles/bake.dir/open_bakefile.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/open_bakefile.c.obj: ../open_bakefile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bake.dir/open_bakefile.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\open_bakefile.c.obj   -c C:\Users\yasom\CLionProjects\bake\open_bakefile.c

CMakeFiles/bake.dir/open_bakefile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/open_bakefile.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\open_bakefile.c > CMakeFiles\bake.dir\open_bakefile.c.i

CMakeFiles/bake.dir/open_bakefile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/open_bakefile.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\open_bakefile.c -o CMakeFiles\bake.dir\open_bakefile.c.s

CMakeFiles/bake.dir/comment_check.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/comment_check.c.obj: ../comment_check.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/bake.dir/comment_check.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\comment_check.c.obj   -c C:\Users\yasom\CLionProjects\bake\comment_check.c

CMakeFiles/bake.dir/comment_check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/comment_check.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\comment_check.c > CMakeFiles\bake.dir\comment_check.c.i

CMakeFiles/bake.dir/comment_check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/comment_check.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\comment_check.c -o CMakeFiles\bake.dir\comment_check.c.s

CMakeFiles/bake.dir/read_file_into_buf.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/read_file_into_buf.c.obj: ../read_file_into_buf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/bake.dir/read_file_into_buf.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\read_file_into_buf.c.obj   -c C:\Users\yasom\CLionProjects\bake\read_file_into_buf.c

CMakeFiles/bake.dir/read_file_into_buf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/read_file_into_buf.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\read_file_into_buf.c > CMakeFiles\bake.dir\read_file_into_buf.c.i

CMakeFiles/bake.dir/read_file_into_buf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/read_file_into_buf.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\read_file_into_buf.c -o CMakeFiles\bake.dir\read_file_into_buf.c.s

CMakeFiles/bake.dir/find_replace_text.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/find_replace_text.c.obj: ../find_replace_text.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/bake.dir/find_replace_text.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\find_replace_text.c.obj   -c C:\Users\yasom\CLionProjects\bake\find_replace_text.c

CMakeFiles/bake.dir/find_replace_text.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/find_replace_text.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\find_replace_text.c > CMakeFiles\bake.dir\find_replace_text.c.i

CMakeFiles/bake.dir/find_replace_text.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/find_replace_text.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\find_replace_text.c -o CMakeFiles\bake.dir\find_replace_text.c.s

CMakeFiles/bake.dir/variable_definition.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/variable_definition.c.obj: ../variable_definition.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/bake.dir/variable_definition.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\variable_definition.c.obj   -c C:\Users\yasom\CLionProjects\bake\variable_definition.c

CMakeFiles/bake.dir/variable_definition.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/variable_definition.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\variable_definition.c > CMakeFiles\bake.dir\variable_definition.c.i

CMakeFiles/bake.dir/variable_definition.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/variable_definition.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\variable_definition.c -o CMakeFiles\bake.dir\variable_definition.c.s

CMakeFiles/bake.dir/readcontinuationlines.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/readcontinuationlines.c.obj: ../readcontinuationlines.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/bake.dir/readcontinuationlines.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\readcontinuationlines.c.obj   -c C:\Users\yasom\CLionProjects\bake\readcontinuationlines.c

CMakeFiles/bake.dir/readcontinuationlines.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/readcontinuationlines.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\readcontinuationlines.c > CMakeFiles\bake.dir\readcontinuationlines.c.i

CMakeFiles/bake.dir/readcontinuationlines.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/readcontinuationlines.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\readcontinuationlines.c -o CMakeFiles\bake.dir\readcontinuationlines.c.s

CMakeFiles/bake.dir/trimline.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/trimline.c.obj: ../trimline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/bake.dir/trimline.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\trimline.c.obj   -c C:\Users\yasom\CLionProjects\bake\trimline.c

CMakeFiles/bake.dir/trimline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/trimline.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\trimline.c > CMakeFiles\bake.dir\trimline.c.i

CMakeFiles/bake.dir/trimline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/trimline.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\trimline.c -o CMakeFiles\bake.dir\trimline.c.s

CMakeFiles/bake.dir/nextline.c.obj: CMakeFiles/bake.dir/flags.make
CMakeFiles/bake.dir/nextline.c.obj: ../nextline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/bake.dir/nextline.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bake.dir\nextline.c.obj   -c C:\Users\yasom\CLionProjects\bake\nextline.c

CMakeFiles/bake.dir/nextline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bake.dir/nextline.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yasom\CLionProjects\bake\nextline.c > CMakeFiles\bake.dir\nextline.c.i

CMakeFiles/bake.dir/nextline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bake.dir/nextline.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yasom\CLionProjects\bake\nextline.c -o CMakeFiles\bake.dir\nextline.c.s

# Object files for target bake
bake_OBJECTS = \
"CMakeFiles/bake.dir/main.c.obj" \
"CMakeFiles/bake.dir/open_bakefile.c.obj" \
"CMakeFiles/bake.dir/comment_check.c.obj" \
"CMakeFiles/bake.dir/read_file_into_buf.c.obj" \
"CMakeFiles/bake.dir/find_replace_text.c.obj" \
"CMakeFiles/bake.dir/variable_definition.c.obj" \
"CMakeFiles/bake.dir/readcontinuationlines.c.obj" \
"CMakeFiles/bake.dir/trimline.c.obj" \
"CMakeFiles/bake.dir/nextline.c.obj"

# External object files for target bake
bake_EXTERNAL_OBJECTS =

bake.exe: CMakeFiles/bake.dir/main.c.obj
bake.exe: CMakeFiles/bake.dir/open_bakefile.c.obj
bake.exe: CMakeFiles/bake.dir/comment_check.c.obj
bake.exe: CMakeFiles/bake.dir/read_file_into_buf.c.obj
bake.exe: CMakeFiles/bake.dir/find_replace_text.c.obj
bake.exe: CMakeFiles/bake.dir/variable_definition.c.obj
bake.exe: CMakeFiles/bake.dir/readcontinuationlines.c.obj
bake.exe: CMakeFiles/bake.dir/trimline.c.obj
bake.exe: CMakeFiles/bake.dir/nextline.c.obj
bake.exe: CMakeFiles/bake.dir/build.make
bake.exe: CMakeFiles/bake.dir/linklibs.rsp
bake.exe: CMakeFiles/bake.dir/objects1.rsp
bake.exe: CMakeFiles/bake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable bake.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bake.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bake.dir/build: bake.exe

.PHONY : CMakeFiles/bake.dir/build

CMakeFiles/bake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bake.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bake.dir/clean

CMakeFiles/bake.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yasom\CLionProjects\bake C:\Users\yasom\CLionProjects\bake C:\Users\yasom\CLionProjects\bake\cmake-build-debug C:\Users\yasom\CLionProjects\bake\cmake-build-debug C:\Users\yasom\CLionProjects\bake\cmake-build-debug\CMakeFiles\bake.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bake.dir/depend

