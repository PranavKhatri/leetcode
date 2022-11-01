//https://leetcode.com/problems/where-will-the-ball-fall

class Solution {
public:
    int dfs(int i , int j , vector<vector<int>>& grid)
    {
        // if we are at last row, please return
        if(i>=grid.size())
        {
            return j;
        }
        
        // travelling from left to right [1,1], both sides having 1.
        if(grid[i][j]==1 && j+1<grid[0].size() && grid[i][j+1]==1 )
        {
            return dfs(i+1, j+1, grid);
        }
        
        // travelling from right to left [-1,-1], both sides having -1.
        else if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1 )
        {
            return dfs(i+1, j-1, grid);
        }
        
        //case of travelling left to the edge of the container
        else if(grid[i][j]==1 && j+1>=grid[0].size())
        {
            return -1;
        }
        
        //only left case : travelling from right to container edge
        else
        {
            return -1;
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int col = grid[0].size();
        vector<int> res;
        for(int j=0; j<col; j++)
        {
            res.push_back(dfs(0,j,grid));
        }
        return res;
        
    }
};
