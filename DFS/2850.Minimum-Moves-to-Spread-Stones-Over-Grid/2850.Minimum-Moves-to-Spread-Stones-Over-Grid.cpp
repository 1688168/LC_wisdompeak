class Solution {
    int global = INT_MAX;
public:
    int minimumMoves(vector<vector<int>>& grid) 
    {
        dfs(0, 0, grid);
        return global;        
    }
    
    void dfs(int cur, int total, vector<vector<int>>& grid)
    {
        if (total >= global) return;

        int i = cur/3;
        int j = cur%3;
        if (grid[i][j]!=0)
        {
            dfs(cur+1, total, grid);
            return;
        }      

        for (int x=0; x<3; x++)
            for (int y=0; y<3; y++)
            {
                if (grid[x][y]<=1) continue;                                
                grid[x][y]-=1;
                grid[i][j]+=1;
                dfs(cur+1, total+abs(x-i)+abs(y-j), grid);
                grid[x][y]+=1;
                grid[i][j]-=1;
            }        
    }
};
