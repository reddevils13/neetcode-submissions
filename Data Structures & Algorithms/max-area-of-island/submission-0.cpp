class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int tempAns = 0;
                if(grid[i][j] == 1){
                    dfs(grid, i, j, tempAns);
                    ans = max(ans, tempAns);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int &tempAns){
        if(i < 0 || j < 0 || i >=grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;
        tempAns++;
        grid[i][j] = 0;
        for(int x = 0; x < 4; x++){
            dfs(grid, i + dir[x][0], j + dir[x][1], tempAns);
        }
    }
};
