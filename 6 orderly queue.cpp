
// M-1 -> using rotate function
class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size() ;

        // brute force way
        if(k == 1)
        {
            string res = s ;

            for(int i = 1 ; i <= n-1 ; ++i)
            {
               rotate(s.begin() , s.begin()+1 ,s.end()) ;
               res = min(res , s) ;
            }
            return res ;
        }

        sort(s.begin() , s.end()) ;
        return s ;
    }
};

// M-2 using substr function

class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size() ;

        // brute force way
        if(k == 1)
        {
            string res = s ;

            for(int i = 1 ; i <= n-1 ; ++i)
            {
                string temp = s.substr(i) + s.substr(0,i) ;

                res = min(temp , res) ;
            }
            return res ;
        }

        sort(s.begin() , s.end()) ;
        return s ;
    }
};
