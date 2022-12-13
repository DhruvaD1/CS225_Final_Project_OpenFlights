# CS225 Final Project: OpenFlights

## Introduction
This is our final project for CS225. Our project runs several graph algorithms on the OpenFlights datasets in order to answer our leading questions. These algorithms include a breadth-first-search, finding the shortest path between two airports, and finding the Euler circuit from an airport.

## Group members
Dhruva Dammanna (dhruvad2)\
Alan Zhang (alanyz2)\
Jalen Xing (jalenx2)\
David Lin (davidl16)

## Testing and running our program
Begin by cloning our repository into the CS225 default Docker container with this : <br />
```git clone https://github.com/DhruvaD1/CS225_Final_Project_OpenFlights.git```

Once you are in the CS225_Final_Project_OpenFlights folder, follow the following steps: <br />
```
mkdir build
cd build
cmake ..
```

To compile and run our test cases stay in the build folder and enter the following commands in order to compile and execute respectively: <br />
```
make test
./test
```

To run our main.cpp stay in the build folder and run the following commands in order to compile and execute respectively: <br />
```
g++ -o main .././src/main.cpp
./main
```
Main runs our algorithms on user inputted airports. These can be changed in the `input.txt` file, which is in the CS225_Final_Project_OpenFlights folder, and all data will be output to `output.txt` also located in CS225_Final_Project_OpenFlights. To input data into `input.txt`, type in the 3 digit airport code with all capital letters into the specified lines in `input.txt`. Instructions and information for inputting data are also written in input.txt.


ATTENTION: Running main and tests can take up to several minutes. This is because a few of our testcases check our algorithms against the entire OpenFlights datasets.
