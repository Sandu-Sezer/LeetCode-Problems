#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* addNode(int x){
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode -> val = x;
    newNode -> next = NULL;

    return newNode;
}

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    if (head == NULL){
        return NULL;
    }
    
    int nrElem = 0;
    struct ListNode* aux = head;

    while (aux != NULL){
        nrElem++;
        aux = aux -> next;    
    }

    int* array = (int*) malloc(sizeof(int) * nrElem);

    aux = head;

    for (int i = 0; i < nrElem; i++){
        array[i] = aux -> val;
        aux = aux -> next;
    }

    int nrElemToGo = 0;

    for (int i = 0; i < nrElem; i++){
        int s = 0;
        for(int j = i; j < nrElem; j++){
            s += array[j];
            if (s == 0){
                nrElemToGo += j - i + 1;
                break;
            }
        }
    }

    int nrElemFinal = nrElem - nrElemToGo;
    int* newArray = (int*) malloc(sizeof(int) * nrElemFinal);
    int index = 0;

    for (int i = 0; i < nrElem; i++){
        int s = 0;
        for (int j = i; j < nrElem; j++){
            s += array[j];
            if (s != 0){
                newArray[index++] = array[i];
            } else {
                i = j;
                break;
            }
        }
    }

    struct ListNode* head2 = NULL;
    struct ListNode* aux2 = NULL;

    for (int i = 0; i < nrElemFinal; i++){
        struct ListNode* newNode = addNode(newArray[i]);
        if (head2 == NULL){
            head2 = newNode;
            aux2 = head2;
        } else {
            aux2 -> next = newNode;
            aux2 = aux2 -> next;
        }
    }
    free(array);
    free(newArray);

    return head2;
}