#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}

234. Palindrome Linked List

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false


ListNode* reverseList(ListNode* head){
        ListNode *t=NULL;
        while(head){
            ListNode *next=head->next;
            head->next=t;
            t=head;
            head=next;
        }
        return t;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return true;

        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next != NULL && fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow->next=reverseList(slow->next);
        slow=slow->next;

        while(slow != NULL){
            if(head->val != slow->val)
             return false;
             head=head->next;
             slow=slow->next;
        }
        return true;
    }


19. Remove Nth Node From End of List

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *s=new ListNode();
        s->next=head;
        ListNode *fast=s;
        ListNode *slow=s;
        
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        
        return s->next;
    }



206. Reverse Linked List

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:
Input: head = [1,2]
Output: [2,1]
Example 3:
Input: head = []
Output: []


  ListNode* reverseList(ListNode* head) {
        ListNode *q=NULL;
        while(head){
            ListNode *next=head->next;
            head->next=q;
            q=head;
            head=next;
        }
        return q;
    }


876. Middle of the Linked List


Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


  ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }


21. Merge Two Sorted Lists


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if(list1==NULL){
          return list2;
      }
      if(list2==NULL){
          return list1;
      }
        ListNode* ptr=list1;
        if(list1->val>list2->val){
            ptr=list2;
            list2=list2->next;
        }
        else{
            list1=list1->next;
        }
        ListNode* curr=ptr;
        while(list1 && list2){
            if(list1->val<list2->val){
                curr->next=list1;
                list1=list1->next;
            }
            else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }
         if(!list1)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;   
    }


237. Delete Node in a Linked List

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:


Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.



  void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }


2. Add Two Numbers

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode();
        ListNode *temp=dummy;
        int carry=0;
        while(l1 != NULL || l2 != NULL || carry){
            int sum=0;
            if(l1 != NULL){
                sum += l1->val;
                l1=l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2=l2->next;
            }
            sum += carry;
            carry=sum/10;
            ListNode *node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }



203. Remove Linked List Elements

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []



  ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp_head=new ListNode(0);
        temp_head->next=head;
        ListNode *t=temp_head;
        while(t){
            if(t->next && t->next->val==val) t->next=t->next->next;
            else t=t->next;
        } 
        return temp_head->next;
    }


160. Intersection of Two Linked Lists

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.




  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b){
            if(a==NULL)
              a=headB;
              else 
              a=a->next;
              
           if(b==NULL)
             b=headA;
             else
             b=b->next;   
        }
        return a;
    }




141. Linked List Cycle

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


   bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            return true;
        }
        return false;
    }


142. Linked List Cycle II

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.





ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *temp=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                while(slow != temp){
                slow=slow->next;
                temp=temp->next;
                }
                return temp;
            }
            
        }
        return NULL;
    }


61. Rotate List


Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]


  ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode *cur=head;
        int len=1;
        while(cur->next && ++len){
            cur=cur->next;
        }
        cur->next=head;
        k=k%len;
        k=len-k;
        while(k--){
            cur=cur->next;
        }
        head=cur->next;
        cur->next=NULL;

        return head;
    }


189. Rotate Array


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]



   void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        for(int i=0;i<nums.size();i++){
            v[(i+k)%nums.size()]=nums[i];
        }
        nums=v;
    }



1290. Convert Binary Number in a Linked List to Integer


Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0


  int getDecimalValue(ListNode* head) {
        ListNode *temp=NULL;
        while(head){
            ListNode *next=head->next;
            head->next=temp;
            temp=head;
            head=next;
        }
        int res=0;
        int i=0;
        while(temp){
            res+=pow(2,i)*temp->val;
            temp=temp->next;
            i++;
        }
        return res;
    }





2095. Delete the Middle Node of a Linked List

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.


   ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode *t=head;
       while(t){
           if(t->next==slow){
               t->next=slow->next;
           }
           t=t->next;
       }
         
         return head;
    }


1721. Swapping Nodes in a Linked List



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]



  ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *temp2=head;
        int cnt=0;
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
            cnt++;
        }

        swap(k-1,cnt-k,v);
        int i=0;
        while(temp2){
            temp2->val=v[i];
            i++;
            temp2=temp2->next;
        }
        return head;
    }



82. Remove Duplicates from Sorted List II


Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]


  ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *res=new ListNode(0);
        res->next=head;
        ListNode *temp=res;

        while(temp->next && temp->next->next){
            if(temp->next->val==temp->next->next->val){
                int ans=temp->next->val;
                while(temp->next != NULL && temp->next->val==ans)
                    temp->next=temp->next->next; 
            }
            else temp=temp->next;
        }
        return res->next;

    }




48. Sort List
Medium
8.9K
271
Companies
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []



  ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<int> v;
        ListNode *temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head;
        for(int i=0;i<v.size();i++){
            temp->val=v.at(i);
            temp=temp->next;
        }
        return head;
    }
