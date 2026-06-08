#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> count(26, 0);

        // Store frequency of magazine characters
        for (char ch : magazine) {
            count[ch - 'a']++;
        }

        // Check ransomNote characters
        for (char ch : ransomNote) {

            if (count[ch - 'a'] == 0) {
                return false;
            }

            count[ch - 'a']--;
        }

        return true;
    }
};