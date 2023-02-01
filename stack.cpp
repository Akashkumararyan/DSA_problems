#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}


Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


  first solution

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                int mx=-1;
                for(int k=j;k<nums2.size();k++){
                    if(nums2[k]>nums2[j]){
                        mx=nums2[k];
                        break;
                    }
                        
                }
                v.push_back(mx);
                }
            }
        }
        return v;
    }



225. Implement Stack using Queues



Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False


class MyStack {
public:
	queue<int> q;
	/** Initialize your data structure here. */
	MyStack() {}

	/** Push element x onto stack. */
	void push(int x) {
		int n=q.size();
		q.push(x);
		while(n>0) {
			q.push(q.front());
			q.pop();
			n--;
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int n=q.front();
		q.pop();
		return n;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if(q.empty()) return true;
		return false;
	}
};



503. Next Greater Element II

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

  vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,-1);
        stack<int> st;

        for(int i=0;i<n*2;i++){
            while(!st.empty() && nums[st.top()] < nums[i%n]){
                v[st.top()]=nums[i%n];
                st.pop();
            }
            if(i<n) st.push(i);
        }
        return v;
    }


239. Sliding Window Maximum

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]


  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i])
              dq.pop_back();

           dq.push_back(i);
           if(i>=k-1) v.push_back(nums[dq.front()]);   
        }
        return v;
    }


682. Baseball Game

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.



int calPoints(vector<string>& op) {
        if(op.empty()) return 0;
        stack<int> st;
        int ans=0;
        for(int i=0;i<op.size();i++){
            if(op[i]=="C"){
                ans -= st.top();
                st.pop();
            }
            else if(op[i]=="D"){
                st.push(st.top()*2);
                ans += st.top();
            }
            else if(op[i]=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);

                ans += x+y;
                st.push(x+y);
            }
            else{
                int n=stoi(op[i]);
                ans += n;
                st.push(n);
            }
        }
        return ans;
    }


844. Backspace String Compare

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".


  bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> st1;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]=='#'){
                st.pop();
            }
            if(s[i] != '#')
              st.push(s[i]);
        }

         for(int i=0;i<t.size();i++){
            if(!st1.empty() && t[i]=='#'){
                st1.pop();
            }
            if(t[i] != '#')
              st1.push(t[i]);
        }
        if(st==st1) return true;
        return false;
    }


1475. Final Prices With a Special Discount in a Shop

Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]


  vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(prices.size());
        for(int i=prices.size()-1;i>=0;i--){
            int curr=prices[i];
            while(st.top() > curr) st.pop();
            if(st.top()==-1) ans[i]=prices[i];
            else ans[i]=prices[i]-st.top();
            st.push(curr);
        }
        return ans;
    }


1047. Remove All Adjacent Duplicates In String

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"


  string removeDuplicates(string s) {
        stack<char> st;
        int n=s.size();
        string sd="";
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()==s[i])
              st.pop();
             else{
                 st.push(s[i]);
             }
        }

        while(!st.empty()){
             sd += st.top();
             st.pop();
         }    
        reverse(sd.begin(),sd.end());
        
        return sd;
    }


1614. Maximum Nesting Depth of the Parentheses

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.
Example 2:

Input: s = "(1)+((2))+(((3)))"
Output: 3

int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                int temp=st.size();
                ans=max(ans,temp);
            }
              
            else if(s[i]==')'){
                st.pop();
            }  
        }
       // if(st.size()>0) return -1;
        return ans;
    }


921. Minimum Add to Make Parentheses Valid

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3

int minAddToMakeValid(string s) {
       stack<char> st;
       int cnt=0;
       for(int i=0;i<s.size();i++){
           if(!st.empty() && st.top()=='(' && s[i]==')'){
             st.pop();
             cnt--;
           }
             
           else if(s[i]=='(' || s[i]==')'){
               st.push(s[i]);
               cnt++;
           }  
       } 
       return cnt;
    }
};


1111. Maximum Nesting Depth of Two Valid Parentheses Strings

Example 1:

Input: seq = "(()())"
Output: [0,1,1,1,1,0]
Example 2:

Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]


  vector<int> maxDepthAfterSplit(string seq) {
        int ans = -1;
        vector<int> v;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                ans++;
                v.push_back(ans%2);
            }
            else if(seq[i]==')'){
                v.push_back(ans%2);
                ans--;
            }
        }
        return v;
    }
};


