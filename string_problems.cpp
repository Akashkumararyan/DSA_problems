Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.


   int lengthOfLastWord(string s) {
        int cnt=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
          if(s[i]==' ' && cnt==0)
              continue;
            if(s[i]==' ' && cnt!=0)
                break;
            cnt++;
        }
            
        return cnt;
    }
}



Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.


string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string ans=words[i];
            string temp=ans;
            reverse(temp.begin(),temp.end());
            
            if(ans==temp)
                return ans;
        }
        return "";
    }



Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".



   string reversePrefix(string word, char ch) {
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                reverse(word.begin(),word.begin()+i+1);
                break;
            }
        }
        return word;
    }


Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"

   string reverseWords(string s) {
        int i=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==' '){
                reverse(s.begin()+i,s.begin()+j);
                    i=j+1;
            }
        }
        reverse(s.begin()+i,s.end());
        
        return s;
    }


     valid palindrone


 bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
             if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
                ans.push_back(s[i]);
        }
        
        for(int i=0;i<ans.size();i++){
            ans[i]=tolower(ans[i]);
        }
        
        int x=0,y=ans.size()-1;
        while(x<=y){
            if(ans[x] != ans[y])
                return false;
            else{
                x++;
                y--;
            }
        }
        return true;
    }    
}



 char tolower(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
            return ch;
        else{
            char temp=ch-'A'+'a';
            return temp;
        }
    }



Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".



  string removeOccurrences(string s, string part) {
        while(s.size()!=0 && s.find(part)<s.size()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }


Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.


   string largestGoodInteger(string num) {
        char ans=0;
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i]==num[i-2])
                ans=max(ans,num[i]);
        }
        if(ans==0) return "";
        else
            return string(3,ans);
        
    }


Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.


   string greatestLetter(string s) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        sort(s.begin(),s.end());
        string ans="";
        for(int i=0;i<s.size();i++){
            char l=tolower(s[i]);
            char u=toupper(s[i]);
            
            if(mp[l] && mp[u]){
                ans=u;
            }
        }
        return ans;
    }


Example 1:

Input: password = "IloveLe3tcode!"
Output: true
Explanation: The password meets all the requirements. Therefore, we return true.
Example 2:

Input: password = "Me+You--IsMyDream"
Output: false
Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
Example 3:

Input: password = "1aB!"
Output: false
Explanation: The password does not meet the length requirement. Therefore, we return false.




bool strongPasswordCheckerII(string p) {
        if(size(p) < 8) return false;
        bool low = false , upper = false ,digit = false ,special = false;
        for(auto c : p){
            if(c>='a' and c<='z') low = true;
            else if(c>='A' and c <='Z') upper = true;
            else if(isdigit(c)) digit = true;
            else special = true;
        }
        for(int i=0;i<p.size();i++) if(p[i] == p[i+1]) return false;
        if(low && upper && digit && special) return true;
        return false;
    }
};



Example 1:

Input: s = "abcdefghi", k = 3, fill = "x"
Output: ["abc","def","ghi"]
Explanation:
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.
Since all groups can be completely filled by characters from the string, we do not need to use fill.
Thus, the groups formed are "abc", "def", and "ghi".
Example 2:

Input: s = "abcdefghij", k = 3, fill = "x"
Output: ["abc","def","ghi","jxx"]
Explanation:
Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".



  vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        for(int i=0;i<s.size();i=i+k){
           string t=s.substr(i,k);
           if(t.size()==k){
               v.push_back(t);
               continue;
           }
           int l=t.size();  
            for(int j=0;j<(k-l);j++)  
                t+=fill;
				
            v.push_back(t);
        }
        return v;
    }
};



Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".



  string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        int cnt=0;
        for(auto i:arr){
            if(mp[i]==1)
              cnt++;

              if(cnt==k)
              return i;
        }
        return "";
    }




1832. Check if the Sentence Is Pangram

xample 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false


bool checkIfPangram(string sentence) {
        vector<int> v(26,0);
        for(auto x:sentence){
            v[x-97]++;
        }
        for(int i=0;i<v.size();i++){
            if(!v[i]) return false;
        }
        return true;
    }

17. Reverse Only Letters

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


  string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            while(i<j && !isalpha(s[i])) i++;
            while(j>=0 && !isalpha(s[j])) j--;
            if(i>j) break;
            swap(s[i++],s[j--]);
        }
        return s;
    }


205. Isomorphic Strings

xample 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true


 bool isIsomorphic(string s, string t) {
        char cs[128]={0},ct[128]={0};
        for(int i=0;i<s.size();i++){
            if(cs[s[i]] != ct[t[i]]) return false;
            else if(!cs[s[i]]){
                cs[s[i]]=i+1;
                ct[t[i]]=i+1;
            }
        }
        return true;
    }



944. Delete Columns to Make Sorted

Example 1:

Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.
Example 2:

Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.
Example 3:

Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.


int minDeletionSize(vector<string>& strs) {
        int delete_count=0;
        int row = strs.size();
        int col = strs[0].size();
        
        for(int j=0; j<col; j++)
        {
            for(int i=0; i<row-1; i++)
            {
                if(strs[i][j]>strs[i+1][j])
                {
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }


942. DI String Match

Example 1:

Input: s = "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: s = "III"
Output: [0,1,2,3]
Example 3:

Input: s = "DDI"
Output: [3,2,0,1]

  vector<int> diStringMatch(string s) {
        int n=s.size();
        int low=0;
        int high=n;
        vector<int> v;
        for(int i=0;i<=n;i++){
            if(s[i]=='I'){
               v.push_back(low);
               low++;
            }
            else{
                v.push_back(high);
                high--;
            } 
        }
        return v;
    }
