class Solution {
public:
    
    int path[51][51][51];
    long long mod = 1e9+7;
    
    
    int dfs(int i, int j,int r,int c,int moves){
        if(i<0 || j<0 || i>=r || j>=c){
            return 1;
        }
        
        if(moves<=0){
            return 0;
        }
        
        if(path[i][j][moves]!=-1){
            return path[i][j][moves];
        }
        
        long long tot = (dfs(i-1,j,r,c,moves-1)%mod) + (dfs(i+1,j,r,c,moves-1)%mod) +
        (dfs(i,j-1,r,c,moves-1)%mod) + (dfs(i,j+1,r,c,moves-1)%mod);
        
        path[i][j][moves] = tot%mod; 
            
        return path[i][j][moves];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(path,-1,sizeof(path));
        return dfs(startRow,startColumn,m,n,maxMove);
    }
};