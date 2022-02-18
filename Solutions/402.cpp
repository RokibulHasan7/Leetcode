class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(auto ch: num){
            //cout<<-1<<endl;
            while(st.size() && st.top() > ch && k > 0){
                k--;
                st.pop();
            }
            
            if(st.empty() && ch == '0'){
                continue;
            }
            else{
                st.push(ch);
            }
        }
        
        while(!st.empty() && k > 0){
            k--;
            st.pop();
        }
        //cout<<st.size()<<endl;
        string Ans = "";
        while(!st.empty()){
            //cout<<-1<<endl;
            Ans = st.top() + Ans;
            st.pop();
        }
        if(Ans.size() == 0){
            return "0";
        }
        return Ans;
    }
};
