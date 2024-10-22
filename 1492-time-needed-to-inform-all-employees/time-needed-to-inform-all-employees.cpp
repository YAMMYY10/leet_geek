class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int,int>> q;
        vector<vector<int>> mat(n);
        for(int i=0;i<n;i++)
            if(manager[i]!=-1)
                mat[manager[i]].push_back(i);
        q.push({headID,0});
        int max_time=0;
        while(!q.empty()){
            int emp=q.front().first;
            int time=q.front().second;
            max_time=max(max_time,time);
            q.pop();
            for(auto it: mat[emp])
                q.push({it,time+informTime[emp]});
        }
        return max_time;
    }
};