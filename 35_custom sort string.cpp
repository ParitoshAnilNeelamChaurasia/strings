// https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp; 

        string ans = ""; 

        for (char it : s) {
            mp[it]++;
        }

        for (auto ch : order) 
        { 
            // Check if the character from `order` exists in the map
            if (mp.find(ch) != mp.end()) 
            { 
                int count = mp[ch]; // Get the count of the character in `s`

                // Append the character `count` times to the result
                while (count--) 
                {
                    ans += ch;
                }
                mp.erase(ch); // Remove the character from the map after processing
            }
        }

        // Add remaining characters from `s` that are not in `order`
        for (auto it : mp) 
        {
            char ch = it.first;  
            int count = it.second; 

            // Append the remaining characters to the result
            while (count--) 
            {
                ans += ch;
            }
        }

        return ans;
    }
};
