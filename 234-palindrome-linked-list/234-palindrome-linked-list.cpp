class Solution {
public:
    
    bool palindromicVector(vector<int>&v){
        int s = 0;
        int e = v.size()-1;
        while(s<=e){
            if (v[s]!=v[e]){
                return false;
            }
            s++;
            e--;
        }
        
        return true;
    }
    
    
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        vector<int>v;
        while(node!=NULL)
        {
            v.push_back(node->val);
            node = node->next;
        }
        
        return palindromicVector(v);
            
    }
};