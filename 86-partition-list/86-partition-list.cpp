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
    ListNode* partition(ListNode* head, int x) {
        ListNode *pt1 = NULL, *pt2 = NULL, *temp1 = head , *temp2 = head, *temp = head;
        
        while(temp != NULL){
            if(temp->val < x){
                if(pt1 == NULL){
                    temp1 = temp;
                    pt1 = temp;
                    temp = temp->next;
                }
                else{
                    pt1->next = temp;
                    pt1 = temp;
                    temp = temp->next;
                }
            }
            else{
                if(pt2 == NULL){
                    temp2 = temp;
                    pt2 = temp;
                    temp = temp->next;
                }
                else{
                    pt2->next = temp;
                    pt2 = temp;
                    temp = temp->next;
                }
            }
        }
        
        //pt1->next = temp2;
        if(pt1 == NULL || pt2 == NULL){
            return head;
        }
        
        if(pt2->next != NULL){
            pt2->next = NULL;
        }
        pt1->next = temp2;
        
        return temp1;
    }
};