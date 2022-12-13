# CS225 Final Project: OpenFlights

## Introduction
This is our final project for CS225. Our project runs several graph algorithms on the OpenFlights datasets in order to answer our leading questions. These algorithms include a breadth-first-search, finding the shortest path between two airports, and finding the Euler circuit from an airport. Link to the data set https://openflights.org/data.html

## Group members
Dhruva Dammanna (dhruvad2)\
Alan Zhang (alanyz2)\
Jalen Xing (jalenx2)\
David Lin (davidl16)

## Files and algorithms
We organized our important files into two main folders, src and tests. See the comments in individual files for more details.

`src/parseInput.cpp`: Implementation of dataset parsing. Creates an adjacency list representation of airports using the `routes` dataset and a map of each airport to their latitude/longitude coordinates using the `data` dataset.

`src/utils.cpp`: Parsing helper functions.

`src/bfs.cpp`: Implementation of BFS traversal, DFS traversal, and finding a Euler path. The BFS algorithm returns a vector of airport codes in the order they were traversed to. The Euler's path algorithm utilizes this BFS path to determine if a Euler circuit exists. If it does, DFS is used to find the exact path, which is also returned as a vector of airport codes.

`src/WeightedGraph.cpp`: Implementation of Dijksta's Algorithm to find the shortest path between two nodes. A weighted graph is first constructed using the adjacency list and data map created using functions from `parseInput.cpp`. This weighted graph is represented using a nested map structure, where weights are the distance calculated between two airports in kilometers. Dijkstra's Algorithm uses this weighted graph to find the shortest path of airports to get from A to B, and returns this path as a vector of airport codes.

`tests/basic.cpp`: Catch2 test cases ensuring our program runs correctly. Our test cases range in size of datasets and ensure edge cases are handled appropriately.

`main.cpp` : main is in the default CS225_Final_Project_OpenFlights folder, and it is used to run our algorithms with input from the user. The input for main comes from input.txt. 

`input.txt` : this is where the user can enter data to test out our algorithms and it is located in the default CS225_Final_Project_OpenFlights folder

`output.txt` : this summarizes the results of what our algorithms produce based off the user's input after main is called

`src/data.txt` : this is the data set that contains the lat and long of all the airports 

`src/routes.txt` : this is the data set that contains all the routes that are flown to from each airport

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
g++ -o main ../main.cpp
./main
```
Main runs our algorithms on user inputted airports. These can be changed in the `input.txt` file, which is in the CS225_Final_Project_OpenFlights folder, and all data will be output to `output.txt` also located in CS225_Final_Project_OpenFlights. To input data into `input.txt`, type in the 3 digit airport code with all capital letters into the specified lines in `input.txt`. Instructions and information for inputting data are also written in input.txt.


ATTENTION: Running main and tests can take up to several minutes. This is because main and a few of our testcases run our algorithms on the entire OpenFlights datasets.
