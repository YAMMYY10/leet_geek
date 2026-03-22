class Solution {
public:
    void rotatedMatrix(vector<vector<int>> &matrix){
        int n=matrix.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i=0; i<n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat==target) {
            return true;
        }
        for (int i=0; i<3; i++) {
            rotatedMatrix(mat);
            if (mat==target) {
                return true;
                break;
            }
        }
        return false;
    }
};