// https://leetcode.com/problems/decoded-string-at-index/description/

#define ll long long
class Solution {
public:
    bool is_digit(char ch)
    {
        return ch >= '0' && ch <= '9' ;
    }

    bool is_alphabet(char ch)
    {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ;
    }
    string decodeAtIndex(string s, int k) {
        ll n = s.size() ;

        ll sz = 0 ;
        for(int i = 0 ; i < n ; ++i)
        {
            if(is_digit(s[i]))
            {
                sz = sz*(s[i] - '0') ;
            }
            else
            {
                sz++ ;
            }
        }

        for(int i = n-1 ; i >= 0 ; --i)
        {
            k = k % sz ;

            if(k==0 && is_alphabet(s[i])== true)
            {
                char ch = s[i] ;
                return string(1 , ch) ;
            }

            if(is_alphabet(s[i]) == true)
            {
                sz = sz-1 ;
            }
            else 
            {
                sz = sz / (s[i] - '0') ;
            }
        }
        return {} ;

    }
};
