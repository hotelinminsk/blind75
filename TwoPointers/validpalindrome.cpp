#include <iostream>
#include <string>

using namespace std;


// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.


// if((str[i]>96) && (str[i]<123))   - 32
// flip the 5th bit
class Solution {
private:
    void toLower(string* s){
        if(s->size() == 0){
            return;
        }

        string::iterator begin = s->begin();
        string::iterator end = s->end();

        while(begin != end){
            if((*begin > 96 - 32 ) && (*begin < 123 - 32)){
                *begin ^= 0x20;
            }

            begin++;
        }

        
    }

public:
    bool isPalindrome(string s) {
        bool palindrome = false;
        if(s.size() == 0) return false;
        
        toLower(&s);


        string::iterator begin = s.begin();
        string::iterator end = s.end();
        int count = 0;
        while ((begin <= end))
        {
            cout << "iteration : "<< count++ << endl;
            if(isalnum(*begin) && isalnum(*end)){
                if(*begin != *end){
                    palindrome = false;
                    break;
                }else{
                    palindrome = true;
                    begin++;end--;
                    continue;
                }

            }else if(!isalnum(*begin)){
                begin++;
            }else if(!isalnum(*end)){
                end--;
            }
            
        }

        return palindrome;
    }
};


int main(){

    Solution sl;
    bool sol = sl.isPalindrome("Was it a car or a cat I saw?");


    cout << "The new string : "<< sol << endl;

}
