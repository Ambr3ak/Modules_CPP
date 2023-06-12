#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 7, 9};
    int lo = 4;
    
    // Find the lower bound of 4 in the vector
    auto it = std::lower_bound(v.begin(), v.end(), lo);
    
    if (it != v.end()) {
        std::cout << "The lower bound of lo is " << *it << std::endl;
        v.insert(it, lo);
    } else {
        std::cout << "The lower bound of 4 is not found" << std::endl;
    }
    for (int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
    
    return 0;
}