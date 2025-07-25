class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        unordered_set<int> st;
        int maxele=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxele=max(maxele,nums[i]);
            if(nums[i]>0 && st.find(nums[i])==st.end()){
                sum+=nums[i];
                st.insert(nums[i]);
            }
        }
        if(sum>0)
            return sum;
        else
            return maxele;
    }
};