class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return evaluate(rowIndex);
    }
private:
    vector<int> evaluate(int rowIndex){
        vector<int> vector1;
        vector<int> vector2;
        int count=0;
        if(rowIndex==0){
            vector1.push_back(1);
            return vector1;
        }
        if(rowIndex==1){
            vector1.push_back(1);
            vector1.push_back(1);
            return vector1;
        }
        vector1.push_back(1);
        vector1.push_back(2);
        vector1.push_back(1);
        if(rowIndex==2)
            return vector1;
        else{
            count+=2;
            return recursiveFunc(vector1, vector2, rowIndex, count);
        }
            
    }
    vector<int> recursiveFunc(vector<int>& v1, vector<int>& v2, int rowIndex, int& count){
        v2.push_back(1);
        for(int i=0; i<v1.size()-1; i++){
            v2.push_back(v1[i]+v1[i+1]);
        }
        v2.push_back(1);
        count++;
        if(count==rowIndex)
            return v2;
        v1.clear();
        return recursiveFunc(v2, v1, rowIndex, count);
    }
};