class Solution {
public:
    string decodeString(string s) {
        int sz = s.size();
        stack<pair<int, string>> st;
        string tmp= "", num = "";
        string Ans = "";
        for(int i = 0; i < sz; i++){
            if(isalpha(s[i])){
                tmp += s[i];
            }
            else if(isdigit(s[i])){
                num += s[i];
            }
            else if(s[i] == '['){
                st.push({stoi(num), tmp});
                num = ""; tmp = "";
            }
            else{
                pair<int, string> p = st.top();
                st.pop();
                string tmp2 = "";
                while(p.first--){
                    tmp2 = tmp2 + tmp;
                }
                tmp = p.second + tmp2;
                //cout<< tmp<<endl;
            }
        }
        return tmp;
    }
};
