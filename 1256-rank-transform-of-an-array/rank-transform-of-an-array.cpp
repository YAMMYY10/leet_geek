class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy=arr;
        int n=arr.size();
        sort(copy.begin(),copy.end());
        int rank=1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(i!=0 && copy[i]!=copy[i-1])
                rank++;
            mp[copy[i]]=rank;
        }
        for(auto &it:arr)
            it=mp[it];
        return arr;
    }
};