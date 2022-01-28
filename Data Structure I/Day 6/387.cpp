class Solution {
public:
    int firstUniqChar(string s) {
        int sz = s.size();
        map<char,int>mp;
        for(int i=0;i<sz;i++){
            mp[s[i]]++;
        }
        int pos=-1;
        for(int i=0;i<sz;i++){
            if(mp[s[i]]==1){
                pos=i;
                break;
            }
        }
        return pos;
    }
};