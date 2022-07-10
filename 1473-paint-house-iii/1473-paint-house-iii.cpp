class Solution {
public:
    
        int dp[100][100][21];
        int mx = 1e7+1;
        
        int solve(vector<int>& houses, vector<vector<int>>& cost, int target,int idx, int cnt, int pre){
            
            if(idx == houses.size()){
                if(cnt == target)
                    return 0;
                else
                    return mx;
            }
            
            if(dp[idx][cnt][pre]!=-1){
                return dp[idx][cnt][pre];
            }
            
            int mn = 1e7+1;
            
            if(houses[idx]!=0){
                if(houses[idx]!=pre){
                    mn = solve(houses,cost,target,idx+1,cnt+1,houses[idx]);
                }
                else{
                    mn = solve(houses,cost,target,idx+1,cnt,houses[idx]);
                }
            }
            
            else{
                for(int i=0;i<cost[0].size();i++){
                    int val;
                    if((i+1)!=pre){
                        val = cost[idx][i] + solve(houses,cost,target,idx+1,cnt+1,i+1);
                    }
                    else{
                        val = cost[idx][i] + solve(houses,cost,target,idx+1,cnt,i+1);
                    }
                    
                    mn = min(mn,val);
                }
                
            }
            
            return dp[idx][cnt][pre] = mn;
        }
            
        
            
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp,-1,sizeof(dp));
        int res = solve(houses,cost,target,0,0,0);
        return res==mx? -1 : res;
        
    }
};