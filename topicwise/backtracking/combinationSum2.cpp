class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> status(candidates.size(), false);
        vector<int> tryout;
        set< vector<int> > setResult;
        checkSum(0, setResult, tryout, target, candidates, status);
        vector<vector<int>> result;
        setToVector(setResult, result);
        return result;
    }
    void setToVector(set<vector<int>>& s, vector<vector<int>>& r){
        set< vector<int> >::iterator itr;
        for(itr=s.begin(); itr!=s.end(); itr++){
            r.push_back(*itr);
        }
    }
private:
    void checkSum(int index, set< vector<int> >& setResult, vector<int>& tryout, int target, vector<int>& candidates, vector<bool>& status){
        // vector<bool> status(candidates.size(), false);
                            
        if(!target){
            setResult.insert(tryout);
            std::fill(status.begin(), status.end(), false);
            return;
        }
        
        for(int i=index; i!=candidates.size() && target>=candidates[i]; i++){
            if(!status[i]){
                tryout.push_back(candidates[i]);
                status[i]=true;
                checkSum(i, setResult, tryout, target-candidates[i], candidates, status);
                tryout.pop_back();
                status[i]=false;
            }
        }
    }
};