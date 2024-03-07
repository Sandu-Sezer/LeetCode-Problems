/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *firstPointer = head;
    struct ListNode *secondPointer = head;

    for (int i = 0; i < n; ++i){
        if (firstPointer == NULL){
            return head;
        }
        firstPointer = firstPointer -> next;
    }

    if (firstPointer == NULL){
        head = head -> next;
        return head;
    }

    while (firstPointer -> next != NULL){
        firstPointer = firstPointer -> next;
        secondPointer = secondPointer -> next;
    }

    struct ListNode* delete = secondPointer -> next;
    secondPointer -> next = delete -> next;
    free(delete); 

    return head;
}