#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 //return the reverse of list A with NULL parameters appropriately set
 ListNode* reverse(ListNode* A){
    if (A == NULL || A->next == NULL){
        return A;
    }
    ListNode* head = A, *prev = NULL, *nxt = A->next;
    while(head != NULL){
        if (nxt != NULL){
            head->next = prev;
            prev = head;
            head = nxt;
            nxt = nxt->next;
        }
        else {
            head->next = prev;
            break;
        }
    }
    return head;
}
