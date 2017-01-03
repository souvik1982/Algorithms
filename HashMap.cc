// Hashing and chaining
// implemented by Souvik on Nov 26, 2016
// using a linked list and nothing from STL

#include <iostream>
#include <string>

class HashMap
{
  
  private:
    
    const static unsigned int nTableSize_=10;
    struct item
    {
      std::string obj1;
      std::string obj2;
      item*       obj3;
    };
    item internalTable_[nTableSize_];
    
  
  public:
  
    HashMap()
    {
      for (unsigned int i=0; i<nTableSize_; ++i)
      {
        internalTable_[i]={"NULL", "NULL", 0};
      }
    }
    
    unsigned int hashFunction(std::string word)
    {
      unsigned int totalASCII=0;
      for (unsigned int i=0; i<word.size(); ++i)
      {
        totalASCII+=word.at(i);
      }
      return totalASCII%nTableSize_;
    }
    
    void addEntry(std::string obj1, std::string obj2)
    {
      unsigned int hash=hashFunction(obj1);
      
      item *it=&(internalTable_[hash]);
      while (it->obj1!="NULL")
      {
        it=it->obj3;
      }
      item *newIt=new item;
      newIt->obj1="NULL";
      newIt->obj2="NULL";
      newIt->obj3=0;
      it->obj1=obj1;
      it->obj2=obj2;
      it->obj3=newIt;
    }
    
    std::string getEntry(std::string obj1)
    {
      unsigned int hash=hashFunction(obj1);
      
      item *it=&(internalTable_[hash]);
      while (it->obj1!=obj1 && it->obj1!="NULL")
      {
        it=it->obj3;
      }
      return it->obj2;
    }
      
    
};

int main()
{
  HashMap hash;
  hash.addEntry("Souvik", "773.543.6998");
  hash.addEntry("Saptaparna", "401.215.7223");
  hash.addEntry("Tapan", "+91.9830123223");
  
  std::cout<<"hash.getEntry(\"Souvik\") = "<<hash.getEntry("Souvik")<<std::endl;
  std::cout<<"hash.getEntry(\"Saptaparna\") = "<<hash.getEntry("Saptaparna")<<std::endl;
  std::cout<<"hash.getEntry(\"Tapan\") = "<<hash.getEntry("Tapan")<<std::endl;
  std::cout<<"hash.getEntry(\"Ashish\") = "<<hash.getEntry("Ashish")<<std::endl;
  
  return 0;
}
  

    
  
      
      
