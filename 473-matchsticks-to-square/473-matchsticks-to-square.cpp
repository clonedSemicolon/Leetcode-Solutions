class Solution {
public:
    int subSum,n;
    bool solve(int i, int a, int b, int c, int d,vector<int>&matchSticks){
       if(i==n){
           if(a==subSum && b==subSum  && c==subSum  && d==subSum){
               return true;
           }
       }
    
      if(a+matchSticks[i]<=subSum){
          if(solve(i+1,a+matchSticks[i],b,c,d,matchSticks)){
              return true;
          }
      }
        
      if(b+matchSticks[i]<=subSum){
          if(solve(i+1,a,b+matchSticks[i],c,d,matchSticks)){
              return true;
          }
      }
        
      if(c+matchSticks[i]<=subSum){
          if(solve(i+1,a,b,c+matchSticks[i],d,matchSticks)){
              return true;
          }
      }
        
      if(d+matchSticks[i]<=subSum){
          if(solve(i+1,a,b,c,d+matchSticks[i],matchSticks)){
              return true;
          }
      }
        
      return false;
        
    }
    
    bool makesquare(vector<int>& matchsticks) {
        n = matchsticks.size();
        int sum = 0;
        vector<int>res(4);
        for(int i = 0;i<n;i++){
            sum += matchsticks[i];
        }
        
        if(sum%4)
            return false;
        
        subSum = sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        
        return solve(0,0,0,0,0,matchsticks);    
    }
};