// https://leetcode.com/problems/delete-columns-to-make-sorted/description/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() ;

        int ans = 0 ;

        for(int i = 0 ; i < strs[0].size() ; ++i)
        {
            for(int j = 1 ; j < n ; ++j)
            {
                // jth word and ith character
                if(strs[j-1][i] > strs[j][i])  // if prev char is smaller -> its not in lexicographical order
                {
                    ans++ ;
                    break ;
                }
            }
        }
        return ans ;
    }
};
