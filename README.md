# README

# Ninja Saga

This project tends to make a game close to Ninja Saga xiht simple rules.
## Getting Started

make diretory -> mkdir build
move into folder -> cd build
By making "cmake .." some errors will appear and will indicate the missing librairies
In our case, we used the following commands for packages and librairies:
  - sudo apt-get install libboost-all-dev
  - sudo apt-get install -y libpthread-stubs0-dev libsfml-dev libxml2-dev docker.io
  - sudo apt-get install -y libmicrohttpd-dev
Once all the useful packages and librairies installed,  cmake will no longer 
display errors.
The next step is to execute the executable file named client inside the folder bin.
----> "./client anyword " displays "Bonjour anyword".

## Running the tests

In order to test the code-coverage you may process as following:
1) In the folder "build" execute the command "cmake .." to compile the project
2) command "make" to execute the project
3) Then "make unittest" to execute the unit tests
4) "make code-coverage"
5) To finish execute the command "firefox code-coverage/index.html"
A web page will be open showing the code-coverage based on the functions and the lines of code.

## Displaying a render and a gameplay 
* "cmake .." from "build" folder
* "make" from the same folder
* "./bin/client render" from  "plt" folder to display the render of a state 
* "./bin/client engine" from "plt" folder to display a gameplay 

## Authors
* **Moïse BEUGRE** 
* **Ouajih DADAOUA** 

