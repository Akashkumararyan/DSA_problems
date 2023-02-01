#include <iostream>

int main() {
   int prefixCount(vector<string>& words, string pref) {
        int n=words.size(),m=pref.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(words[i].substr(0,m)==pref)
                cnt++;
        }
        return cnt;
    }
}


Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.


  other solution by find string method

 int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if (words[i].find(pref) == 0)
            {
               count++; 
            }
        }
        return count;
    }








Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
Output: 3
Explanation:
The strings in words which are a prefix of s = "abc" are:
"a", "ab", and "abc".
Thus the number of strings in words which are a prefix of s is 3.
Example 2:

Input: words = ["a","a"], s = "aa"
Output: 2
Explanation:
Both of the strings are a prefix of s. 
Note that the same string can occur multiple times in words, and it should be counted each time.





int countPrefixes(vector<string>& words, string s) {
       int n=words.size(),m=s.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(s.substr(0,words[i].size())==words[i])
                cnt++;
        }
        return cnt;
     
    }
