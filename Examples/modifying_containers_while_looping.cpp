#include <iostream>
#include <vector>






int main() {
    

   std::vector<int> v = {1,2,3,4};

    // while adding the end of the vector will be changed
    // it will cause unexpected results

    /*
   for(auto x : v)
        v.push_back(x);
    */

   
   const std::size_t size = v.size();
   for(int i = 0; i < size; ++i)
        v.push_back(v[i]);

    for(auto x : v)
        std::cout << x << "\n";
    
    return 0;
}