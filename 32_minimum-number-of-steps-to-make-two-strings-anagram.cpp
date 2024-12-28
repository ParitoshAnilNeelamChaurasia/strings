// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

// Approach -1 -> using 2 maps
// O(n+m+k) 

class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char, int> mp_s, mp_t;

        for (char ch : s) 
        {
            mp_s[ch]++;
        }
        for (char ch : t) 
        {
            mp_t[ch]++;
        }

        int count = 0;

        for (auto it : mp_s) 
        {
            char ch = it.first;
            int freq_s = it.second;
            int freq_t = mp_t[ch];

            // Add the difference for characters in `s`
            if (freq_s > freq_t) {
                count += freq_s - freq_t;
            }
        }

        return count;
    }
};

// Approach - 2 -> using single map
class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp_s ;

        for(auto it : s)
        {
            mp_s[it]++ ;
        }

        for(auto it : t)
        {
            mp_s[it]-- ;
        }

        int count = 0 ;

        for(auto it : mp_s)
        {
            if(it.second > 0)
            count += (it.second) ;
        }
        return count ;
    }
};
