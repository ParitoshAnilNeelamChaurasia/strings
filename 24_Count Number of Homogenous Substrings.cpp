// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

class Solution {
public:

    int MOD = 1e9+7 ;
    int countHomogenous(string s) {
        int n = s.size() ;

        int count = 0 ;

        int len = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(i > 0 && s[i] == s[i-1] )
            {
                len++ ;
            }
            else
            {
                len = 1 ;
            }
            count = (count + len) % MOD ;
        }
        return count % MOD;
    }
};
