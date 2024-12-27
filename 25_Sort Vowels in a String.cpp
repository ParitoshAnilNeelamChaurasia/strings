// https://leetcode.com/problems/sort-vowels-in-a-string/description/

class Solution {
public:
    bool is_vow(char ch)
    {
        return ch == 'a' || ch == 'e' ||  ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ;
    }
    string sortVowels(string s) {
        string ans = "" ;

        int n = s.size() ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(is_vow(s[i]))
            {
                ans.push_back(s[i]) ;
            }
        }

        sort(ans.begin() , ans.end()) ;
        int j = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(is_vow(s[i]) == false)
            {
                s[i] = s[i] ;
            }
            else
            {
                s[i] = ans[j] ;
                j++ ;
            }
        }
        return s ;
    }
};
