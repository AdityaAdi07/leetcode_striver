class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        vector<pair<int, char>> freq;

        for (auto &it : mp)
            freq.push_back({it.second, it.first});

        sort(freq.rbegin(), freq.rend());

        string ans;

        for (auto &p : freq) {
            ans.append(p.first, p.second);  
        }

        return ans;
    }
};