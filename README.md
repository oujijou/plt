# README
## Execution 
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





