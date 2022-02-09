class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        
        if(n > m){
            return false;
        }
        
        for(int i = 0; i < n; i++){
            vec1[s1[i] - 'a']++;
            vec2[s2[i] - 'a']++;
        }
        
        if(vec1 == vec2){
            return true;
        }
        int i = 0;
        int j = n;
        while(j < m && i < j){
            vec2[s2[j] - 'a']++;
            vec2[s2[i] - 'a']--;
            i++; j++;
            if(vec1 == vec2){
                return true;
            }
        }
        
        return false;
    }
};