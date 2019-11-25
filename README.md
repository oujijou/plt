# README

# Project Title

One Paragraph of project description goes here

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc

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

## Testing code-coverage
In order to test the code-coverage you may process as following:
1) In the folder "build" execute the command "cmake .." to compile the project
2) command "make" to execute the project
3) Then "make unittest" to execute the unit tests
4) "make code-coverage"
5) To finish execute the command "firefox code-coverage/index.html"
A web page will be open showing the code-coverage based on the functions and the lines of code.

## Displaying a render and a gameplay 
"cmake .." from "build" folder
"make" from the same folder
"./bin/client render" from  "plt" folder to display the render of a state 
"./bin/client engine" from "plt" folder to display a gameplay 







