// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/


// Approach 1
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size() ;

        // this set is created -> to find the unique characters present in string "s"

        // In future take it from the set and used it to find the answer
        unordered_set<char> st ;

        for(auto it : s)
        {
            st.insert(it) ;
        }

        int count = 0 ;

        for(char letter : st)
        {
            int left_ind = -1 ;
            int right_ind = -1 ;

            for(int i = 0 ; i < n ; ++i)
            {
                if(s[i] == letter)
                {
                    // assigning left_ind -> its assigned only 1 time
                    if(left_ind == -1)
                    {
                        left_ind = i ; 
                    }

                    // right_ind -> varies in each iteration
                    right_ind = i ;
                }
            }

            // middle index starts from left_ind+1 -> right_ind-1 
            unordered_set<char> st_mid ;
            for(int middle_ind = left_ind+1 ; middle_ind <= right_ind - 1 ; ++middle_ind)
            {
                st_mid.insert(s[middle_ind]) ;
            }
            count += st_mid.size() ;
        }
        return count ;
    }
};
