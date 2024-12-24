// https://leetcode.com/problems/buddy-strings/description/

class Solution {
public:

    bool checkfreq(string s)
    {
        vector<int> arr(26,0) ;

        for(auto it : s)
        {
            arr[it-'a']++ ;

            if(arr[it-'a'] > 1)
            {
                return true ;
            }
        }
        return false ;
    }
    bool buddyStrings(string s, string goal) {
        int m = s.size() ;
        int n = goal.size() ;

        if(m != n)
        {
            return false ;
        }

        if(s == goal)
        {
            return checkfreq(s) ;
        }

        vector<int> index ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(s[i] != goal[i])
            {
                index.push_back(i) ;
            }
        }

        if(index.size() != 2)
        {
            return false ;
        }

        swap(s[index[0]] , s[index[1]]) ;

        return s == goal ;
    }
};
