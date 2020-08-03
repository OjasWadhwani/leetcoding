class Solution {
public:
    
    bool isLowerCase(char a){
        if(a>=97 && a<=122)
            return true;
        return false;
    }
    bool isUpperCase(char a){
        if(a>=65 && a<=90)
            return true;
        return false;
    }
    bool isNumber(char a){
        if(a>=48 && a<=57)
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int len = s.length();
        // cout<<"length: "<<len<<endl;
        int i=0;
        int j=len-1;
        // cout<<"i: "<<i<<endl;
        // cout<<"j: "<<j<<endl;
        while(i<=j){
            while(!isLowerCase(s[i]) && !isUpperCase(s[i]) && !isNumber(s[i]) && i<=j)
                i++;     
            while(!isLowerCase(s[j]) && !isUpperCase(s[j]) &&! isNumber(s[j]) && i<=j)
                j--;
            // cout<<"i: "<<i<<endl;
            // cout<<"j: "<<j<<endl;
            if(s[i]!=s[j]){
                if(isNumber(s[j]) && isNumber(s[i]))
                    return false;
                if((isNumber(s[i]) && (isUpperCase(s[j]) || isLowerCase(s[j]))) ||  (isNumber(s[j]) && (isUpperCase(s[i]) || isLowerCase(s[i]))) )
                    return false;
                if((isUpperCase(s[i]) && isUpperCase(s[j])) || (isLowerCase(s[i]) && isLowerCase(s[j])))
                    return false;
                if(isUpperCase(s[i]) &&  isLowerCase(s[j]))
                    if(s[i]+32 != s[j])
                        return false;
                if(isUpperCase(s[j]) &&  isLowerCase(s[i]))
                    if(s[i]-32 != s[j])
                        return false;
            }
            i++;
            j--;
        }
        return true;
    }
};