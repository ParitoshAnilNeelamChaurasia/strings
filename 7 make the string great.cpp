// https://leetcode.com/problems/make-the-string-great/

class Solution {
public:
    string makeGood(string s) {
        int n = s.size() ;

        string res = "" ; // acts as stack

        for(char &ch : s)
        {
            if(!res.empty() && (res.back() + 32 == ch || res.back() - 32 == ch))
            {
                res.pop_back() ;
            }
            else
            {
                res.push_back(ch) ;
            }
        }

        return res ;
    }
};
