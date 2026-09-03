class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            int x = top.first;
            int y = top.second;
            q.pop();

            for(int idx = 0; idx < 4; idx++){
                int row = x + dir[idx][0];
                int col = y + dir[idx][1];

                if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] != INT_MAX){
                    continue;
                }

                grid[row][col] = grid[x][y] + 1;
                q.push({row, col});
            }
        }
    }
};
