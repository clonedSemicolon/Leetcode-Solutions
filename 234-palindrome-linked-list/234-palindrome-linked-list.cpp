class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        string res = "";
        while(node!=NULL)
        {
            res += to_string(node->val);
            node = node->next;
        }
        
        string ps = res;
        reverse(ps.begin(),ps.end());
        return ps == res;
            
    }
};