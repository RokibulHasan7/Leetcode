class Solution {
public:
    vector<vector<int>> Ans;
    
    void solve(vector<int>& candidates, vector<int>& tmp, int target, int idx, int sum){
        if(idx >= candidates.size()){
            return;
        }
        
        if(sum + candidates[idx] == target){
            tmp.push_back(candidates[idx]);
            Ans.push_back(tmp);
            return;
        }
        
        if(sum + candidates[idx] < target){
            vector<int> vec1 = tmp;
            vector<int> vec2 = tmp;
            
            vec1.push_back(candidates[idx]);
            solve(candidates, vec1, target, idx, sum + candidates[idx]);
            solve(candidates, vec2, target, idx + 1, sum);
        }
        else{
            return;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        solve(candidates, tmp, target, 0, 0);
        return Ans;
    }
};
