# Dijkstra's Shortest Path Algorithm

> Dijkstra's algorithm (or Dijkstra's Shortest Path First algorithm, SPF algorithm) is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later. source: Wikipedia

## Informal working of this algorithm

1. Let G = (V, U) be weighted graph represented with help of adjacency list such that *u* is in adjacency list of *v* if and only if u is adjacent to v and vice-versa.
2. Initialize path array p_array with all the nodes adjacent to source *S*. Put along with cost of traversal. Set cost=&infin; for every node not adjacent to source.
3. For every node q in p_array except the source pop q. Find all the nodes adjacent to q and then update the paths currently we have by following expression for every neighbor p of q.  
<center> newCost[s, p] = min(cost(u,p), cost(u,q) + cost(q, p)) </center>

4. Push all neighbors of q into p_array and keep performing step 3 and 4 until all elements in p_array has been examined.  
  
  
**PS**: In implementation, I've used two separate arrays for this called paths and current_List.