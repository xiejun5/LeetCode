/*************************************************************************
	> File Name: LeetCode203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 16时40分36秒
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p = &ret, *q;
    ret.next = head;
    while (p && p->next) {
        if (p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return ret.next;
}
