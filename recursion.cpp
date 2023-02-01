#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).


  bool isPowerOfThree(int n) {
        if(n<1) return false;
        if(n%3==0){
            return isPowerOfThree(n/3);
        }
        return n==1;
    }


Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.int fib(int n) {

  
       if(n<=1) return n;
       int ans=fib(n-2)+fib(n-1);
       return ans; 
    }


Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


recursive approch

bool checkPowersOfThree(int n) {
        for(int i=15;i>=0;i--){
            int x=pow(3,i);
            if(x<=n)
            n -= x;
            if(n==0) return true;
        }
        return false;
    }

other apporch tle maintain

int climbStairs(int n) {
        if(n<=2) return n;
        int ans=2,ans1=1,res;
        for(int i=3;i<=n;i++){
            res=ans+ans1;
            ans1=ans;
            ans=res;
        }
        return res;
    }

   // Subset-1
xample 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]



 private:
    void solve(vector<int> nums, vector<int> op,int i,vector<vector<int>> &ans){
       if(i>=nums.size()){
           ans.push_back(op);
           return;
       }
       solve(nums,op,i+1,ans);

       int res=nums[i];
       op.push_back(res);
       solve(nums,op,i+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        int i=0;
        solve(nums,op,i,ans);
        return ans;
    }


Subset -2

  Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


void func(int ind,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            func(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        func(0,nums,ds,ans);
        return ans;
    }
