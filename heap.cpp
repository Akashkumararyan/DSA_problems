#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

Build Min Heap

void Heapify(vector<int> &arr,int n,int i){
    int sm=i;
    int li=2*i+1;
    int ri=2*i+2;
    if(li<n && arr[sm]>arr[li]){
        sm=li;
    }
    if(ri<n && arr[sm]>arr[ri]){
        sm=ri;
    }
    if(sm != i){
        swap(arr[sm],arr[i]);
        Heapify(arr,n,sm);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,n,i);
    }
    return arr;
}


912. Sort an Array

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.


  vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};


347. Top K Frequent Elements

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

  vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto x:mp){
            pq.push({x.second,x.first});
            if(pq.size()>k)
            pq.pop();
        }
        vector<int> v;
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }


Minimum Cost of ropes


xample 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Which makes the array {4, 5, 6}. Cost of
this operation 2+3 = 5. 
2) Now connect ropes of lengths 4 and 5.
Which makes the array {9, 6}. Cost of
this operation 4+5 = 9.
3) Finally connect the two ropes and all
ropes have connected. Cost of this 
operation 9+6 =15
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. 
Other ways of connecting ropes would always 
have same or more cost. For example, if we 
connect 4 and 6 first (we get three rope of 3,
2 and 10), then connect 10 and 3 (we get
two rope of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.
Example 2:

Input:
n = 5
arr[] = {4, 2, 7, 6, 9}
Output: 
62 
Explanation:
First, connect ropes 4 and 2, which makes
the array {6,7,6,9}. Cost of
this operation 4+2 = 6. Next, add ropes 
6 and 6, which results in {12,7,9}. 
Cost of this operation 6+6 = 12.
Then, add 7 and 9, which makes the array {12,16}. 
Cost of this operation 7+9 = 16. And
finally, add these two which gives {28}.
Hence, the total cost is 6 + 12 + 16 + 
28 = 62.

long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long cost=0;
        
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            
            long long sum=a+b;
            cost += sum;
            
            pq.push(sum);
            
        }
        return cost;
    }

