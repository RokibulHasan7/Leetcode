class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i = 0;
        while(i < 31){
            int tmp = pow(2, i);
            if(n == tmp){
                return true;
            }
            i++;
        }
        
        return false;
    }
};