// https://leetcode.com/problems/shortest-palindrome/description/

// Approach-1

// O(n2)
class Solution {
public:
    string shortestPalindrome(string s) {
        string ans = s ;
        reverse(ans.begin() , ans.end()) ;

        int n = s.size() ;

        for(int i = 0 ; i < n ; ++i)
        {
            // prefix in s == suffix in ans
            if(s.substr(0,n-i) == ans.substr(i,n))
            {
                return ans.substr(0,i) + s ;
            }
        }
        return ans + s ;
    }
};

// Approach - 2

// (Using LPS in KMP)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix
    
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; //You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(), 0); //O(n)
        computeLPS(temp, LPS);

        int longestLPSLength = LPS[temp.length()-1]; //temp.back();

        string culprit = rev.substr(0, s.length() - longestLPSLength); //O(n)

        return culprit + s;
    }
};
