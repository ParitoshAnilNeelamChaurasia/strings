// https://leetcode.com/problems/detect-capital/description/

class Solution {
public:
    bool upper(char ch)
    {
        return ch >= 'A' && ch <= 'Z' ;
    }

    bool lower(char ch)
    {
        return ch >= 'a' && ch <= 'z' ;
    }

    bool detectCapitalUse(string word) {
        int n = word.size() ;

        bool up_flag = false ;
        int up_count = 0 ;
        bool low_flag = false ;
        int low_count = 0 ;


        for(int i = 0 ; i < n ; ++i)
        {
            if(upper(word[i]) == true)
            {
                up_flag = true ;
                up_count++ ;
            }
            else if(lower(word[i]) == true)
            {
                low_flag = true ;
                low_count++ ;
            }
        }

        int pos = -1 ;

        if(upper(word[0]) == true)
        pos = 0 ;

        if(up_flag == true && low_flag == true)
        {
            if(pos == 0 && up_count == 1)
            {
                return true ;
            }
            return false ;
        }
        
        else if(low_flag == true && low_count == n)
        {
            return true ;
        }

        else if(up_flag == true && up_count == n)
        {
            return true ;
        }
        return false ;
    }
};
