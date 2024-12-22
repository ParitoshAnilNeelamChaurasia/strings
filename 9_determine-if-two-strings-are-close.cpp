// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        set<char>st_1 , st_2 ;

        for(auto it : word1)
        {
            st_1.insert(it) ;
        }

        for(auto it : word2)
        {
            st_2.insert(it) ;
        }

        vector<char>char_1 , char_2 ;

        for(auto it : st_1)
        {
            char_1.push_back(it) ;
        }
        for(auto it : st_2)
        {
            char_2.push_back(it) ;
        }

        sort(char_1.begin() , char_1.end()) ;
        sort(char_2.begin() , char_2.end()) ;

        

        if(st_1.size() != st_2.size())
        {
            return false ;
        }
        if(char_1.size() != char_2.size())
        {
            return false ;
        }
        else
        {
            for(int i = 0 ; i < char_1.size() ; ++i)
            {
                if(char_1[i] != char_2[i])
                {
                    return false ;
                }
            }
        }
        unordered_map<char,int> mp_1 , mp_2 ;

        for(auto it : word1)
        {
            mp_1[it]++ ;
        }
        for(auto it : word2)
        {
            mp_2[it]++ ;
        }

        

        vector<int> ans_1, ans_2 ;

        for(auto it : mp_1)
        {
            ans_1.push_back(it.second) ;
        }

        for(auto it : mp_2)
        {
            ans_2.push_back(it.second) ;
        }

        sort(ans_1.begin() , ans_1.end()) ;

        sort(ans_2.begin() , ans_2.end()) ;

        if(ans_1.size() != ans_2.size())
        {
            return false ;
        }

        for(int i = 0 ; i < ans_1.size() ; ++i)
        {
            if(ans_1[i] != ans_2[i])
            {
                return false ;
            }
        }
        return true ;

        
    }
};
