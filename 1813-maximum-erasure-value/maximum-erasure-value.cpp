class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        int left=0, csum=0, maxsum=0;

        for(int right=0;right<n;right++){
            while(st.find(nums[right])!=st.end()){
                st.erase(nums[left]);
                csum-=nums[left];
                left++;
            }

            csum+=nums[right];
            st.insert(nums[right]);

            maxsum=max(maxsum,csum);
        }
        return maxsum;
    }
};