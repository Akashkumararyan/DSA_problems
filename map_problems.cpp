#include <bits/stdc++.h>
using namespace std;

int main() {

1.Input: lowLimit = 1, highLimit = 10
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
Box 1 has the most number of balls with 2 balls.
  
int func(int num)
    {
        int sum=0;
        while(num>0)
        {
            int rem=num%10;
            sum+=rem;
            num/=10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        map<int,int>mpp;
        int maxx=0;
        for(int i=lowLimit;i<=highLimit;i++)
        {
            mpp[func(i)]++;
        }
        for(auto it:mpp)
        {
            maxx=max(it.second,maxx);
        }
        return maxx;
    }


2.Roman to integer

   unordered_map<char ,int> mp; 
		 mp['I'] = 1;
		 mp['V'] = 5;
		 mp['X'] = 10;
		 mp['L'] = 50;
		 mp['C'] = 100;
		 mp['D'] = 500;
		 mp['M'] = 1000;

		int number = 0;
		for(int i = 0 ; i < s.size() ; i++){
			number += (mp[s[i]] >= mp[s[i + 1]] || i == s.size() - 1 ) ? mp[s[i]] : -mp[s[i]];         
		}
		return number;
	}
  
}


Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].


   int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it:nums){
            if(it!=0)
                m[it]++;
        }
        return m.size();
    }
};     












Sample 1:
Input
Output
4
3
3 3 3
6
1 3 2 1 2 2
4
1 2 1 2
5
1 3 2 4 5
0
3
2
4
Explanation:
Test case 11: All the elements are already same. Thus we need to perform zero operations.

Test case 22: We remove the elements A_1, A_2,A 
1
​
 ,A 
2
​
 , and A_4A 
4
​
  using three operations. The array becomes [2, 2, 2][2,2,2] where all elements are same.

Test case 33: We remove the elements A_1A 
1
​
  and A_3A 
3
​
  using two operations. The array becomes [2, 2][2,2] where all elements are same.

Test case 44: We remove the elements A_1, A_2, A_3,A 
1
​
 ,A 
2
​
 ,A 
3
​
 , and A_4A 
4
​
  using four operations. The array becomes [5][5].








#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int> A(n);
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    sort(A.begin(),A.end());
	    unordered_map<int,int> mp;
	    for(auto it:A){
	        mp[it]++;
	    }
	    int maxi=0;
	   for(auto x:mp)
        {
            maxi=max(x.second,maxi);
        }
        
        cout<<n-maxi<<endl;
	    
	}
	return 0;
}




Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.
Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.




  int mostFrequentEven(vector<int>& nums) {
       map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=-1,mx=-1;
        for(auto x:mp){
            if(x.first%2==0 && x.second >mx){
                ans=x.first;
                mx=x.second;
            }
        }
        return ans;
    }



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


   int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        
        int mx=0,ans=0;
        for(auto x:mp){
            if(x.second >mx){
                mx=x.second;
                ans=x.first;    
            }
            
        }
        return ans;
    }



Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

 

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.



  bool areOccurrencesEqual(string s) {
        bool b=true;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        int val=mp[s[0]];
        for(auto it:mp){
            if(it.second!=val)
            b=false;
            }
        return b;
    }



Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]


   vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> v1(n+1,0);
        vector<int> v2;
        
        for(auto i:nums){
            v1[i]++;
            if(v1[i]>1)
                v2.push_back(i);
        }
        
        for(int i=1;i<n+1;i++){
            if(v1[i]==0)
                v2.push_back(i);
        }
        return v2;
    }


Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true


  bool containsDuplicate(vector<int>& nums) {
        bool b=false;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
           if(++mp[nums[i]]==2)
               b= true;
        }
        
        return b;
        }


          Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1


  int n=s.size(),ans=-1;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1)
                return i;
        }
        return ans;
    }


Example 1:

Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
Example 2:

Input: nums = [[1,2,3],[4,5,6]]
Output: []
Explanation: 
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].


vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> v;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int m=nums[i].size();
            for(int j=0;j<m;j++){
                mp[nums[i][j]]++;
            }
        }
        for(auto it:mp){
            if(it.second==n)
                v.push_back(it.first);
        }
        return v;




Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.



  
  
  int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int ans=-1;
        for(auto it:arr){
         mp[it]++;
        }
        int mx=0;
        for(auto i:mp){
            
            if(i.first==i.second)
            ans=max(i.second,ans);
        }
        cout<<mx<<endl;
        return ans;
    }
	
	
	
	2150. Find All Lonely Numbers in the Array
		
		Input: nums = [10,6,5,8]
Output: [10,8]
Explanation: 
- 10 is a lonely number since it appears exactly once and 9 and 11 does not appear in nums.
- 8 is a lonely number since it appears exactly once and 7 and 9 does not appear in nums.
- 5 is not a lonely number since 6 appears in nums and vice versa.
Hence, the lonely numbers in nums are [10, 8].
Note that [8, 10] may also be returned.
Example 2:

Input: nums = [1,3,5,3]
Output: [1,5]
Explanation: 
- 1 is a lonely number since it appears exactly once and 0 and 2 does not appear in nums.
- 5 is a lonely number since it appears exactly once and 4 and 6 does not appear in nums.
- 3 is not a lonely number since it appears twice.
Hence, the lonely numbers in nums are [1, 5].
Note that [5, 1] may also be returned.
	
	
	vector<int> findLonely(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1 && mp.find(nums[i]-1)==mp.end() && 
               mp.find(nums[i]+1)==mp.end()){
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};


