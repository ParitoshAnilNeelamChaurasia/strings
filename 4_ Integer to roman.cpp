// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        // int n = num.size() ;

        vector<int> val = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1} ;
        vector<string> ans={"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"} ;

        string res = "" ;
        int i = 0 ;

        while(num > 0)
        {
            while(num >= val[i])
            {
                num = num - val[i] ;
                res = res + ans[i] ;
            }
            i++ ;
        } 
        return res ;
    }
};
