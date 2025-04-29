class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        while (!s.empty() && s.back() == ' ') {
        s.pop_back();
    }
    if(s.size()==1) return 1;
    for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') break;
            count++;
        }
    return count;
        
    }
};