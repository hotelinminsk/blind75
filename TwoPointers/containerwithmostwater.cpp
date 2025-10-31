#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 1){return 0;}
        int begin = 0;
        int end = height.size() - 1 ;

        int leftmax= height[begin];
        int rightmax = height[end];
        int max_area = 0;
        while (begin <= end)
        {
            int x = end - begin;
            int y = min(height[end], height[begin]);

            if(x * y >= max_area) {
                max_area = x*y;
            }

            if(height[end] > height[begin]){
                begin++;
            }else{
                end--;
            }

        }


        return max_area;

    }
};

int main(){

    cout << "Test "<<endl;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution sol1 ;
    cout << "The max area is " << sol1.maxArea(height)<<endl;


}