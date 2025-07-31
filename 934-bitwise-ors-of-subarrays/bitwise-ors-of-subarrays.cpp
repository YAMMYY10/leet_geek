class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> prev;
        for(int i=0;i<arr.size();i++){
            unordered_set<int> curr;
            curr.insert(arr[i]);
            for(int it:prev)
                curr.insert(arr[i] | it);
            res.insert(curr.begin(),curr.end());
            prev=curr;
        }
        return res.size();
    }
};