class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        int val = nums[0];
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(int i = 0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                val = nums[i];
                break;
            }
        }
        
        return val;
    }
};