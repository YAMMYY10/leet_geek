class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0,curr=0,farthest=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,nums[i]+i);
            if(curr==i){
                jumps++;
                curr=farthest;
            }
        }
        if(curr>=n-1)
            return true;
        return false;
    }
};