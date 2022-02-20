class Solution {
public:
    string LargestString(string s, int n){
        int freq[26] = {0};
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }
        
        priority_queue<pair<char, int>> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push({char('a' + i), freq[i]});
            }
        }
        
        string ans = "";
        
        while(!pq.empty()){
            int c1 = pq.top().first;
            int n1 = pq.top().second;
            pq.pop();
            
            int mn = min(n1, n);
            for(int i = 0; i < mn; i++){
                ans += c1;
            }
            if(n1 - mn > 0){
                if(!pq.empty()){
                    int c2 = pq.top().first;
                    int n2 = pq.top().second;
                
                    pq.pop();
                    ans += c2;
                
                    if(n2 - 1 > 0){
                        pq.push({c2, n2 - 1});
                    }
                    if(n1 - mn > 0){
                        pq.push({c1, n1 - mn});
                    }
                }
                else{
                    return ans;
                }
            }
        }
        
        return ans;
    }
    
    string repeatLimitedString(string s, int repeatLimit) {
        return LargestString(s, repeatLimit);
    }
};
