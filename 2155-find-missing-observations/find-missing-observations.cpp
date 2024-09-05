class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        cout<<m<<endl;
        int sum_m=0;
        for(auto num:rolls)
            sum_m+=num;
        int sum_n=(mean*(n+m))-sum_m;
        cout<<sum_n<<endl;
        if(sum_n<n || sum_n>6*n)
            return {};
        // if((sum_n/n)>6 || (sum_n<0) || ((sum_n/n)==6 && (sum_n%n)!=0))
        //     return {};
        vector<int> ans;
        while(n>0){
            ans.push_back((sum_n/n));
            sum_n-=(sum_n/n);
            n--;
        }
        return ans;
    }
};