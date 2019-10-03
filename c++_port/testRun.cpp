
#include <iostream>
#include "graph.hpp"
using namespace std;
int main()
{
    vgraph::Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    
    g.addEdge(1, 4);
    
    g.addEdge(2, 4);
    
    g.addEdge(3, 6);
    
    g.addEdge(4, 7);
    g.addEdge(4, 5);
    
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    
    g.addEdge(6, 7);

   cout<<"\n";
   for(int i=0; i<8; i++){
     cout<<"\n\n";
     g.generateRoutingTable(i);
   }
   cin.get();
   return 0;
}