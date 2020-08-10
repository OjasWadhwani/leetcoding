class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        int len=s.length();
        for(int i=0; i<len; i++){
            sum+=pow(26, len-1-i)*(s[i]-64);
        }
        return sum;
    }
};