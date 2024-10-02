class Solution {
public:
    bool check_limit(vector<int> weights, int wt, int days){
        int cnt=1,curr_sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>wt)   
                return false;
            else if(curr_sum+weights[i]>wt){
                cnt++;
                curr_sum=0;
            }
            curr_sum+=weights[i];
        }
        if(cnt<=days)
            return true;
        else 
            return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high;
        for(int i=0;i<n;i++)
            high+=weights[i];
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check_limit(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};