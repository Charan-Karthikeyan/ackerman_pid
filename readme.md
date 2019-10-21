# PID Controller for Ackermann Steering
[![Build Status](https://travis-ci.org/Charan-Karthikeyan/ackerman_pid.svg?branch=iteration_1_design)](https://travis-ci.org/Charan-Karthikeyan/ackerman_pid)
[![Coverage Status](https://coveralls.io/repos/github/Charan-Karthikeyan/ackerman_pid/badge.svg?branch=iteration_2_implementation)](https://coveralls.io/github/Charan-Karthikeyan/ackerman_pid?branch=iteration_2_implementation)
---

## Overview

A PID based controller for an ackermann steering system. A simulation of the ackermann model is also included to test the controller.

## Agile Iterative Process

[Agile Iterative Process google sheets document](https://docs.google.com/spreadsheets/d/1OC-UdeI0B-3x7UZrUb_SEa5TkO0w30IA12mvkQLu_Fg/edit#gid=0)

## Install UMLet

[Download UMlet files](https://www.umlet.com/download/umlet_14_3/umlet-standalone-14.3.0.zip)
```
Download file from link
unzip umlet-standalone-14.3.0.zip
cd Umlet
Run program: java -jar umlet.jar 
```

## Standard install via command-line

```
git clone --recursive https://github.com/ashwinvk94/ackermann_pid
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```
## Cpplint check
```
cd  <path to repository>
cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```

## Cppcheck check
```
cd <path to repository>
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```

## Doxygen File generation
```
sudo apt-get install doxygen
doxygen -g
Open Doxygen file and source file in "INPUT" prameter and add the include and app folder
Add "*.hpp *.cpp" in the "FILE_PATTERNS" parameter in the doxygen file
Run "doxygen ./Doxyfile" in te terminal
Open html folder
open index.html
 ```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.


