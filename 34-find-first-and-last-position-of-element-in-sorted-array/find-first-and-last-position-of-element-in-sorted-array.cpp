class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2,-1);
        int low=0,high=n-1;
        while(low<=high){ //lb
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans[0]=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        low=0,high=n-1;
        while(low<=high){ //ub
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans[1]=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return ans;
    }
    // int lowbnd(vector<int>& nums, int target){
    //     int low=0,high=nums.size()-1;int ans=-1;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(nums[mid]>=target){
    //             ans=mid;
    //             high=mid-1;
    //         }
    //         else
    //             low=mid+1;
    //     }
    //     return ans;
    // }
    // int uprbnd(vector<int>& nums, int target){
    //     int low=0,high=nums.size()-1;int ans=nums.size();
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(nums[mid]>target){
    //             ans=mid;
    //             high=mid-1;
    //         }
    //         else
    //             low=mid+1;
    //     }
    //     return ans;
    // }
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int lb=lowbnd(nums,target);
    //     if(lb==-1 || nums[lb]!=target) return {-1,-1};
    //     return {lb,uprbnd(nums,target)-1};
    // }
};