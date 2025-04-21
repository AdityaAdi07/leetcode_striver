class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long> presum;
        presum.push_back(0);
        long long sum=0;
        for (int i=0; i<differences.size(); i++){
            sum+=differences[i];
            presum.push_back(sum);
        }
        long long xl= lower-(*min_element(presum.begin(), presum.end()));
        long long xm= upper-(*max_element(presum.begin(), presum.end()));
        if(xl>xm) return 0;
        return xm-xl+1;
        
    }
};