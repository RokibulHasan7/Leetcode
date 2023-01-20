class Solution {
public:
    void backtrack(set<vector<int>> &Ans, vector<int> &temp, int index, vector<int> &nums){
        if(index >= nums.size()){
            if(temp.size() >= 2){
                Ans.insert(temp);
            }
            return;
        }
        // if the temp remains increasing after appending nums[index]
        if(temp.size() == 0 || (temp.back() <= nums[index])){
            temp.push_back(nums[index]);
            backtrack(Ans, temp, index + 1, nums);
            // delete nums[index] from the end of the sequence
            temp.pop_back();
        }
        // call recursively not appending an element
        backtrack(Ans, temp, index + 1, nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> Ans;
        vector<int> temp;
        backtrack(Ans, temp, 0, nums);
        return vector(Ans.begin(), Ans.end());
    }
};
