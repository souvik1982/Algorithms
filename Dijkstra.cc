/*-------------------------
Souvik's implementation
of Dijkstra's path finding
algorithm.
December 8, 2016
--------------------------*/

#include <iostream>
#include <vector>
#include <cstdlib> //for random numbers
#include <iomanip>

std::vector<std::vector<double> > makeGraph(unsigned nNodes)
{
  std::vector<std::vector<double> > graph;
  for (unsigned int i=0; i<nNodes; ++i)
  {
    std::vector<double> row;
    for (unsigned int j=0; j<nNodes; ++j)
    {
      if (i!=j)
      {
        double distance=double(rand()%100)/double(50);
        if (distance<=1.) row.push_back(distance);
        else row.push_back(0);
      }
      else row.push_back(99);
    }
    graph.push_back(row);
  }
  return graph;
}

void printGraphMatrix(std::vector<std::vector<double> > *graph)
{
  std::cout<<"The graph in matrix form: "<<std::endl;
  std::cout<<"  ";
  for (unsigned int i=0; i<graph->size(); ++i) std::cout<<std::setw(5)<<i<<"|";
  std::cout<<std::endl<<" --- "<<std::endl;
  for (unsigned int i=0; i<graph->size(); ++i)
  {
    std::cout<<i<<"| ";
    for (unsigned int j=0; j<graph->at(i).size(); ++j)
    {
      std::cout<<std::setw(5)<<graph->at(i).at(j)<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<"=== "<<std::endl;
}

double shortestDijkstra(unsigned int node1, unsigned int node2, std::vector<unsigned int> *path, std::vector<std::vector<double> > *graph)
{
  std::vector<double> v_nodeDistances(graph->size()); // Node distances from node1
  for (unsigned int i=0; i<v_nodeDistances.size(); ++i) v_nodeDistances.at(i)=999;
  v_nodeDistances.at(node1)=0;
  
  std::vector<unsigned int> v_nodeVisited;
  for (unsigned int i=0; i<v_nodeDistances.size(); ++i) v_nodeVisited.push_back(0);
  
  path->push_back(node1);
  unsigned int currentNode=node1;
  unsigned int nextCurrentNode=currentNode;
  double minDistanceNeighbor=999;
  do
  {
    minDistanceNeighbor=999;
    for (unsigned int j=0; j<graph->at(currentNode).size(); ++j) // All neighbors of the current node
    {
      if (j!=currentNode && v_nodeVisited.at(j)==0) // No self-connections. Is this neighbor unvisited?
      {
        double distanceToNeighbor=graph->at(currentNode).at(j);
        if (distanceToNeighbor!=0) // Is there a connection? This is not necessary, but may speed things up a bit
        {
          double tempDistance=v_nodeDistances.at(currentNode)+distanceToNeighbor;
          if (tempDistance<v_nodeDistances.at(j)) v_nodeDistances.at(j)=tempDistance;
          if (tempDistance<minDistanceNeighbor)
          {
            minDistanceNeighbor=tempDistance;
            nextCurrentNode=j;
          }
        }
      }
    }
    v_nodeVisited.at(currentNode)=1;
    currentNode=nextCurrentNode;
    path->push_back(currentNode);
  }
  while (currentNode!=node2 && minDistanceNeighbor!=999);
        
  return minDistanceNeighbor;
}

int main()
{
  std::vector<std::vector<double> > graph = makeGraph(10); // 5 nodes in the graph
  printGraphMatrix(&graph);
  
  std::vector<unsigned int> path;
  double shortestDistance=shortestDijkstra(0, 4, &path, &graph);
  if (shortestDistance!=999)
  {
    std::cout<<"The shortest distance = "<<shortestDistance<<std::endl;
    std::cout<<"The shortest path = "<<path.at(0);
    for (unsigned int i=1; i<path.size(); ++i) std::cout<<"->"<<path.at(i);
    std::cout<<std::endl;
  }
  
  return 0;
}
