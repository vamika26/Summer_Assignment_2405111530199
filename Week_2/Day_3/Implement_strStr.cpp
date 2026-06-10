#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int m = needle.length();

        // Traverse possible starting points
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare substring with needle
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // Complete match found
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};