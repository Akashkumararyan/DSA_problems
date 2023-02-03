#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

700. Search in a Binary Search Tree

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []

  TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val !=val){
            if(val<root->val) root=root->left;
            else root=root->right;
        }
        return root;
    }

701. Insert into a Binary Search Tree

Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]


   TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==NULL)return new TreeNode(val);
        TreeNode* curr= root;
        while (true){
            if (curr->val > val){
                if(curr->left)curr= curr->left;
                else{
                    curr->left= new TreeNode(val);
                    break;
                }
                
            }
            else{
                if(curr->right)curr= curr->right;
                else{
                    curr->right= new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

450. Delete Node in a BST

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []

  TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return solve(root);
        TreeNode* dammy=root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val==key){
                    root->left=solve(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val==key){
                    root->right=solve(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dammy;
    }

    TreeNode* solve(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        
        TreeNode* rc=root->right;
        TreeNode* lr=findr(root->left);
        lr->right=rc;
        return root->left;
    }

    TreeNode* findr(TreeNode* root){
        if(root->right==NULL) return root;
        return findr(root->right);
    }
};


230. Kth Smallest Element in a BST

Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

void solve(TreeNode* root,vector<int> &v){
           if(root==NULL) return;
           solve(root->left,v);
           v.push_back(root->val);
           solve(root->right,v);
       }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        int ans=0;
        solve(root,v);
        
        for(int i=0;i<v.size();i++){
           if(i==k-1)
             ans=v[i];
        }
        return ans;
    }


98. Validate Binary Search Tree

Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

void solve(TreeNode* root,vector<int> &v){
           if(root==NULL) return;
           solve(root->left,v);
           v.push_back(root->val);
           solve(root->right,v);
      }
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int> v;
        solve(root,v);
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1] <= v[i])
            return false;
        }
        return true;
    }

173. Binary Search Tree Iterator

Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


class BSTIterator {
    private: stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    private:
     void pushAll(TreeNode* node){
         for(; node!=NULL;st.push(node),node=node->left);
     }
};

167. Two Sum II - Input Array Is Sorted

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

  vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        vector <int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i+1);
            }
            mp[nums[i]] = i+1;
        }
        return ans;
    }

938. Range Sum of BST

Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

   void solve(TreeNode* root,vector<int> &v){
           if(root==NULL) return;
           solve(root->left,v);
           v.push_back(root->val);
           solve(root->right,v);
       }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> v;
        int sum=0;
        solve(root,v);
        vector<pair<int, int>> vp;
        for(int i= 0; i<v.size(); i++) {
            vp.push_back({i, v[i]});
            // vp.push_back(make_pair(i, v[i]));
        }
        int l =0, h=0;
        for(int i =0; i<vp.size(); i++){
            if(vp[i].second == low) l = i;
            else if(vp[i].second == high) h =i;
        }

        for(int i =l; i<= h; i++){
            sum += vp[i].second;
        }
        // cout<< l <<" "<<h;
        // for(auto i : vp) cout<< i.second<<" ";
        return sum;
    }


      897. Increasing Order Search Tree

Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]

  TreeNode* head=new TreeNode(0);
       TreeNode* ptr=head;

      void solve(TreeNode* root){
          if(root==NULL) return;
          solve(root->left);
          head->right=new TreeNode(root->val);
          head=head->right;
          solve(root->right);
      } 
public:
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        return ptr->right;
    }

108. Convert Sorted Array to Binary Search Tree

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

  TreeNode* solve(int l,int h,vector<int> &nums){
          if(l==h) return (new TreeNode(nums[l]));
          if(l>h) return NULL;

          int mid=l + (h-l)/2;
          TreeNode* ptr=new TreeNode(nums[mid]);
          ptr->left=solve(l,mid-1,nums);
          ptr->right=solve(mid+1,h,nums);
          return ptr;
      }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        return solve(l,h,nums);
    }

1038. Binary Search Tree to Greater Sum Tree

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]

  int sum=0;
      void solve(TreeNode* root){
          if(root==NULL) return;
          solve(root->right);
          root->val += sum;
          sum=root->val;
          solve(root->left);
          return;
      }
public:
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }



   669. Trim a Binary Search Tree
   
   Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
Example 2:


Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]

 TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }

    TreeNode* solve(TreeNode* root,int low,int high){
        if(root==NULL) return NULL;
        TreeNode* l=solve(root->left,low,high);
        if(l != root->left){
            root->left=l;
        }
        TreeNode* r=solve(root->right,low,high);
         if(r != root->right){
            root->right=r;
        }
        if(root->val>high || root->val<low){
            return (root->left)?root->left:root->right;
        }
        return root;
    }
};


96. Unique Binary Search Trees

Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
  
   int catalan_number(int n){
        int catalan[n+1];
        catalan[0]=catalan[1]=1;
        for(int i=2;i<=n;i++){
            catalan[i]=0;
            for(int j=0;j<i;j++){
                catalan[i] += catalan[j]*catalan[i-j-1];
            }
        }
         return catalan[n];
    }
public:
    int numTrees(int n) {
        return catalan_number(n);
    }

//recursion method

 int numTrees(int n) {
        if(n<=1) return 1;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans += numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }

