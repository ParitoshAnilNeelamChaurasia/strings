// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size() ;
        int n = t.size() ;

        int i = 0 ;
        int j = 0 ;

        int count = 0 ;
        while(i < m && j < n)
        {
            if(s[i] == t[j])
            {
                j++ ;
            }
            i++ ;
        }
        return n - j ;
    }
};
