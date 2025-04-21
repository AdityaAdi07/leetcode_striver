class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxl = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxl) return false;
            maxl = max(maxl, i + nums[i]);
        }
        return true;
    }
};
