// https://leetcode.com/problems/backspace-string-compare/description/

// O(m+n) -> extra space complexity
class Solution {
public:
    string res(string &temp)
    {
        int n = temp.size() ;
        string ans = "" ;

        int i = 0 ;

        while(i < n)
        {
            if(temp[i] != '#')
            {   
                ans.push_back(temp[i]) ;
            }
            else if(!ans.empty())
            {
                ans.pop_back() ;
            }
            i++ ;
        }
        return ans ;
    }
    bool backspaceCompare(string s, string t) {
        return res(s) == res(t) ;
    }
};
