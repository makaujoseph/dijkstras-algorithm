# Dijkstra's Algorithm

This is a description of how the executable for Dijkstra's algorithm works.

1. Enter number of nodes (integer between 1 and 20) - refer as n
   * 20 is max in concern for size
2. For each node, enter the distance away from other nodes
   * The program will prompt: "dists from node 0: "
   * For n vertices, the prompt will repeat for nodes 0 to n
   * Following the prompt, enter a distance between the prompted node and all other nodes
     1. Distance to self is 0, and distance to nonadjacent nodes is 0
3. Enter starting node (initial node to being algorithm)
4. Enter ending node (between 0 and n), program will calculate distance and show path between starting node and ending node.
   * Will repeat until user enters -1
  
## Notes

Lots of error checking was omitted (i.e. checking that number of nodes is between 1 and 20, checking that the ending node is valid, etc.) for the sake of simplicity. This program assumes all correct inputs.
