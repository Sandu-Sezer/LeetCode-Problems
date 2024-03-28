/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* trecut = NULL;
    struct ListNode* current = head;

    while (current != NULL){
        struct ListNode* aux = current -> next;
        current -> next = trecut;
        trecut = current;
        current = aux;
    }

    return trecut;
}