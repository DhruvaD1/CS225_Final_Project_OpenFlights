# CS225_Final_Project_OpenFlights

## The output and correctness of each algorithm

### BFS

Our Breadth First Search Algorithm searches all the airports you can travel to based on the airport you start off with. The method was successful due to running extensive tests on the BFS algorithm to make sure it would work by looking up different airports in the routes.txt file and confirming the airports it could be able to fly to.

### Dijkstra 

Dijkstra algorithm was made and used to find the shortest path in a weighted graph. The algorithm was initially tested with a smaller dataset that was hand drawn. After showing it worked for those cases, we moved onto testing various airports on the entire data set. The algorithm accepts two parameters, a starting airport and ending airport, and returns the shortest path from the two airports using the routes.txt and data.txt files. 

### Eulers

We implemented Euler's path so that only one edge will be traversed exactly once. The function takes in a starting airport and checks if a Euler path exists or not. If there is an Euler path, the path is printed. The method would be deemed successful because we tested the Euler path on various airports and we would count to see if the size of the path minus one would be equal to the number of nodes for a given airport in the adjacency list.

### The answer to your leading questions

We answered our leading questions by being able to find the shortest path between two airports, a start and end airport, while also being able to find all the airports that can be flown to using a Breadth First Search, which was all in our initial leading question. We were also able to implement Euler's Path to see if each airport in a graph would only be traversed once. We discovered a lot about the importance of data parsing and making sure the data is correct, since we faced a lot of problems with access null values initially. In addition, we also learned a lot more about writing tests for our algorithms making sure the tests are not shallow are very important and making sure you hit all possible cases. Overall, the OpenFlights Project was a great experience to learn more working in projects with a group using tools such as github while also diving deepr into the data structure algorithms welearned in class. 

