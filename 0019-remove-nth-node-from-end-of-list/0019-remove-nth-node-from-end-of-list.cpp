/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *leader = &dummy, *follower = &dummy;
        for(int i = 0; i < n; i++){
            leader = leader->next;
        }
        while(leader->next){
            leader = leader->next;
            follower = follower->next;
        }
        follower->next = follower->next->next;
        
        return dummy.next;
    }
};