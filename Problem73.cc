#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> factors(int n)
{
  std::vector<int> v_factors; v_factors.push_back(1);
  int n_temp=n;
  for (unsigned int i=2; n_temp>1; ++i)
  {
    while (n_temp%i==0)
    {
      n_temp/=i;
      if (v_factors.at(v_factors.size()-1)!=i) v_factors.push_back(i);
    }
  }
  return v_factors;
}

int main()
{
  int d=8;
  std::vector<int> v_factors=factors(d);
  
  unsigned int nFractions=0;
  for (unsigned int j=2; j<=d; ++j)
  {
    std::vector<int> v_factors=factors(j);
    for (int n=1; n<j; ++n)
    {
      bool divisible=false;
      for (unsigned int i=1; i<v_factors.size(); ++i)
      {
        if (n%v_factors.at(i)==0)
        {
          divisible=true;
          break;
        }
      }
      if (!divisible && float(n)/float(j)<float(1.)/float(2.) && float(n)/float(j)>float(1.)/float(3.)) ++nFractions;
    }
  }
  std::cout<<"nFractions = "<<nFractions<<std::endl;
    
  
}
