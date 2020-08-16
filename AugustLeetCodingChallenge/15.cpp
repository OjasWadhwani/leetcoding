// Non-overlapping Intervals
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (!intervals.size()) return 0;
        vector< pair<int,int>> v;
        for(int i=0; i<intervals.size(); i++){
            v.push_back(make_pair(intervals[i][0], intervals[i][1]));
        }
        sort(v.begin(), v.end(), sortPairBySecond);
        int end = v[0].second;
        int count=1;
        for(int i=1; i<intervals.size(); i++){
            if(v[i].first>=end){
                count++;
                end=v[i].second;
            }
        }
        return intervals.size()-count;
    }
    
    static bool sortPairBySecond( pair<int, int>& a,  pair<int, int>& b){
        return (a.second < b.second);
    }
};