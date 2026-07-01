class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char,int> mp;

        for(char c : p)
            mp[c]++;

        int count = mp.size();

        int l = 0;

        vector<int> ans;

        for(int r = 0; r < s.size(); r++)
        {
            if(mp.find(s[r]) != mp.end())
            {
                mp[s[r]]--;

                if(mp[s[r]] == 0)
                    count--;
            }

            while(count == 0)
            {
                if(r - l + 1 == p.size())
                    ans.push_back(l);

                if(mp.find(s[l]) != mp.end())
                {
                    mp[s[l]]++;

                    if(mp[s[l]] == 1)
                        count++;
                }

                l++;
            }
        }

        return ans;
    }
};