// Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        int odd=0;
        for(char a = 'A'; a<='z'; a++){
            odd += count(s.begin(), s.end(), a) & 1;
        }
        return s.length() - odd + (odd>0);
    }
};