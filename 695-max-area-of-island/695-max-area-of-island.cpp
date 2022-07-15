class Solution {
public:
    
    int getArea(vector<vector<int>>& grid,int i, int j){
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        
        if(i<0 || j<0 || i>row || j>col || grid[i][j]==0){
            return 0;
        }
        
        grid[i][j] = 0;
        
        int val = 1+getArea(grid,i+1,j)+getArea(grid,i-1,j)+getArea(grid,i,j+1)+getArea(grid,i,j-1);
        return val;
        
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = -1;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    res = max(res,getArea(grid,i,j));
                }
            }
        }
        
        if(res == -1){
            res = 0;
        }
        return res;
    }
};