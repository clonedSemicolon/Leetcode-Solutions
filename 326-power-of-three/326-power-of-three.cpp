class Solution {
public:
    bool isPowerOfThree(int n) {
        long long pow = 1;
        while(pow<n){
            pow *= 3;
        }
        
        return pow==n;
    }
};