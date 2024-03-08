bool hasCycle(struct ListNode *head) {
    if (head == NULL || head -> next == NULL){
        return false;
    }

    struct ListNode *pointer1 = head;
    struct ListNode *pointer2 = head -> next;

    while (pointer1 != pointer2){
        if (pointer1 == NULL || pointer1 -> next == NULL){
            return false;
        }
        if (pointer2 == NULL || pointer2 -> next == NULL){
            return false;
        }
        pointer1 = pointer1 -> next;
        pointer2 = pointer2 -> next -> next;
    }
    return true;
}