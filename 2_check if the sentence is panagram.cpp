// https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ans(26,0) ;

        for(auto it : sentence)
        {
            ans[it - 'a']++ ;
        }

        for(auto it : ans)
        {
            if(it == 0)
            return false ;
        }
        return true ;
    }
};
