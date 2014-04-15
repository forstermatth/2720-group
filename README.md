2720-group
==========
[![Build Status](https://travis-ci.org/forstermatth/2720-group.png?branch=master)](https://travis-ci.org/forstermatth/2720-group)


__Team Durian__
Members: Matt Forster, Justin Werre, Josh Enns, Huy Nguyen

Build Instructions
  1. If on a UofL lab computer (need the use of `/opt/centos/devtoolset-1.1/root/usr/bin/g++`), do a `git checkout uoflmachine` before using make.
  2. To compile the project, use `make` in the root directory.
  2. The `sched` target builds the production code, while the `tests` target builds the testing
code.
  3. To run the tests, execute `tests`.
  4. To start the program, execute `sched`.
  

The program takes in a .xml filename as input, and can include relative or absolute paths. We have included a test input file, located at testfiles/demo.xml.
The rapidXML library is included within the project and does not need to be installed on the machine compiling.
