class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int pre[n+1];
        int suf[n+1];
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                pre[i] = 0;
            }
            else{
                pre[i] = st.top() + 1;
            }
            
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                suf[i] = n - 1;
            }
            else{
                suf[i] = st.top() - 1;
            }
            
            st.push(i);
        }
        
        /*for(int i = 0; i < n; i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < n; i++){
            cout<<suf[i]<<" ";
        }
        cout<<endl;*/
        
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, heights[i] * ((suf[i] - pre[i]) + 1));
        }
        
        return mx;
    }
};
