#include <iostream>

void Problem3()
{
  long n=600851475143;
  long j=n;
  
  std::vector <unsigned int> prime_factors;
  
  for (long i=2; i<=sqrt(n); ++i)
  {
    while (j%i==0)
    {
      j=j/i;
      prime_factors.push_back(i);
    }
  }
  
  std::cout<<"Largest prime factor of "<<n<<" is "<<prime_factors.at(prime_factors.size()-1)<<std::endl;
}
    
    
