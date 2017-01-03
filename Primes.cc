#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>

int main()
{
  clock_t t=clock();
  unsigned int maxPrime=1e2;
  std::vector <unsigned int> primes;
  primes.push_back(2);
  for (unsigned int i=2; primes.size()<=maxPrime; ++i)
  {
    bool wasDivisible=false;
    for (unsigned int j=0; primes.at(j)*primes.at(j)<=i && wasDivisible==false; ++j)
    {
      if (i % primes.at(j)==0) wasDivisible=true;
    }
    if (!wasDivisible) 
    {
      primes.push_back(i);
      std::cout<<primes.size()-1<<", "<<i;
    }
  }
  t=clock()-t;
  
  std::cout<<maxPrime<<" nth prime = "<<primes.at(maxPrime)<<std::endl;
  std::cout<<"This took "<<(float)t<<" CLK"<<std::endl;
  return 0;
}
