// https://leetcode.com/problems/restore-ip-addresses/description/

class Solution {
public:
    int n ;

    vector<string> res ;

    bool is_valid(string s)
    {
        if(s[0] == '0')
        return false ;

        int num = stoi(s) ;

        if(num > 255)
        return false ;

        return true ;
    }
    void solve(string &s , int ind , int parts , string curr)
    {
        if(ind == n && parts == 4)
        {
            curr.pop_back() ;  // for removing "."
            res.push_back(curr) ;
        }
        if(ind + 1 <= n)
        solve(s , ind+1 , parts+1 , curr + s.substr(ind , 1) + ".") ;

        if(ind+2 <= n && is_valid(s.substr(ind,2)))
        solve(s , ind+2 , parts+1 , curr + s.substr(ind , 2) + ".") ;

        if(ind+3 <= n && is_valid(s.substr(ind,3))) 
        solve(s , ind+3 , parts+1 , curr+s.substr(ind , 3) + ".") ;
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size() ;

        res.clear() ;

        if(n > 12)
        {
            return {} ;
        }

        int parts = 0 ;
        string curr = "" ;
        // (s , ind , no. of parts , string curr)
        solve(s , 0 , parts , curr) ;

        return res ;
    }
};
