#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
  // Fill a vector with random numbers;
  std::vector<int> v;
  for (unsigned int i=0; i<v.size(); ++i) v.push_back(rand()%100);
  
  // 
