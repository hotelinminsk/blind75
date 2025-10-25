// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        vector<int> leftproduct;
        vector<int> rightproduct;

        for(int i = 0; i<nums.size(); i++){
            if(leftproduct.size() < 1){
                leftproduct.insert(leftproduct.begin(), 1);
                continue;
            }

            leftproduct.insert(leftproduct.begin() + i, leftproduct[i-1] * nums[i-1]);
           cout << leftproduct[i] << endl;

        }

        vector<int> sum;
        int j = nums.size() - 1;
        int right = 1;
        for(j; j != -1; j--){
            if(j == nums.size() -1 ){
                sum.insert(sum.begin(), right * leftproduct[j]);
                continue;
            }

            right = right * nums[j+1];
            sum.insert(sum.begin(), right * leftproduct[j]);

        }
        return sum;
    }
};

int main(){
    Solution sol1;

    sol1.productExceptSelf({1,2,4,5,6});

    return 0;

}