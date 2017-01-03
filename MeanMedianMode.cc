#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
  
  unsigned int n;
  cin>>n;
  vector<int> v(n);
  double total=0;
  for (unsigned int i=0; i<n; ++i)
  {
    cin>>v.at(i);
    total+=v.at(i);
  }
  double mean=total/n;
  
  sort(v.begin(), v.end());
  
  double median;
  if (v.size()%2) median=v.at(n/2-1); // odd
  else median=(v.at(n/2)+v.at(n/2-1))/2.;
  
  map<int, unsigned int> modeMap;
  map<int, unsigned int>::iterator i_map;
  for (unsigned int i=0; i<n; ++i)
  {
    ++modeMap[v.at(i)];
  }
  unsigned int mode=0, modeCount=0;
  for (i_map=modeMap.begin(); i_map!=modeMap.end(); ++i_map)
  {
    if (i_map->second>modeCount)
    {
      modeCount=i_map->second;
      mode=i_map->first;
    }
  }
  
  
  cout<<mean<<endl;
  cout<<median<<endl;
  cout<<mode<<endl;
  
  return 0;
}
