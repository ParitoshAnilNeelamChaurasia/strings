// https://leetcode.com/problems/compare-version-numbers/description/

class Solution {
public:
    vector<string> get_token(string version)
    {
        stringstream ss(version) ;  // converting the string -> to stream 

        string token = "" ;  // all tokens of the current string came

        vector<string> tokens ;

        // ss -> stream
        // token -> token
        // . -> dilemeter (. -> given as the breaking point)
        while(getline(ss , token , '.'))            // string token se stream me daalna jo bhi dilemeter ho
        {
            tokens.push_back(token) ;
        }
        return tokens ;
    }
    int compareVersion(string version1, string version2) {

        vector<string> v1 = get_token(version1) ;
        vector<string> v2 = get_token(version2) ;

        int m = v1.size() ;
        int n = v2.size() ;
        int i = 0 ;

        while(i < m  || i < n)
        {
            int a , b ;

            if(i < m)
            {
                a = stoi(v1[i]) ;
            }
            else
            {
                a = 0 ;
            }

            if(i < n)
            {
                b = stoi(v2[i]) ;
            }
            else
            {
                b = 0 ;
            }
            if(a < b)
            {
                return -1 ;
            }
            else if(a > b)
            {
                return 1 ;
            }
            i++ ;
        }
        return 0 ;   // equal versions
    }
};
