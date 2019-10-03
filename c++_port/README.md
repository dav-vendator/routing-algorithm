# DSDV ALGORITHM:

> Destination-Sequenced Distance-Vector Routing (DSDV) is a table-driven routing scheme for ad hoc mobile networks based on the Bellman–Ford algorithm. It was developed by C. Perkins and P.Bhagwat in 1994.

## Input:
> A graph in form of a Weight Matrix(A NxN array).

## Output:
<img src="https://raw.githubusercontent.com/dav-vendator/routing-algorithm/master/output.png" title="DSDV">

## Explanation of output
1. **Destination** : Destination to reach
2. **Next Node** : If there exist a shortest path (or path) then this column contains next node in that path (A if path is A -> B -> C).
3. **Distance** : Distance between  source and destination node in found shortest path (number of nodes in between) else -1.
4. **Sequence** : Sequence basically contains a pseudo random number, if there exist a path between source and destination then this number is even else it's odd.
