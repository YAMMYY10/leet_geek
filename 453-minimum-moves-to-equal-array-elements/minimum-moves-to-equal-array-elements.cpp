class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int cnt=0;
        for(int num:nums)
            cnt+=num-mini;
        return cnt;
    }
};