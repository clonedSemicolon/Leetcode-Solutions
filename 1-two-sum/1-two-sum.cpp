class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        map<int,bool>bmp;
        vector<int>pos;
        
        
        for(int i = 0;i<nums.size();i++){
            bmp[nums[i]] = 1;
            mp[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(bmp[target-val] && i!=mp[target-val]){
                pos.push_back(i);
                pos.push_back(mp[target-val]);
                break;
            }
        }
        
        return pos;
    }
};