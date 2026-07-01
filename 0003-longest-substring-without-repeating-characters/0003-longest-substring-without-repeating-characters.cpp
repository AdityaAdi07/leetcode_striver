class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            unordered_map<int,int> mp;
            int l=0;
            int count=0;
            int max_c=0;
            for(int r=0; r<s.size(); r++){
                mp[s[r]]++;
                count++;
                while(mp[s[r]]>1){
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                    l++;
                    count--;
                }
                
                max_c=max(max_c, count);
            }    
            return max_c;
    }
};