#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

Input: nums = [1,2,3,4,5]
Output: 8
Explanation:
The above diagram depicts the process from which we obtain the triangular sum of the array.
Example 2:

Input: nums = [5]
Output: 5
Explanation:
Since there is only one element in nums, the triangular sum is the value of that element itself.

  int triangularSum(vector<int>& nums) {
        int n=nums.size();
        while(n!=1){
            for(int i=0;i<n-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }


Input: nums = [1,3,5,2,4,8,2,2]
Output: 1
Explanation: The following arrays are the results of applying the algorithm repeatedly.
First: nums = [1,5,4,2]
Second: nums = [1,4]
Third: nums = [1]
1 is the last remaining number, so we return 1.
Example 2:

Input: nums = [3]
Output: 3
Explanation: 3 is already the last remaining number, so we return 3.



int minMaxGame(vector<int>& nums) {
       
        while(nums.size()!=1){
             vector<int> v;
             int flag=1;
            for(int i=0;i<nums.size();i=i+2){
                if(flag){
                    v.push_back(min(nums[i],nums[i+1]));
                    flag=0;
                }
                else{
                    v.push_back(max(nums[i],nums[i+1]));
                    flag=1;
                }
                
            }
            nums.clear();
            nums=v;
        
        }
        
        return nums[0];
    }





2470. Number of Subarrays With LCM Equal to K


Input: nums = [3,6,2,7,1], k = 6
Output: 4
Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
Example 2:

Input: nums = [3], k = 2
Output: 0
Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.


int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int temp = nums[i];
            for(int j = i; j<n; j++){

                temp = lcm(temp, nums[j]);  //gcd(temp,nums[j])
                if(temp == k){
                    ans++;
                }
                else if(temp>k){  // temp<k  for gcd
                    break;
                }
            }
        }
        return ans;
    }



914. X of a Kind in a Deck of Cards
Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.



  bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }


204. Count Primes

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0


int countPrimes(int n) {
        if (n<=2) return 0;
        int cnt=0;
        vector<bool> nums(n,true);
        nums[0]=nums[1]=false;
        for (int i=2; i<n; ++i)
            if (nums[i]){
                ++cnt;
                for (int j=2; i*j<n; ++j)
                    nums[i*j]=false;
            }
        return cnt;
    }


448. Find All Numbers Disappeared in an Array

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]


   vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int mark=abs(nums[i])-1;
            if(nums[mark]>0) nums[mark] *= -1; 
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) v.push_back(i+1);
        }
        return v;
    }


485. Max Consecutive Ones

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2

int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,i=0;
        while(i<nums.size()){
            int cnt=0;
            while(i<nums.size() && nums[i]==1){
                cnt++;
                i++;
            }
            if(cnt>mx)
                mx=cnt;
                
                i++;
            
        }
        return mx;
    }


605. Can Place Flowers

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

bool canPlaceFlowers(vector<int>& f, int n) {
        int i=0;
        while(i<f.size() && n>0){
            if(f[i]==1){
                i += 2;
            }
            else if(i+1==f.size() || f[i+1] != 1){
                n--;
                i += 2;
            }
            else 
             i++;
        }
        return n==0;
    }


7. Reverse Integer

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21

int reverse(int n) {
        bool neg = n<0;
        n=abs(n);
        
        int ans=0;
        int temp;
        while(n>0)
        {
            temp=n%10;
            if((double)INT_MAX/ans<=10.0)
                return 0;
            ans*=10;
            ans+=temp;
            n/=10;
        }
        
        if(!neg)
        return ans;
        return ans*-1; 
    }
};

1005. Maximize Sum Of Array After K Negations

Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
Example 2:

Input: nums = [3,-1,0,2], k = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
Example 3:

Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13
Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].

  int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0 && k>0){
                nums[i] = -nums[i];
                k--;
            }
        }
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int x= *min_element(nums.begin(),nums.end());
        if(k%2 !=0) sum -= 2*x;
        return sum;
    }
};


2210. Count Hills and Valleys in an Array

Input: nums = [2,4,1,1,6,5]
Output: 3
Explanation:
At index 0: There is no non-equal neighbor of 2 on the left, so index 0 is neither a hill nor a valley.
At index 1: The closest non-equal neighbors of 4 are 2 and 1. Since 4 > 2 and 4 > 1, index 1 is a hill. 
At index 2: The closest non-equal neighbors of 1 are 4 and 6. Since 1 < 4 and 1 < 6, index 2 is a valley.
At index 3: The closest non-equal neighbors of 1 are 4 and 6. Since 1 < 4 and 1 < 6, index 3 is a valley, but note that it is part of the same valley as index 2.
At index 4: The closest non-equal neighbors of 6 are 1 and 5. Since 6 > 1 and 6 > 5, index 4 is a hill.
At index 5: There is no non-equal neighbor of 5 on the right, so index 5 is neither a hill nor a valley. 
There are 3 hills and valleys so we return 3.
Example 2:

Input: nums = [6,6,5,5,4,1]
Output: 0
Explanation:
At index 0: There is no non-equal neighbor of 6 on the left, so index 0 is neither a hill nor a valley.
At index 1: There is no non-equal neighbor of 6 on the left, so index 1 is neither a hill nor a valley.
At index 2: The closest non-equal neighbors of 5 are 6 and 4. Since 5 < 6 and 5 > 4, index 2 is neither a hill nor a valley.
At index 3: The closest non-equal neighbors of 5 are 6 and 4. Since 5 < 6 and 5 > 4, index 3 is neither a hill nor a valley.
At index 4: The closest non-equal neighbors of 4 are 5 and 1. Since 4 < 5 and 4 > 1, index 4 is neither a hill nor a valley.
At index 5: There is no non-equal neighbor of 1 on the right, so index 5 is neither a hill nor a valley.
There are 0 hills and valleys so we return 0.



int countHillValley(vector<int>& nums) {
        int cnt=0;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1])
            v.push_back(nums[i]);
        }
        for(int i=1;i<v.size()-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1] || v[i]<v[i-1] && v[i]<v[i+1])
              cnt++;
        }
        return cnt;
    }


896. Monotonic Array

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false

bool isMonotonic(vector<int>& nums) {
        vector<int> v1=nums;
        vector<int> v2=nums;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int> ());
        if(v1==nums || v2==nums) return true;
        return false;
    }


2165. Smallest Value of the Rearranged Number

Input: num = 310
Output: 103
Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
The arrangement with the smallest value that does not contain any leading zeros is 103.
Example 2:

Input: num = -7605
Output: -7650
Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
The arrangement with the smallest value that does not contain any leading zeros is -7650.
  
  
  long long smallestNumber(long long num) {
        if(num<0){
           string s=to_string(-num);
           sort(s.rbegin(),s.rend());
           return -stoll(s); 
        }
        else if(num==0) return 0;
        
        string s=to_string(num);
        sort(s.begin(),s.end());
        int i=0;
        while(s[i]=='0')
          i++;
        char c = s[i];
          s.erase(s.begin() + i);
          s = c + s;
          
        return stoll(s);
    }
};
