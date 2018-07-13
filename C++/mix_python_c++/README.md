# Break into C++ code from python
   This project show how to call C++ from python, and set breakpoint in
   C++, the program will stop in the the c++ code
## usage:
     There are two ways to build this. <br />
     1. make CFuncEntry.so <br />
     2. make py <br />
     After build, you will get CFuncEntry.so in the root dir.<br >
     You can run python-db call_cpp.py, to run the code.
     Use gdb --args python-dbg call_cpp.py , you can go into debug mode
     and set breakpoints in testlib.cpp code.


