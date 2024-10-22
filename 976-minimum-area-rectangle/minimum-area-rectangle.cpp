class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
      unordered_map<int,unordered_set<int>> mp;
      for(auto it:points)
        mp[it[0]].insert(it[1]);

      int minArea= INT_MAX;

      for(int i=0; i<points.size(); i++){
        for(int j=i+1; j<points.size(); j++){
            int x1=points[i][0], y1=points[i][1];
            int x2=points[j][0], y2=points[j][1];
            if(x1!=x2 && y1!=y2)
                if(mp[x1].find(y2)!=mp[x1].end() && mp[x2].find(y1)!=mp[x2].end())
                    minArea= min(minArea, abs(y2-y1)*abs(x2-x1));
        }
      }
      if(minArea==INT_MAX) 
        return 0;
      return minArea;        
    }
};