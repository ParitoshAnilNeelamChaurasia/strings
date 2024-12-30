// https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/


// Approach 1
#define ll long long
class Solution {
public:
    long long countSubstrings(string s, char c) {
        ll n = s.size() ;

        ll count = 0 ;
        ll substrings = 0 ;

        for(auto it : s)
        {
            if(it == c)
            {
                substrings += count+1 ;
                count++ ;
            }
        }
        return substrings ;
    }
};

// Approach 2
#define ll long long
class Solution {
public:
    long long countSubstrings(string s, char c) {
        ll count = 0 ;

        for(auto it : s)
        {
            if(it == c)
            {
                count++ ;
            }
        }
        return count*(count+1) / 2 ;
    }
};
