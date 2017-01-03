#include <iostream>
#include <vector>
#include <cstdlib> //for random numbers 
#include <time.h>                                                                                                    

void print_vector(std::vector<int> *v)
{
  for (unsigned int i=0; i<v->size(); ++i) std::cout<<v->at(i)<<" ";
  std::cout<<std::endl;
}

std::vector<int> merge(std::vector <int> v1, std::vector<int> v2)
{
  std::vector<int> v_output;
  unsigned int i_v1=0, i_v2=0;
  while (i_v1<v1.size() && i_v2<v2.size())
  {
    if (v1.at(i_v1)<v2.at(i_v2))
    {
      v_output.push_back(v1.at(i_v1));
      ++i_v1;
    }
    else
    {
      v_output.push_back(v2.at(i_v2));
      ++i_v2;
    }
  }
  while (i_v1<v1.size())
  {
    v_output.push_back(v1.at(i_v1));
    ++i_v1;
  }
  while (i_v2<v2.size())
  {
    v_output.push_back(v2.at(i_v2));
    ++i_v2;
  }
  return v_output;
}

std::vector<int> merge_sort(std::vector<int> v)
{
  std::vector<int> v1, v2;
  for (unsigned int i=0; i<int(v.size())/2; ++i) v1.push_back(v.at(i));
  for (unsigned int i=int(v.size())/2; i<v.size(); ++i) v2.push_back(v.at(i));
  
  if (v1.size()>1) v1=merge_sort(v1);
  if (v2.size()>1) v2=merge_sort(v2);
  
  std::vector<int> v3;
  v3=merge(v1, v2);
  return v3;
}

int main()
{
  //Fill vector with random numbers                                                                                                         
  std::vector<int> v;
  for(int i=0; i<10000; ++i) v.push_back(rand()%100);

  //Print                                                                                                                                   
  print_vector(&v);
  
  //Merge sort 
  std::cout<<"SORTED"<<std::endl;                                                                                                                             
  clock_t t=clock();                                                                                                                             
  std::vector<int> m = merge_sort(v);
  t=clock()-t;

  //Print                                                                                                                                   
  print_vector(&m);
  std::cout<<"Timing for "<<v.size()<<" elements = "<<t<<" CLKs"<<std::endl;
  
  return 0;
}


