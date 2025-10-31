#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // You are given an array prices where 
    // prices[i] is the price of a given stock on the ith day.
    int maxProfit(vector<int>& prices){
        int profit = 0;
        int mincost = prices[0];
        int begin = 1;
        int mincostindex = 0;

        while(begin < prices.size()){
            int temp = prices[begin];

            if(begin > mincostindex){
                
                if(temp - mincost > profit){
                    profit = temp-mincost;
                }
            }
            

            if(temp < mincost){
                mincost = temp;
                mincostindex = begin;
            }

            begin++;

            cout << "The temp : "<< temp << " the profit: "<< profit << " the mincost: "<< mincost<<endl;
        }

        return profit;
    }
    
    // int maxProfit(vector<int>& prices) {
    //     int left = 0;
    //     int right = prices.size() - 1;       
    //     int max_profit = 0;
    //     int cheapest_price = 999;
    //     int max_price = -999;
    //     pair<int,int> cheapest_max;
    //     while(left <= right){
    //         int leftprice = prices[left];
    //         int rightprice = prices[right];

    //         if(leftprice < cheapest_price){
    //             cheapest_price = leftprice;
    //         }
    //         if(rightprice > max_price){
    //             max_price = rightprice;
    //         }

    //         if((max_price - cheapest_price) > max_profit){
    //             max_profit = max_price - cheapest_price;
    //         }

    //         cout << "Left is : "<<left << " right is : "<< right << " cheapest price : "<< cheapest_price << " largest price: "<< max_price <<" max_profit : "<< max_profit <<endl;

    //         left++;
    //         right--;
    //     }


    //     return max_profit;
    // }
};



int main(){

    Solution sol1;

    vector<int> prices = {3,2,6,5,0,3,-1};

    sol1.maxProfit(prices);
}