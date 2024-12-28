// https://leetcode.com/problems/count-beautiful-substrings-i/

class Solution {
public:
    bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int count_vowel = 0, count_cons = 0; // Reset counts for each starting point

            for (int j = i; j < n; ++j) 
            {
                if (is_vowel(s[j])) 
                {
                    count_vowel++;
                } else 
                {
                    count_cons++;
                }
                
                if (count_vowel == count_cons && (count_vowel * count_cons) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
