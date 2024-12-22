// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first = "" ;
        string second = "" ;

        for(auto it : word1)
        {
            first += it ;
        }

        for(auto it : word2)
        {
            second += it ;
        }

        return first == second ;
    }
};
