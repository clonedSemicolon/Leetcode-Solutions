class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n =  numRows;
        vector<vector<int>> v;
        if( n == 1)
        {
            v.push_back({1});
        }
        
        if(n == 2)
        {
            v.push_back({1});
            v.push_back({1,1});
        }
        
        if(n >=3)
        {
            v.push_back({1});
            v.push_back({1,1});
        
            int level = 2;
            
            for(int i = 1; i<n-1; ++i)
            {
                vector<int> r;
                for(int j = 0; j<= level; ++j)
                {
                    if(j == 0)
                        r.push_back(v[i][0]);
                    else if(j == level) {
                        r.push_back(v[i][level-1]);
                    }
                    else{
                        r.push_back(v[i][j-1] + v[i][j]);
                    }    
                }
                
                ++level;
                v.push_back(r);
            }
        }
        
        return v;
    }
};