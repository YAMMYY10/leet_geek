class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp1;
        for(int i:basket1)
            mp1[i]++;
        for(int i:basket2)
            mp1[i]++;
        long long min_cost=INT_MAX;
        for(auto const &[fruit,count]:mp1){
            if(count%2!=0)
                return -1;
            min_cost=min(min_cost,(long long)fruit);
        }

        vector<long long> fruits;
        map<int,int> cnt;
        for(int i:basket1)
            cnt[i]++;

        for(auto const &[fruit,count]:mp1){
            int diff=cnt[fruit]-(count/2);
            for(int i=0;i<abs(diff);i++)
                fruits.push_back(fruit);
        }

        sort(fruits.begin(),fruits.end());

        long long total_cost=0;
        int swaps=fruits.size()/2;
        for(int i=0;i<swaps;i++)
            total_cost+=min(fruits[i],2*min_cost);
        
        return total_cost;
    }
};