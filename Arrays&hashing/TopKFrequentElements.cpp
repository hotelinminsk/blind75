// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1

// Output: [1]

// Example 3:

// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// Output: [1,2]



#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> top;
        map<int,int> frequency;

        for(int x : nums){
            if(frequency.count(x)){
                frequency[x] += 1;
            }else{
                frequency.insert({x, 1});
            }
        }

        for(int i = 0; i < k; i++){
            pair<int,int> max = {0, 0};
            for(auto pair : frequency){
                if(pair.second > max.second){
                    max.second = pair.second;
                    max.first = pair.first;
                }
            }
            top.insert(top.begin(),max.first);
            frequency.erase(max.first);
        }

        return top;
    }
};


int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;


    Solution sol1;

    vector<int> top = sol1.topKFrequent(nums, k);
    int counter;
    counter = 0;
    for(int i : top){
        cout << "Max " << counter++ <<"'st element is : "<< i<< endl;
    }

    return 0;
}