#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

xample 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
Example 2:

Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.



int minBitFlips(int start, int goal) {
        int ans= start ^ goal;
        int cnt =0;
    for(int i =0; i<31; i++){
        if((ans&(1<<i)) != 0){
            cnt++;
        }
    }
    return cnt;
    }


int minBitFlips(int start, int goal) {
        int ans= start ^ goal;
        return __builtin_popcount(ans);
    }


int minBitFlips(int start, int goal) {
        int ans=0;
        while(start || goal){
            if(start%2 != goal%2)
            ans++;
            start /=2;
            goal /=2;
        }
        return ans;
    }



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101




  vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0;i<=n;i++){
            int sum=0;
            int num=i;
            while(num!=0){
                sum += num%2;
                num=num/2;
            }
            v.push_back(sum);
        }
        return v;
    }




 Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.




  nt findComplement(int num) {
       int ans1=1;
       vector<int> v;
       while(num!=0){
           v.push_back(num%2);
           num=num/2;
       }
       reverse(v.begin(),v.end());
       for(int i=0;i<v.size();i++){
           if(v[i]==0)
           v[i]=1;
           else
           v[i]=0;
       }
        for(int i=v.size()-1;i>0;i--){
            num=num + v[i] * ans1;
            ans1 = ans1 * 2;
        }
    return num;
    }




  int findComplement(int num) {
        int ans=0,i=0;
        while(num!=0){
            if((num & 1)==0)
            ans += 1<<i;

            i++;
            num=num>>1;
        }
        return ans;
    }


  Example 1:

Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
Example 2:

Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
Example 3:

Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]







  int countMaxOrSubsets(vector<int>& nums) {
        int mor=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mor |=nums[i];
        }
        int ans1=0;
        int total=pow(2,(int)nums.size());
        for(int i=0;i<total;i++){
            int ans1=0;

            for(int j=0;j<nums.size();j++){
            if(i & (1<<j)){
                ans1 |=nums[j];
            }
        }
         if(mor==ans1)
             ans++;
        }
        
        return ans;
    }




  Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]




  vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;
        int x=0;
        for(int i=0;i<nums.size();i++){
            x= x ^ nums[i];
        }
        int cnt=0;
        while(x){
            if(x & 1)
              break;

              cnt++;
              x=x>>1;
        }
        int x1=0,x2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & (1<<cnt))
              x1 = x1 ^ nums[i];
            else
              x2 = x2 ^ nums[i];
        }
        v.push_back(x1);
        v.push_back(x2);

        return v;
    }
