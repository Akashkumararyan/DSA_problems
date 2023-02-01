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



#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}


1967. Number of Strings That Appear as Substrings in Word


Example 1:

Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
Example 2:

Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.
Example 3:

Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".


  
        for(int i =0; i<word.size(); i++){
            string str = "";
            for(int j = i; j<word.size(); j++){
                str += word[j];
                s.push_back(str);
            }
        }
        
        set<string> st;
        for(int i =0; i<s.size(); i++){
            st.insert(s[i]);
        }
        //  for(auto it:st){
        //     cout<<it<<endl;
        // }
        for(auto j : st){
                
            for(int i=0;i< pa.size();i++){

                    if(j == pa[i]){
                        cout<<pa[i]<<" "<<j<<endl;
                        cnt++;
                    }
            }
        }
        return cnt;
    }


1876. Substrings of Size Three with Distinct Characters


Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".



  int countGoodSubstrings(string s) {
        int cnt=0;
        if(s.size()<=2) return cnt;

        for(int i=0;i<s.size()-2;i++){
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2])
            cnt++;
        }
        return cnt;
    }


520. Detect Capital

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false

 bool detectCapitalUse(string word) {
        int cnt=0;
        if(word.size()==1) return true;
        for(int i=0;i<word.size();i++){
            if(word[i]>=65 && word[i]<=90)
                cnt++;
        }
        if(cnt==1 && isupper(word[0]))
          return true;
        else if(cnt==0 || cnt==word.size())
          return true;
        else return false;    
    }





