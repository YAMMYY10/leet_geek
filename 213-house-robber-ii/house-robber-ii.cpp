class Solution {
public:
    int robcheck(vector<int> arr){
        int n=arr.size();
        if(n==0)
            return 0;
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0],arr[1]);
        vector<int> dp(n);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int> vec1,vec2;
        for(int i=0;i<n;i++){
            if(i!=0)
                vec2.push_back(nums[i]);
            if(i!=n-1)
                vec1.push_back(nums[i]);
        }
        return max(robcheck(vec1),robcheck(vec2));
    }
};