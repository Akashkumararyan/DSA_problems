#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size(),m=nums2.size();
        set<int> s;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]>nums2[j]) j++;
            else if(nums1[i]<nums2[j]) i++;
            else{
                s.insert(nums1[i]);
                i++;
                j++;
            }
        }
        vector<int> v;
        for(auto it:s){
            v.push_back(it);
        }
        return v;
    }


Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size(),m=nums2.size();
        vector<int> v;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]>nums2[j]) j++;
            else if(nums1[i]<nums2[j]) i++;
            else{
                v.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return v;
    }
};
