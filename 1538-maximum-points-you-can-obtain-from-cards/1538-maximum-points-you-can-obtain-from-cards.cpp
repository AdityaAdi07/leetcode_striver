class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int maxs=0;
        for(int i=0; i<k; i++) lsum+=cardPoints[i];
        maxs=lsum;
        int r=cardPoints.size()-1;
        for(int i=k-1; i>=0; i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
            maxs=max(maxs, lsum+rsum);
        }
        return maxs;
        
    }
};