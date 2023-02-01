#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

Example 1:

Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.
Example 2:

Input: nums = [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2] with length 1. Note that it must be strictly
increasing.


  int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cnt=1;
        int mx=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                cnt++;
             if(cnt>mx){
               mx=cnt;
             }
            }
            else
             cnt=1;
        }
        return mx;
    }


 bool isSubsequence(string s, string t) {
        int j=0;
        int n=s.size();
        int m=t.size();
        for(int i=0;i<m && j<n;i++){
          if(s[j]==t[i])
             j++;
        }
        
        
        if(j==n) return true;
        else return false;
    }


// Recursive solution

bool isSub(string &s,string &t,int n,int m){
         if(n==0) return true;
         if(m==0) return false;

         if(s[n-1]==t[m-1]){
             return isSub(s,t,n-1,m-1);
         }
         else{
             return isSub(s,t,n,m-1);
         }
     }

    bool isSubsequence(string s, string t) {
        if(isSub(s,t,s.size(),t.size()))
           return true;
           else
           return false;
    }



//Combinations 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []




void findC(int i,int target,vector<int> A,vector<int> ds, vector<vector<int>> &ans){
        if(i==A.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(A[i]<=target){
            ds.push_back(A[i]);
            findC(i,target-A[i],A,ds,ans);
            ds.pop_back();
        }

        findC(i+1,target,A,ds,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findC(0,target,candidates,ds,ans);
        return ans;
    }



//combination 2


Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]



   void findC(int i,int target,vector<int> A,vector<int> 
              ds,vector<vector<int>> &ans){
            if(target==0){
                ans.push_back(ds);
                return;
            }
        for(int in=i;in<A.size();in++){
            if(in>i && A[in]==A[in-1]) continue;
            if(A[in]>target) break;
            ds.push_back(A[in]);
            findC(in+1,target-A[in],A,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findC(0,target,candidates,ds,ans);
        return ans;
    }


863. Sum of All Subset XOR Totals

Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
Example 2:

Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
Example 3:

Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.



int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n = nums.size(), p = 1 << n;
        for (int i = 0; i < p; i++) {
            int xr=0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    xr = xr ^ nums[j];
                    
                }
                
            }
            ans += xr;
        }
        return ans;
    }



Subset Sums


Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8




public:
    void func(int ind,int sum,vector<int> arr,int N,vector<int> &ans){
        if(ind==N){
            ans.push_back(sum);
            return;
        }
        func(ind+1,sum+arr[ind],arr,N,ans);
        func(ind+1,sum,arr,N,ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        func(0,0,arr,N,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
