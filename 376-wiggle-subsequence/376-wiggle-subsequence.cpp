class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int pos = 1;
        int neg = -1;
        int possum = 0, negsum = 0;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(((nums[i]-nums[i-1])*pos)>0){
                possum++;
                pos*=-1;
            }
            
            if(((nums[i]-nums[i-1])*neg)>0){
                negsum++;
                neg*=-1;
            } 
            
        }
        
        possum ++;
        negsum ++;
        
        return max(possum,negsum);
    }
};