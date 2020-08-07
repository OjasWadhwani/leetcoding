class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector< vector<int> > result;
        vector<int> tryout;
        checkSum(0, tryout, target, candidates, result);
        return result;
    }
private:
    void checkSum(int index, vector<int>& tryout, int target, vector<int>& candidates, vector< vector<int> >& result){
        if(!target){
            result.push_back(tryout);
            return;
        }
        
        for(int i = index; i != candidates.size() && target >= candidates[i]; i++){
            tryout.push_back(candidates[i]);
            checkSum(i, tryout, target - candidates[i], candidates, result);
            tryout.pop_back();
        }
    }
};