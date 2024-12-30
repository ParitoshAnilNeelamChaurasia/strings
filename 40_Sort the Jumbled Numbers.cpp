// https://leetcode.com/problems/sort-the-jumbled-numbers/description/

//T.C : O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
//S.C : O(n+d)

class Solution {
public:
    string get_Mapped(string &num , vector<int> &mapping)
    {
        string mapped_num = "" ;

        for(int i = 0 ; i < num.size() ; ++i)
        {
            char ch = num[i] ;
            int convert_ch_to_int = ch - '0' ;

            mapped_num += to_string(mapping[convert_ch_to_int]) ;
        }
        return mapped_num ;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int m = mapping.size() ;
        int n = nums.size() ;

        vector<pair<int,int>> vec ;

        for(int i = 0 ; i < n ; ++i)
        {
            string num_str = to_string(nums[i]) ;

            string mapped_str = get_Mapped(num_str , mapping) ;

            int mapped_Num = stoi(mapped_str) ;

            vec.push_back({mapped_Num , i}) ;
        } 

        sort(vec.begin() , vec.end()) ;

        vector<int> res ;

        for(auto &p : vec)
        {
            int original_Num_idx = p.second ;

            res.push_back(nums[original_Num_idx]) ;
        }
        return res ;

    }
};
