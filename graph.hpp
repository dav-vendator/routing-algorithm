#include <iostream>
#include <list>
#include <vector>
#include <string>
//--Random Number
#include <cstdlib>
#include <ctime>

namespace vgraph{
using std::string;
using std::list;
using std::vector; 

class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists
    // A recursive function used by getAllPaths()
    void getAllPathsUtil(int , int , bool [], int [], int &,vector<vector<int>>&);
    vector<vector<int>> getAllPaths(int s, int d);
    void printHeader(int,int);
    void printMiddle(int,int,vector<string> what);
  public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);
    vector<int> getShortestPath(int,int);
    void generateRoutingTable(int);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    std::srand(std::time(nullptr));
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 's' to 'd'
vector<vector<int>> Graph::getAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
 
    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
    vector<vector<int>> routes;
    // Call the recursive helper function to print all paths
    getAllPathsUtil(s, d, visited, path, path_index,routes);
    return routes;
}
 
// A recursive function to get all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::getAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index,vector<vector<int>>& routes)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        vector<int> temp;
        for (int i = 0; i<path_index; i++){
            temp.push_back(path[i]);
        }
        routes.push_back(temp);
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                getAllPathsUtil(*i, d, visited, path, path_index,routes);
    }
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
 }

 vector<int> Graph::getShortestPath(int s,int e){
    vector<vector<int>> routes = getAllPaths(s,e);
    if(routes.size() <= 0){
        return {};
    }
    int min = routes[0].size();
    int index = 0;
    for(int i=1; i<routes.size(); i++){
        if(routes[i].size() < min){
            index = i;
            min = routes[i].size();
        }
    }
    return routes[index];
 }
 
 void Graph::printHeader(int spacing,int size){
  for(int i=0; i<size; i++){
     if(i % spacing == 0)
        std::cout<<'+';
     else
        std::cout<<"-";
   }
   std::cout<<"+";
 }

void Graph::printMiddle(int spacing,int size,vector<string> what){
  if(what.size() < size){
    for(int i=0; i < (size - what.size()); i++){
        what.push_back("NULL");
    }
  }
  int incr = 0;
  int arryCount = -1;
  for(int i=0; i<size; i++){
     if(i % spacing == 0){
        std::cout<<'|';
        arryCount++;
        incr = 0;
     }else{
        if(incr < what[arryCount].size()){
          std::cout<<what[arryCount][incr];
          incr++;
         }else{
            std::cout<<" ";
         }
     } 
   }
   std::cout<<"|";
 }

 void Graph::generateRoutingTable(int s){
    std::cout<<"\n\nGENERATING ROUTING TABLE (SOURCE : "<<s<<" ):\n\n";
    this->printHeader(20,20*5);
    std::cout<<"\n";
    this->printMiddle(20,20*5,{"S No.","Destination","Next Node","Distance","Sequence"});
    std::cout<<"\n";
    this->printHeader(20,20*5);
    vector<int> temp; 
    vector<string> data;
    vector<int> sp;
    for(int i=0; i < this->V; i++){
        std::cout<<"\n";
        sp = this->getShortestPath(s,i);
        temp.push_back(i);
        temp.push_back(i);
        temp.push_back(sp.empty()  ? -1 : sp.size() <= 1 ? sp[0] : sp[1]);
        temp.push_back(sp.size()-1);
        temp.push_back(sp.empty() ? 2*rand()+1 : 2 * rand());
        for(auto x : temp){
            data.push_back(std::to_string(x));
        }
        this->printMiddle(20,20*5,data);
        std::cout<<"\n";
        this->printHeader(20,20*5);
        data.clear();
        temp.clear();
    }
 }

}
