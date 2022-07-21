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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> s;
        ListNode* temp = head;
        int i = 1;
        while(i < left){
            temp = temp->next;
            i++;
        }
        ListNode* temp1 = temp;
        
        for(i = left; i <= right; i++){
            s.push(temp1->val);
            temp1 = temp1->next;
        }
        
        for(i = left; i <= right; i++){
            temp->val = s.top();
            temp = temp->next;
            s.pop();
        }
        
        return head;
    }
};