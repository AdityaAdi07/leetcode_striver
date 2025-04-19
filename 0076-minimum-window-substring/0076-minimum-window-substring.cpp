class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(char c : t) mp[c]++;
        
        int count = 0;
        int l = 0, r = 0;
        int minl = INT_MAX;
        int strt = -1;

        while(r < s.size()) {
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while(count == t.size()) {
                if(r - l + 1 < minl) {
                    minl = r - l + 1;
                    strt = l;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        return strt == -1 ? "" : s.substr(strt, minl);
    }
};
