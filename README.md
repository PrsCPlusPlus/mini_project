Dijkstra's Shortest Path Algorithm:

Input:
- `vec`: A 2D vector representing the graph with each row containing (u, v, w) denoting an edge from vertex u to vertex v with weight w.
- `vertices`: The total number of vertices in the graph.
- `edges`: The total number of edges in the graph.
- `source`: The source vertex from which the shortest paths are calculated.

Output:
- `dist`: A vector of integers representing the shortest distance from the source vertex to every other vertex.

Algorithm:

1. Create an empty adjacency list `adj` to represent the graph.

2. Populate the adjacency list `adj` with edges and their corresponding weights:
   - For each edge (u, v, w) in `vec`:
     - Add (v, w) to `adj[u]` (since it's an undirected graph, add (u, w) to `adj[v]` as well).

3. Initialize a vector `dist` of size `vertices` with all elements set to `INT_MAX`, representing initial distances.

4. Create an empty set `st` to store pairs (distance, vertex).

5. Set the distance of the `source` vertex to 0 and insert (0, `source`) into `st`.

6. While `st` is not empty:
   - Get the top element `(node_distance, top_node)` from `st`.
   - Remove the top element from `st`.
   - For each neighbor of `top_node` in `adj`:
     - Calculate the new distance `node_distance + neighbor.weight`.
     - If the new distance is less than the current distance in `dist` for the neighbor:
       - Find and erase the existing record of the neighbor from `st` if it exists.
       - Update `dist[neighbor]` with the new distance.
       - Insert `(new_distance, neighbor)` into `st`.

7. Return the vector `dist` containing the shortest distances.

Time Complexity:
- The time complexity of Dijkstra's algorithm with a binary heap is O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph.

This algorithm efficiently finds the shortest path between a given source vertex and all other vertices in a weighted, undirected graph using Dijkstra's shortest path algorithm.
