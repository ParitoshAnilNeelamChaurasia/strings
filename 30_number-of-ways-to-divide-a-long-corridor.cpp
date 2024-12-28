// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

class Solution {
public:
    int MOD = 1e9+7 ;
    int numberOfWays(string corridor) {
        int n = corridor.size() ;

        vector<int> seed_ind ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(corridor[i] == 'S')
            {
                seed_ind.push_back(i) ;
            }
        }

        if(seed_ind.size() % 2 == 1 || seed_ind.size() == 0)
        {
            return 0 ;
        }

        int prev_end_ind = seed_ind[1] ;
        int curr_ind ; 

        long long res = 1 ;

        for(int i = 2 ; i < seed_ind.size() ; i = i+2)
        {
            int len = seed_ind[i] - prev_end_ind ;
            res = (res * len) % MOD ;
            prev_end_ind = seed_ind[i+1] ;
        }
        return (int)res ;
    }
};
