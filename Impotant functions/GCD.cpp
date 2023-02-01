#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--){
	    int n, m;
	    cin >> n >> m;
	    int g = __gcd(n, m);
	    cout << (n / g) * (m / g) << endl;
	}
	return 0;
}




Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
Example 2:

Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
Example 3:

Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.






gdc of array

int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first = nums[0];
        int last = nums[nums.size()-1];
        int ans=1, i;
        for (i=2; i<=first; i++){
            if(first%i==0 && last%i==0){
                ans=i;
            }
        }
        
        return ans;
    }



using gcd function




int findGCD(vector<int>& nums) {
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
             ans=__gcd(nums[0],nums[n-1]);
        }
        return ans;
}



Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""


 string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1)
            return "";
        return (str1.substr(0,gcd(str1.size(),str2.size())));
    }


