class Solution {
public:
    void findcombination(int index,int target,vector<int>& candidates,vector<vector<int>> &ans, vector<int> &vec){
        if(index==candidates.size()){
            if(target==0)
                ans.push_back(vec);
            return;
        }

        if(candidates[index]<=target){
            vec.push_back(candidates[index]);
            findcombination(index,target-candidates[index],candidates,ans,vec);
            vec.pop_back();
        }
        findcombination(index+1,target,candidates,ans,vec);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        findcombination(0,target,candidates,ans,vec);
        return ans;
    }
};