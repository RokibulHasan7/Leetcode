class Solution {
public:
    bool isValid(string s) {
        int sz = s.size();
        bool ok = true;
        stack<char>st;
        for(int i = 0; i < sz; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(st.size() > 0){
                char ch = st.top();
                if((s[i] == ')' && ch != '(') || (s[i] == '}' && ch != '{') || (s[i] == ']' && ch != '[')){
                    ok = false;
                }
                else{
                    st.pop();
                }
            }
            else{
                ok = false;
            }
        }
        if(!ok || s.size() % 2 ==1 || st.size() > 0){
            return false;
        }
        else{
            return true;
        }
    }
};