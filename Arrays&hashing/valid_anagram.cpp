// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// Example 1:

// Input: s = "racecar", t = "carrace"

// Output: true

// Example 2:

// Input: s = "jar", t = "jam"

// Output: false
#include <string.h>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,long> map1;
        unordered_map<char,long> map2;
        
        for(char x : s){
            if(map1.count(x)){
                map1[x] += + 1;
            }

            map1.insert({x,1});
        }

        for(char x : t){
            if(map2.count(x)){
                map2[x] += + 1;
            }

            map2.insert({x,1});
        }

        bool k = true;
        for(auto one : map1){
            if(map2[one.first] != one.second){
                k = false;
                break;
            }
        }


        return k;
    }
};



int main(){

    Solution sol1;
    cout<<sol1.isAnagram("jar", "jam")<<endl;
    cout<<sol1.isAnagram("racecar", "carrace")<<endl;


    return 0;
}