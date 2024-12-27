// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
public:

    string rever(string ch)
    {
        reverse(ch.begin() , ch.end()) ;
        return ch ;
    }

    string reverseWords(string s) {
        int n = s.size() ;

        string ans = "" ;

        string temp = ""  ;
        for(int i = 0 ; i < n ; ++i)
        {
            if(s[i] != ' ')
            {
                temp += s[i] ;
            }

            else if(s[i] == ' ')
            {
                ans += rever(temp) + " " ;
                temp = "" ;
            }
        }

        ans += rever(temp) ;
        return ans ;
    }
};
