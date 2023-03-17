#include <iostream>

int main() {

Example 1:

Input: x = 4
Output: 2

  
 long long l=1,h=x,ans=0,mid,sq;
    while(l<=h)
    {
        mid=(l+h)/2;
        sq=mid*mid;
        if(sq==x)
            return mid;
        else if(sq>x)
            h=mid-1;
        else
        {
            l=mid+1;
            ans=mid;
        }
    }
    return ans;
}
}

 bool isPerfectSquare(int num) {
        bool b=false;
        long long l=0,h=num,sq=0;
        while(l<=h){
            long long mid=(l+h)/2;
            sq=mid*mid;
            if(sq==num){
                b=true;
                return b;
            }
            else if(sq>num)
                h=mid-1;
            else
                l=mid+1;
        }
        return b;
    }
};




Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1
Example 3:

Input: arr = [0,10,5,2]
Output: 1



int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int h=arr.size()-1;
        int mid= l + (h-l)/2;
        while(l<h){
            if(arr[mid]<arr[mid+1]){
                l=mid+1;
            }
            else{
                h=mid;
            }
            mid= l + (h-l)/2;
        }
        return l;
    }



Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1



int firstBadVersion(int n) {
        int l=1;
        int h=n;
        int mid=l+(h-l)/2;
        int ans=n;
        while(l<=h){
            if(isBadVersion(mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
           mid=l+(h-l)/2;
        }
        return ans;
    }




Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.



nt specialArray(vector<int>& nums) {
        int i=1, j=nums.size();
		while(i<=j){
			int mid=i+(j-i)/2, cnt=0;
			for(int k=0; k<nums.size(); k++){
				if(nums[k]>=mid){cnt++;}
			}
			if(cnt==mid){return mid;}
			else if(cnt<mid){j=mid-1;}
			else{i=mid+1;}
		}
		return -1;
	}

1011. Capacity To Ship Packages Within D Days

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
	
	 bool canShip(vector<int>& weights,int days,int maxCapacity){
          int currentDay=1,currentCapacity=0;
          for(int weight:weights){
              if(weight > maxCapacity) return false;
              if(weight+currentCapacity > maxCapacity){
                  currentDay += 1;
                  if(currentDay > days) return false;
                  currentCapacity=weight;
              }
              else{
                  currentCapacity += weight;
              }
          }
          return true;
      }

    int shipWithinDays(vector<int>& weights, int days) {
        int capacity=0,maxWeight=0,sumWeight=0;
        for(int weight:weights){
            maxWeight=max(maxWeight,weight);
            sumWeight += weight;
        }
        int start=maxWeight,end=sumWeight;
        while(start<=end){
            int mid=start + (end-start)/2;
            if(canShip(weights,days,mid)){
                capacity=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return capacity;
    }
};

