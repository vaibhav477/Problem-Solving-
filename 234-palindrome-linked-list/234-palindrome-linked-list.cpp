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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        
        stack<int> st;
        temp = head;
        int i =0;
        while(i < (length/2)){
            st.push(temp->val);
            temp = temp->next;
            i++;
        }
        if(length%2 != 0){
            temp = temp->next;
        }
        int flag = 1;
        while(temp != NULL){
            if(temp->val != st.top()){
                flag = 0;
                break;
            }
            temp = temp->next;
            st.pop();
        }
        
        if(flag){
            return true;
        }
        else{
            return false;
        }
    }
};