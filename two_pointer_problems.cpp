#include <iostream>

int main() {
   bool findSubarrays(vector<int>& nums) {
        bool b=false;
        int n=nums.size();
        if(n<=2)
            return false;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                 if(nums[j]+nums[j+1]==nums[i]+nums[i+1])
                     b=true;
            }
        }
        return b;
    }
}



Example 1:

Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:

Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
Example 3:

Input: nums = [0,0,0]
Output: true
Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.



using map

 bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size()-1;i++){
            mp[nums[i]+nums[i+1]]++;
            
            if(mp[nums[i]+nums[i+1]]>=2)
                return true;
        }
        return false;
    }



sorting method



bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
      vector <int> ans;
        for(int i=0;i<n-1;i++){
            int x=nums[i]+nums[i+1];
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1])
                return true;
        }
        return false;
    }



Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size(),cnt=0,i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<n && j<m){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        return cnt;
    }
};



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};
