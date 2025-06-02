# CMake generated Testfile for 
# Source directory: /home/csmajs/pchai010/FRAT-NIGHT
# Build directory: /home/csmajs/pchai010/FRAT-NIGHT
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(valgrind_test "bin/Rush_Week")
set_tests_properties(valgrind_test PROPERTIES  _BACKTRACE_TRIPLES "/home/csmajs/pchai010/FRAT-NIGHT/CMakeLists.txt;29;add_test;/home/csmajs/pchai010/FRAT-NIGHT/CMakeLists.txt;0;")
subdirs("lib")
subdirs("test")
