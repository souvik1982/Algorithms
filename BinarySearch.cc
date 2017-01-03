#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

int main()
{
  clock_t t=clock();
  std::vector <double> numbers = {1, 22, 33, 54, 75, 116, 137, 178, 199, 2310, 2911, 3112, 3713, 4114, 4315, 4716, 5317, 5918, 6119, 6720, 7121, 7322, 7923, 8324, 8925, 9726, 10127, 10328, 10729, 10930, 11331, 12732, 13133, 13734, 13935, 14936, 15137, 15738, 16339, 16740, 17341, 17942, 18143, 19144, 19345, 19746, 19947, 21148, 22349, 22750, 22951, 23352, 23953, 24154, 25155, 25756, 26357, 26958, 27159, 27760, 28161, 28362, 29363, 30764, 31165, 31366, 31767, 33168, 33769, 34770, 34971, 35372, 35973, 36774, 37375, 37976, 38377, 38978, 39779, 40180, 40981, 41982, 42183, 43184, 43385, 43986, 44387, 44988, 45789, 46190, 46391, 46792, 47993, 48794, 49195, 49996, 50397, 50998, 52199, 523100, 541100};
  int prime=40181;
  unsigned int indexLo=0, indexHi=numbers.size();
  unsigned int index=(unsigned int)((indexLo+indexHi)/2.);
  while (numbers.at(index)!=prime && indexLo<indexHi)
  {
    if (prime>numbers.at(index)) indexLo=index+1;
    else if (prime<numbers.at(index)) indexHi=index-1;
    index=(unsigned int)((indexLo+indexHi)/2.);
  }
  if (prime==numbers.at(index)) std::cout<<prime<<" is a prime within my list."<<std::endl;
  else std::cout<<prime<<" is not a prime within my list."<<std::endl;
  t=clock()-t;
  std::cout<<"This took "<<t<<" CLKs"<<std::endl;
  return 0;
}
