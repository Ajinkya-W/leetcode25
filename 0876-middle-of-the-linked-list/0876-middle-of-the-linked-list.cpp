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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head, *temp1 = head;
        int count = 0, currCounter = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        count /=2;
        while(currCounter!=count){
            cout<<temp1->val;
            currCounter++;
            temp1 = temp1->next;
        }
        return temp1;
    }
};