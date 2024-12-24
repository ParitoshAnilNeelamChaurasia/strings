// https://leetcode.com/problems/repeated-substring-pattern/submissions/1487122946/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size() ;

        for(int l = 1 ; l <= n/2 ; ++l)
        {
            if(n % l == 0)
            {
                int time = n / l ;

                string pattern = s.substr(0,l) ;
                string new_str = "" ;

                while(time--)
                {
                    new_str += pattern ;
                }
                if(new_str == s)
                return true ;
            }
        }
        return false ;
    }
};
