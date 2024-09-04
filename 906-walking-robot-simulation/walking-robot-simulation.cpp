class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        if(commands.empty())
            return 0;
        int n=commands.size();
        vector<pair<int,int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        int dir=0;
        set<pair<int,int>> obs;
        for(auto it: obstacles)
            obs.insert({it[0],it[1]});
        int xc=0,yc=0,maxdis=0;
        for(int cmd:commands){
            if(cmd==-2)
                dir=(dir-1+4)%4;
            else if(cmd==-1)
                dir=(dir+1)%4;
            else{
                for(int x=0;x<cmd;x++){
                    int newx=xc+directions[dir].first;
                    int newy=yc+directions[dir].second;
                    if(obs.count({newx,newy}))
                        break;
                    xc=newx;
                    yc=newy;
                    maxdis=max(maxdis,xc*xc+yc*yc);
                }
            }
        }
        return maxdis;
    }
};