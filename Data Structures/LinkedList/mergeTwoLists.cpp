#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* head = l1;  
        l1 = l1->next;
        ListNode* p = head;     
        bool froml1 = false;

        while(l1 != NULL && l2 != NULL){
            if(froml1 == true) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
            froml1 = !froml1;
        }
        if (l1 != NULL) {
            p->next = l1;
        } else {
            p->next = l2;
        }
        return head;
    }
