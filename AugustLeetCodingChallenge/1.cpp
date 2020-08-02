class Solution {
public:
    bool isCapital(char a){
        int b = a;
        if(a>=97 && a<=122)
            return false;
        return true;
    }
    
    bool detectCapitalUse(string word) {
        if(word.length()==1) return true;
        if(word.length()==2) {if(!isCapital(word[0]) && isCapital(word[1])) return false;
                             else return true;}
        if(isCapital(word[0])){
            if(isCapital(word[1])){
                for(int i=2; i<word.length(); i++){
                    if(!isCapital(word[i]))
                        return false;
                }
                return true;
            }
            else{
                for(int i=2; i<word.length(); i++){
                    if(isCapital(word[i]))
                        return false;
                }
                return true;
            }
        }
        else{
            for(int i=1; i<word.length(); i++){
                if(isCapital(word[i]))
                    return false;
            }
            return true;
        }
    }
};