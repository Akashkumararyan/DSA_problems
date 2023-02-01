#include <bits/stdc++.h>
using namespace std;

int main() {

   // Concept of pair
  
  pair<int,string> p;
  p=make_pair(5,"akash");
  p={5,"aryan"};
  cout<<p.first<<" "<<p.second;*/

  //relation between two array
  int A[]={1,2,3};
  int B[]={4,5,6};
  pair<int,int> s[3];
  s[0]={1,4};
  s[1]={2,5};
  s[2]={3,6};
  swap(s[0],s[2]);
  for(int i=0;i<3;i++){
    cout<<s[i].first<<" "<<s[i].second<<endl;
  }

  pair<int,pair<int,int>> p={1,{2,3}};
  cout<<p.first<<" "<<p.second.first<<" "<<p.second.second;

  pair<int,int> A[]={{1,2},{3,4},{5,6}};
  cout<<A[1].second;*/

   // Concept of vector

  vector<int> v;
  v.push_back(1);
  v.emplace_back(2);
  v.emplace_back(4);
  v.emplace_back(5);

  //Removing elements from vector

  v.erase(v.begin());  // 2 4 5
  v.erase(v.begin()+1);  //2 5

  //1 2 4 5
  v.erase(v.begin()+1,v.begin()+2);   // 1 4 5
  */

// Insert function

  v.insert(v.begin(),7);  // 7 1 2 4 5
  v.insert(v.begin()+2,2,10);  // 7 1 10 10 2 4 5

  v.pop_back();  // 7 1 10 10 2 4
  */

 // Concept of List 

  list<int> ls;
  ls.push_back(1);
  ls.push_back(2);
  ls.push_back(3);
  ls.push_back(4);

  ls.push_front(0);

for(auto it:ls)
  cout<<it<<" ";*/

  // Concept of deque

  deque<int> dq;
  dq.push_back(1);
  dq.push_back(2);
  dq.push_back(3);
  dq.push_back(4);

  dq.push_front(0);

for(auto it:dq)
  cout<<it<<" ";
  
 // for(vector<int>:: iterator it=v.begin();it!=v.end();it++)
   // cout<<*(it)<<" ";

  //for(auto it=v.begin();it!=v.end();it++)
    //cout<<*(it)<<" ";

  /*for(auto it: v)
    cout<<it<<" ";*/

  vector<pair<int,int>> vec;
  vec.push_back({1,2});
  vec.emplace_back(3,4);

  
  
}




Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.






 vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        vector<pair<int,string>> v;
        vector<string> s;
        int n=names.size();
        for(int i=0;i<n;i++){
            v.push_back(make_pair(h[i],names[i]));
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
            s.push_back(v[i].second);
        }
        return s;
    }




map string problem


 unordered_map<char,int> mp;
    int ans = 0;
    
    for(int i=0;i<allowed.size();i++)
    {
        mp[allowed[i]]++;
    }
    int flag = true;
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words[i].size();j++)
        {   
        if(mp.find(words[i][j])==mp.end()){
            flag = false;
            break;
        }
            
                
                
        }
        if(flag==true)
            ans++;
        flag=true;
        
    }
    return ans;
