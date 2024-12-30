// https://leetcode.com/problems/adding-spaces-to-a-string/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m = s.size() ;
        int n = spaces.size() ;

        int i = 0 ;
        int j = 0 ;

        string ans ;

        while(i < m)
        {
            if(j < n && i == spaces[j])
            {
                ans.push_back(' ') ;
                j++ ;
            }
            else
            {
            ans.push_back(s[i]) ;
            i++ ;
            }
        }
        return ans ;
    }
};
