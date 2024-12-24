
// https://leetcode.com/problems/concatenated-words/description/

class Solution {
public:

    bool is_concatenated(string word , unordered_set<string> &st)
    {
        int l = word.size() ;

        for(int i = 0 ; i < l ; ++i)
        {
            string pref = word.substr(0,i) ;
            string suff = word.substr(i,l) ;

            if( (st.find(pref) != st.end() && st.find(suff) != st.end()) || (st.find(pref) != st.end() && is_concatenated(suff , st)) )
            {
                return true ;
            }
        }
        return false ;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size() ;

        unordered_set<string> st(words.begin() , words.end()) ;

        vector<string> res ;

        for(int i = 0 ; i < n ; ++i)
        {
            string word = words[i] ;

            if(is_concatenated(word , st) == true)
            {
                res.push_back(word) ;
            }
        }
        return res ;
    }
};



// MEMOIZATION APPROACH

class Solution {
public:

    unordered_map<string , bool> mp ;
    bool is_concatenated(string word , unordered_set<string> &st)
    {
        int l = word.size() ;

        if(mp.find(word) != mp.end())
        {
            return mp[word] ;
        }

        for(int i = 0 ; i < l ; ++i)
        {
            string pref = word.substr(0,i) ;
            string suff = word.substr(i,l) ;

            if( (st.find(pref) != st.end() && st.find(suff) != st.end()) || (st.find(pref) != st.end() && is_concatenated(suff , st)) )
            {
                return mp[word] = true ;
            }
        }
        return mp[word] = false ;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size() ;

        unordered_set<string> st(words.begin() , words.end()) ;

        vector<string> res ;

        for(int i = 0 ; i < n ; ++i)
        {
            string word = words[i] ;

            if(is_concatenated(word , st) == true)
            {
                res.push_back(word) ;
            }
        }
        return res ;
    }
};
