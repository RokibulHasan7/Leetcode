class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int Ans = 0;
        for(int i = 0; i < 32; i++){
            int mask = (1 << i);
            if(n & mask){
                Ans |= (1 << (31 - i));
                cout<<Ans<<endl;
            }
        }
        
        return Ans;
    }
};