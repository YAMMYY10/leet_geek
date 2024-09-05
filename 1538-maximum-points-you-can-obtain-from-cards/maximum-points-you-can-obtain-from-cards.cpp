class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        for(int i=0;i<k;i++)
            lsum+=cardPoints[i];
        int rsum=0;int right=n-1;
        int maxsum=lsum;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[right];
            right--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};