#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

// A breadth-first search to find connectedness between a and b
bool connected(vector<vector<int> > *pairs, int a, int b)
{
  std::vector<int> visitedNodes(pairs->size());
  for (unsigned int i=0; i<visitedNodes.size(); ++i) visitedNodes.at(i)=0;
  
  std::vector<int> activeStack;
  activeStack.push_back(a);
  
  while (activeStack.size()>0)
  {
    int a=activeStack.back();
    activeStack.pop_back();
    if (visitedNodes.at(a)==0) // not discovered
    {
      visitedNodes.at(a)=1;  
      for (unsigned int i=0; i<pairs->at(a).size(); ++i)
      {
        int bCand=pairs->at(a).at(i);
        if (b==bCand) return true;
        if (visitedNodes.at(bCand)==0) activeStack.push_back(bCand);
      }
    }
  }
  return false;
}

int main()
{ 
  int N, I;
  cin >> N >> I;
  vector<vector<int> > pairs(N);
  for (int i = 0; i < I; ++i) 
  {
    int a, b;
    cin >> a >> b;
    pairs[a].push_back(b);
    pairs[b].push_back(a);
  }
  
  long long result = 0;
  for (unsigned int i=0; i<N; ++i)
  {
    for (unsigned int j=i+1; j<N; ++j)
    {
      result+=!connected(&pairs, i, j);
    }
  }
    
  cout << result << endl;
  return 0;
}
