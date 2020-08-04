class Solution {
public:
    bool isPowerOfFour(int num) {
        if(!num) return false;
        while(num!=1){
            if(num%4!=0)
                return false;
            num/=4;
        }
        return true;
    }
};