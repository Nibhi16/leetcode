class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Step 1: find the kth node from prevGroupEnd
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k; ++i) {
                kth = kth->next;
                if (!kth) return dummy.next; // less than k nodes left
            }

            // Step 2: reverse k nodes
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            while (curr != nextGroupStart) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Step 3: connect previous group to reversed group
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart; // new end of this group
        }

        return dummy.next;
    }
};
