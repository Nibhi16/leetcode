 //struct ListNode {
   //  int val;
     //ListNode *next;
    // ListNode(int x) : val(x), next(nullptr) {}
 
 //};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr =  head;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next= prev;
            prev= curr;
            curr=next;
        }
        return prev;
    }
};