
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {

public:
    int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> seen;
            int start = 0, maxLen = 0;

            for(int end = 0; end < s.length(); end++){
                if(seen.count(s[end])){
                    start = max(start, seen[s[end]] + 1);

                }

                seen[s[end]] = end;

                maxLen = max(maxLen, end - start + 1);


            }

            return maxLen;

        }

        // for(char k : s){
        //     if(seen.count(k) != 1){
        //         seen.insert(make_pair(k, seen_at));
        //         substring.push_back(k);
        //     }else{

        //         if(substring.size() > maxsubstring.size()){
        //             maxsubstring.clear();
                    
        //             for(char m : substring){
        //                 maxsubstring.push_back(m);
        //             }

        //             seen.clear();
        //             substring.clear();
        //             seen.insert(make_pair(k, 1));
        //             substring.push_back(k);
        //         }
        //     }

        //     seen_at++;

        // }

    
};



int main(){
    string s = "dvdf";
    Solution sol1;

    string s1 = "pwwkew";

    cout << sol1.lengthOfLongestSubstring(s)<< endl;
    
    cout << sol1.lengthOfLongestSubstring(s1) << endl;

    return 0;
}
