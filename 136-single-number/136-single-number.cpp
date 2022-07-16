class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int,int>mp;
        int val = nums[0];
        for(int i = 1;i<nums.size();i++){
            val ^= nums[i];
        }
        
        
        
        return val;
    }
};