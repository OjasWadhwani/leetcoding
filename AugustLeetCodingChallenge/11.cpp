class Solution {
public:
    int hIndex(vector<int>& citations) {
        return evaluate(citations);  
    }
private: 
    int evaluate(vector<int>& citations){
        sort(citations.begin(), citations.end());
        return binarySearch(citations);
    }
    int binarySearch(vector<int>& citations){
        int len=citations.size();
        int lo=0, hi=len-1, mid;
        while(lo<=hi){
            mid=lo + (hi-lo)/2;
            if(citations[mid] >= len-mid)
                hi=mid-1;
            else 
                lo=mid+1;
        }
        return len-lo;
    }
};