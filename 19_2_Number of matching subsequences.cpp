// https://leetcode.com/problems/number-of-matching-subsequences/


// BRUTE FORCE -> O(m+n)
class Solution {
public:

    bool f(string it , string s)
    {
        int i = 0 ;
        int j = 0 ;

        int it_s = it.size() ;
        int s_s = s.size() ;

        while(i < it_s && j < s_s)
        {
            if(it[i] == s[j])
            {
                i++ ;
            }
            j++ ;
        }
        return i == it_s ;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int m = s.size() ;
        int n = words.size() ;

        int count = 0 ;

        for(auto it : words)
        {
            if(f(it,s) == true)
            {
                count++ ;
            }
        }

        return count ;
    }
};

// Optimal

class Solution {
public:
    bool isSubsequence(string& s, string& t, unordered_map<char, vector<int>>& mp) {
        int m = s.size(); 
        int prev = -1;    // To track the previous index in `t`

        // Iterate through each character of `s`
        for (int i = 0; i < m; ++i) {
            char ch = s[i];

            // If the character `ch` is not in `t`, return false
            if (mp.find(ch) == mp.end()) {
                return false;
            }

            // Get the indices of the character `ch` in `t`
            vector<int>& indices = mp[ch];

            // Use upper_bound to find the next occurrence of `ch` after `prev`
            auto it = upper_bound(indices.begin(), indices.end(), prev);

            // If there's no valid index after `prev`, return false
            if (it == indices.end()) {
                return false;
            }

            // Update `prev` to the current index of `ch`
            prev = *it;
        }

        // All characters of `s` are found in `t` in order
        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;

        // Preprocess `s` to create a map of character -> list of indices
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]].push_back(i);
        }

        // Check each word in `words` to see if it is a subsequence of `s`
        for (string& word : words) {
            if (isSubsequence(word, s, mp)) {
                count++;
            }
        }

        return count; 
    }
};
