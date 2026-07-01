class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mp;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < fruits.size(); r++) {

            mp[fruits[r]]++;

            while (mp.size() > 2) {

                mp[fruits[l]]--;

                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};