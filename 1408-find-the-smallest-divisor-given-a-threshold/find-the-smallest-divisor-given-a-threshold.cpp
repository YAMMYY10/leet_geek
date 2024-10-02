class Solution {
public:
    bool check(vector<int> nums,int threshold, int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)divisor);
        }
        if(sum<=threshold)
            return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int mini=INT_MAX;
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,threshold,mid)){
                mini=min(mini,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return low;
    }
};