#include <iostream>
#include "circularbuffer.h"
#include <algorithm>

int main()
{

   CircularBuffer<char> cbuf3(0);
    CircularBuffer<int> cbuf(10);
    std::cout << "Capacity: " << cbuf.capacity() <<std::endl;
    std::cout << "Is empty? " << std::boolalpha << cbuf.empty() <<std::endl;
    std::cout << "Size: " << cbuf.size() <<std::endl;
    cbuf.push_back(0);
    cbuf.push_back(1);
    cbuf.push_back(2);
    cbuf.push_back(3);
    cbuf.push_back(4);
    cbuf.push_back(5);
    cbuf.push_back(6);
    cbuf.push_back(7);
    cbuf.push_back(8);
    cbuf.push_back(9);
    cbuf.push_back(10);
    cbuf.push_back(11);
  /*  std::cout << "Is empty? " <<std::boolalpha << cbuf.empty() << std::endl;
    std::cout << "Size: " << cbuf.size() <<std::endl;
    std::cout << "Cbuf[2]" << cbuf.at(2) <<std::endl;
    cbuf.pop_front();
    std::cout << "Is empty? " <<std::boolalpha << cbuf.empty() << std::endl;
    std::cout << "Size: " << cbuf.size() <<std::endl;
    std::cout << "Cbuf[0]" << cbuf.at(0) <<std::endl;
    CircularBuffer<int> copy(cbuf);
    std::cout << "Copy[0]" <<copy.at(0) <<std::endl;
*/
    std::for_each(cbuf.begin(),cbuf.end(),[](int& a){a*=a;});
    for(auto it = cbuf.begin(); it !=cbuf.end();++it)
        std::cout << *it <<std::endl;

    return 0;
}
