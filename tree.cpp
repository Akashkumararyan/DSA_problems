#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

Inordere traversal problrm

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]


  void inorder(TreeNode* root,vector<int>& v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return v;
    }

using stack


 vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int> v;
        while(true){
            if(node != NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()==true) break;
                node=st.top();
                st.pop();
                v.push_back(node->val);
                node=node->right;
            }
        }
        return v;
    }






N-ary Tree Preorder Traversal

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]



   void preorder(Node* root,vector<int>& v){
        
        v.push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            preorder(root->children[i],v);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> v;
        if(root==NULL) return v;
        
        preorder(root,v);
        return v;
    }

using stack

 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            v.push_back(root->val);
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) st.push(root->left);
        }
        return v;
    }


postorder traversal using two stack

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL) st1.push(root->left);
            if(root->right != NULL) st1.push(root->right);
        }
        while(!st2.empty()){
            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;
    }
};



102. Binary Tree Level Order Traversal

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

  vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }


104. Maximum Depth of Binary Tree

Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2

   int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);

        return 1+max(l,r);
    }
};


110. Balanced Binary Tree

Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


  bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;

        int l=height(root->left);
        if(l==-1) return -1;
        int r=height(root->right);
        if(r==-1) return -1;
        
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);
    }


543. Diameter of Binary Tree

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1


  int diameterOfBinaryTree(TreeNode* root) {
        int dm=0;
        height(root,dm);
        return dm;
    }
    private:
    int height(TreeNode* node,int& dm){
        if(!node) return 0;

        int l=height(node->left,dm);
        int r=height(node->right,dm);
        dm=max(dm,l+r);

        return 1+max(l,r);

    }
};

100. Same Tree

Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false


  bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return(p==q);
        }
        return (p->val==q->val)
        && isSameTree(p->left,q->left)
        && isSameTree(p->right,q->right);

    }


103. Binary Tree Zigzag Level Order Traversal

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool b=true;

        while(!q.empty()){
            int n=q.size();
            vector<int> row(n);
            for(int i=0;i<n;i++){
             TreeNode* node=q.front();
             q.pop();

             int in=(b) ? i: (n-1-i);

             row[in]=node->val;
             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);
            }
            b = !b;
            ans.push_back(row);
        }
        return ans;
    }
};

199. Binary Tree Right Side View

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []

  vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root,0,v);
        return v;
    }
    public:
    void solve(TreeNode* root,int level,vector<int> &v){
        if(root==NULL) return;
        if(v.size()==level) v.push_back(root->val);
        solve(root->right,level+1,v);
        solve(root->left,level+1,v);
    }



236. Lowest Common Ancestor of a Binary Tree

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
          return root;

          TreeNode* left=lowestCommonAncestor(root->left,p,q);
          TreeNode* right=lowestCommonAncestor(root->right,p,q);

          if(left==NULL) return right;
          else if(right==NULL) return left;
          else{
              return root;
          }
    }0


  2331. Evaluate Boolean Binary Tree

Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
Example 2:

Input: root = [0]
Output: false
Explanation: The root node is a leaf node and it evaluates to false, so we return false.

  bool evaluateTree(TreeNode* root) {
        if(root->val==1 || root->val==0) 
        return root->val;

        bool left=evaluateTree(root->left);
        bool right=evaluateTree(root->right);

        if(root->val==3) 
        return left && right;
        else 
        return left || right;
        
    }


111. Minimum Depth of Binary Tree

Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

  int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(l==0) return 1+max(l,r);
        if(r==0) return 1+max(l,r);

        return 1+min(l,r);
    }


112. Path Sum

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.


  bool hasPathSum(TreeNode* root, int t) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return t==root->val;

        bool b=false;
        if(root->left) b=hasPathSum(root->left,t-root->val);
        if(root->right) b=b || hasPathSum(root->right,t-root->val);

        return b;
    }


226. Invert Binary Tree

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []


  void solve(TreeNode* node){
          if(node==NULL) return;

          solve(node->left);
          solve(node->right);

          TreeNode* temp;
          temp=node->left;
          node->left=node->right;
          node->right=temp;
      }
public:
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }

222. Count Complete Tree Nodes

Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1

  int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int l=leftmove(root);
        int r=rightmove(root);

        if(l==r) return (1<<l)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int leftmove(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }

    int rightmove(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }



