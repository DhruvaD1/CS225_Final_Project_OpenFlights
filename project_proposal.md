## Leading Question 

From the dataset we can learn how to find the shortest path between two points, how to detect a cycle in a graph, and how to traverse a graph. We will develop the algorithms such as Dijkstra’s, Eulerian, and BFS to solve these questions. The dataset contains every airport in the world and the locations of each. We will use the dataset to answer how to find the shortest path between two points, how to detect a cycle in a graph, and how to traverse a graph in an airport context. The cycle detection allows us to see if airports return and travel to each other, while the shortest path algorithm allows airports to find the shortest paths between each other. 

## Dataset Acquisition

Our dataset is in the format of .dat and has 14,110 entries. We plan to use all of the data in the dataset, so the subset will be the entire dataset. The format of the dataset are strings and integers that are separated by commas, with the first entry containing the airport, the location of the airport, acronyms for the airport, the latitude and longitude, and the airport that it is flying to. 

## Data Format

To make sure the data and input are error-free, we will make there are no duplicate entries by skipping over values we have already seen. In addition, if a row contains a null value or if the airport does not fly to a certain location, that value will also be skipped. If the value is null, there would be no purpose for processing that input. 

## Data Correction

To make sure the data and input are error-free, we will make there are no duplicate entries by skipping over values we have already seen. In addition, if a row contains a null value or if the airport does not fly to a certain location, that value will also be skipped. If the value is null, there would be no purpose for processing that input. 

## Data Storage

The main data structure we will use to hold the data will be a HashMap. The key of the HashMap will be the airport, and the value will be a vector of airports that the key has direct flights to. The space complexity of the Map O(vertices). We will also need a queue for the BFS. We will need a priority queue to make the heap, which is needed for Djikstra’s shortest path. The space complexity of the priority queue O(vertices) worst case, which is unlikely to ever happen. For the cycle detection we will need a vector which will be space complexity of O(vertices).

## Algorithm 

We will be using a breadth-first-search traversal algorithm, Dijkstra’s Algorithm for the shortest path between two airports, and a cycle identification algorithm to answer our leading questions. 
The shortest path and the cycle identification require one airport as an input, while our BFS traversal requires one airport as well as an adjacency list which we will construct using a map.
The expected output of our BFS algorithm will be the name of each airport visited in order. The expected output of Dijkstra’s Algorithm will be the name of each airport in order within the shortest path. These outputs can be stored into a vector and printed. The expected output of our cycle identification algorithm is a boolean value.
The optimal runtime of our BFS algorithm is O(N). The optimal runtime of Dijkstra’s Algorithm is O(N + E log N). The optimal runtime of our cycle identification is O(N + E). N is equal to the number of airports in the dataset and E is equal to the number of edges/flights in our dataset.


## Timeline


1st: The first week should be dedicated to making sure all group members are able to load in and read the data from the .dat file correctly. We will then make any data corrections needed depending on the input.
	
2nd: The second week, we should implement our search function. Breadth-first-search should try to be finished during this time. (Finished before November 14th)

(Mid-week)

3rd: Our third week should be implementing the shortest path algorithm.

4th: Our fourth week should be implementing the cycle detection algorithm.  

5th: Create the demo of the video. Refine code and Present

Dec 8th - Project is due 
