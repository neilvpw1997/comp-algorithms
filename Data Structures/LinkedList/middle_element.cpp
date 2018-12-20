#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 //for finding floor(l/2)
 ListNode* middle(ListNode* A){
    if (A == NULL || A->next == NULL){
        return A;
    }
    ListNode* head = A, *fp = head, *sp = head, *psp = head;
    while(fp != NULL && fp->next != NULL){
        psp = sp;
        sp = sp->next;
        fp = fp->next->next;
    }
    if (fp == NULL){
        return psp;
    }
    if (fp->next == NULL){
        return sp;
    }
} 

//for finding ceil(l/2)
ListNode* middle(ListNode* A){
    if (A == NULL || A->next == NULL){
        return A;
    }
    ListNode* head = A, *fp = head, *sp = head;
    while(fp != NULL && fp->next != NULL){
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp;
} 
