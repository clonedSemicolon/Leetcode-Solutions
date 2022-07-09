class Solution {
public: 
    int maxResult(vector<int>& nums, int k) {
       int n=nums.size();
        vector<int>sol(n,0);
      
      priority_queue<pair<int,int>>pq;
      
      for(int i=n-1; i>=0; i--){
          while(pq.size()&&pq.top().second>i+k)
              pq.pop();
          
          sol[i]=sol[i]+(pq.size()?pq.top().first:0)+nums[i];
          pq.push({sol[i],i});
      }
      return sol[0];
    }
};