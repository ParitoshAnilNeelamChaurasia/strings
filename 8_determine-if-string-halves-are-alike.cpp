// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

class Solution {
public:
    bool is_vowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch =='E' || ch == 'I' || ch == 'O' || ch == 'U' ;
    }
    bool halvesAreAlike(string s) {
        int n = s.size() ;

        int i = 0 ;
        int j = n/2 ;
        int count_i = 0 ;
        int count_j = 0 ;

        while(i < n/2)
        {
            if(is_vowel(s[i]) == true)
            {
                count_i++ ;
            }
            i++ ;
        }

        while(j < n)
        {
            if(is_vowel(s[j]) == true)
            {
                count_j++ ;
            }
            j++ ;
        }

        return count_i == count_j ;
    }
};
