class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{-1,-1},{1,-1},{1,1}};
    bool isValid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m)
            return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                for(int k=0;k<8;k++){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(isValid(x,y,n,m))
                        cnt+=(board[x][y]==1 || board[x][y]==2);
                }
                if(board[i][j]==1 && (cnt<2 || cnt>3))
                    board[i][j]=2;
                else if(board[i][j]==0 && cnt==3)
                    board[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2)
                    board[i][j]=0;
                else if(board[i][j]==-1)
                    board[i][j]=1;
            }
        }
    }
};