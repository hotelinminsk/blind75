#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        bool hasduplicate = false;

        std::unordered_map<int,int> map;
        for(int i: nums){
            if(map.count(i)){
                hasduplicate = true;
                break;
            }
            std::pair p = std::make_pair(i,1);
            map.insert(p);
        }

    
        return hasduplicate;
    }

};


int main(){

    std::vector<int> test = {1, 2, 3, 4};
    Solution sol1;
    std::cout << sol1.hasDuplicate(test) << std::endl;

    return 0;
}