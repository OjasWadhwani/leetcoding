class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = moves(grid);
        
        return count;
    }
private:
    int moves(vector<vector<int>>& grid){
        queue <pair<int, int>> q;
        
        int count=0;
        int count1=0, count2=0; 
        int status = 0; // checks for presence of 1
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                    count1++;
                }
                if(grid[i][j]==1)
                    status=1;
            }
        }
        
        if(!count1){
            count=0;
            if(status)
                count=-1;
            return count;
        }

        while(!q.empty()){
            if(count1){
                updateAdjacent(grid, count1, count2, q);
                // cout<<"count2: "<<count2<<endl;
                count1=0;
                count++;
            }
            if(count2){
                updateAdjacent(grid, count2, count1, q);
                // cout<<"count1: "<<count1<<endl;
                count2=0;
                count++;
            }
        }
        
        count--;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    count=-1;
                    break;
                }
            }
        }
        
        return count;
        
    }
    
    void updateAdjacent(vector<vector<int>>& grid, int& count1, int& count2, queue <pair<int, int>>& q){
        while(count1--){
            pair<int, int> temp=q.front();
            int row=temp.first;
            int column=temp.second;
            
            if(row!=grid.size()-1 && grid[row+1][column]==1){
                grid[row+1][column]=2; //down
                q.push(make_pair(row+1, column));
                count2++;
            }
            if(column!=grid[temp.first].size()-1 && grid[row][column+1]==1){
                grid[row][column+1]=2; //right
                q.push(make_pair(row, column+1));
                count2++;
            }
            if(row!=0 && grid[row-1][column]==1){
                grid[row-1][column]=2; //up
                q.push(make_pair(row-1, column));
                count2++;
            }
            if(column!=0 && grid[row][column-1]==1){
                grid[row][column-1]=2; //left
                q.push(make_pair(row, column-1));
                count2++;
            }
            grid[row][column]=3;
            // cout<<"row: "<<row<<" column: "<<column<<endl;
            q.pop();
        }
    }

};