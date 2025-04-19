class Solution {
public:
    int helper(vector<int>& nums, int k){
        int l = 0, count = 0;
        map<int, int> mp;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) mp.erase(nums[l]); 
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
