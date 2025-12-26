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
        // 2 pass solution
        ListNode *temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        if(n == count) {
            head = head->next;
            return head;
        }
        int currCount = 1;
        temp = head;
        while(currCount < count - n){
            temp = temp->next; currCount++;
        }
        ListNode *prevNode = temp, *nextNode = temp->next? temp->next->next: nullptr;
        prevNode->next = nextNode;
        return head;
    }
};