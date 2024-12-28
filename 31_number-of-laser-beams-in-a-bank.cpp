// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/submissions/1490626701/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size() ;

        int ans = 0 ;
        int prev = 0 ;

        for(string s : bank)
        {
            int curr = 0 ;
            for(char c : s)
            {
                if(c == '1')
                {
                    curr++ ;
                }
            }
            if(curr != 0)
            {
                ans = ans + (curr*prev) ;
                prev = curr ;
            }
        }
        return ans ;
    }
};
