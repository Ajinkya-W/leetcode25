/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode dummy;
    struct ListNode *curr = &dummy;
    int carry = 0;
    int sum;
    while(l1 != NULL || l2 != NULL) {

        sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry; 
        carry = sum/10;
        sum = sum%10;
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = sum;
        if(l1)
        l1 = l1->next;
        if(l2)
        l2 = l2->next;
    }
    
    if(carry == 1) {
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = 1;
    }
    curr->next = NULL;
    return dummy.next;
}