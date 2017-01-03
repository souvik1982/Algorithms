#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int median(vector<int> v, vector<int> *vL, vector<int> *vR)
{
  unsigned int halfIndex=(v.size()-1)/2;
  if (v.size()%2) // Odd size
  {
    if (vL!=0) for (unsigned int i=0; i<halfIndex; ++i) vL->push_back(v.at(i));
    if (vR!=0) for (unsigned int i=halfIndex+1; i<v.size(); ++i) vR->push_back(v.at(i));
    return v.at(halfIndex);
  }
  else // Even size
  {
    if (vL!=0) for (unsigned int i=0; i<=halfIndex; ++i) vL->push_back(v.at(i));
    if (vR!=0) for (unsigned int i=halfIndex+1; i<v.size(); ++i) vR->push_back(v.at(i));
    return (v.at(halfIndex)+v.at(halfIndex+1))/2.;
  }
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  unsigned int n;
  cin>>n;
  vector<int> v(n);
  for (unsigned int i=0; i<n; ++i) cin>>v.at(i);
  
  sort(v.begin(), v.end());
  
  vector<int> vL, vR;
  double Q2=median(v, &vL, &vR);
  double Q1=median(vL, 0, 0);
  double Q3=median(vR, 0, 0);
    
  cout<<Q1<<endl;
  cout<<Q2<<endl;
  cout<<Q3<<endl;
  
  return 0;
}
