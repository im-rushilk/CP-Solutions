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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* curr = head;
        int len = 0;

        while(curr != NULL) {
            len++;
            curr = curr->next;
        }

        vector<int> v1(len, 0);

        if(len < 3) {
            return {-1, -1};
        }

        ListNode* temp = head->next;
        ListNode* pvs = head;

        int i = 1;

        while(temp->next != NULL) {

            ListNode* forward = temp->next;

            if(temp->val > pvs->val && temp->val > forward->val) {
                v1[i] = 1;
            }

            else if(temp->val < pvs->val && temp->val < forward->val) {
                v1[i] = 1;
            }

            pvs = temp;
            temp = forward;
            i++;
        }

        int first = -1;
        int last = -1;
        int mini = INT_MAX;

        for(int j = 0; j < len; j++) {

            if(v1[j] == 1) {

                if(first == -1) {
                    first = j;
                    last = j;
                }

                else {
                    mini = min(mini, j - last);
                    last = j;
                }
            }
        }

        if(first == last) {
            return {-1, -1};
        }

        return {mini, last - first};
    }
};