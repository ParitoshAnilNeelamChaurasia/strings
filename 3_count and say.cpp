// https://leetcode.com/problems/count-and-say/description/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1" ;
        }
        string say = countAndSay(n-1) ;

        string res = "" ;

        for(int i = 0 ; i < say.size() ; ++i)
        {
            char ch = say[i] ;

            int count = 1 ;  // count = 1 -> one char we have taken in "ch"

            while(i < say.size()-1 && say[i] == say[i+1])
            {
                count++ ;
                i++ ; 
            } 

            res += to_string(count) + ch ;
        }
        return res ;
    }
};
