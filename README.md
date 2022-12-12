# CS225_Final_Project_OpenFlights

## About
This is a project for UIUC CS225 Data Structures class. 
The project uses the Open Flights data set to run several graph algorithms on it to find out things like the BFS, cycles, and shortest path between airports.


## Group Members
Dhruva Dammanna (dhruvad2)\
Alan Zhang (alanyz2)

## How to run
To run the code run make main in the termainal and do ./main to run

To run the test cases make test in the terminal and then do ./test to run the tests

## The Data

There were two datasetst both from the Open Flights Data Set. One that had airports that flew to eachother and one that had information about individual airports like
the location of it

The data was processed by using functions from mp_scheduele file_to_string and splitString. We also created two functions to parse the data from the two datasets 
parseData and parseRoutes. Both of these fucntions used the two functions from mp_scheduele. 

Lastly in the data there were some places like helicopter landing sites that airplanes can not land in so those had to be removed from the data.

## BFS

The BFS created ran BFS search from a chosen starting point and returned a vector of every airport in order visted. Also the function printed out how many kilometers apart the two airports at the start and the end were. BFS runs in O(m+n) runtime and O(V) space.

## Dijkstra 

Dijkstra algorithm was made and used to find the shortest path in a weighted graph. It is especiall useful in this because it will give the fastest route from one airport to another. It runs in O(V log V) runtime and O(V) space.

## Eulers

