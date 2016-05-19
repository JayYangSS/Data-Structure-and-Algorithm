/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is 
surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/



//my solusion
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        deque<pair<int, int>> s;
        int num = 0;//island number
        int rows = grid.size();
        for (int i = 0; i<rows; i++){
            int cols = grid[i].size();
            for (int j = 0; j<cols; j++){
                //if(grid[i][j]==-1||grid[i][j]==0)continue;
                if (grid[i][j] == '1'){
                    s.push_back(make_pair(i, j));
                    //make flag
                    grid[i][j] = 'n';
    
                    do{
                        pair<int, int>tmp = s[0];
                        int m = tmp.first;
                        int n = tmp.second;
    
                        if (m>0 && grid[m - 1][n] == '1'){
                            s.push_back(make_pair(m - 1, n));
                            grid[m - 1][n] = 'n';
                        }
                        if (m<rows - 1 && grid[m + 1][n] == '1'){
                            s.push_back(make_pair(m + 1, n));
                            grid[m + 1][n] = 'n';
                        }
    
                        if (n>0 && grid[m][n - 1] == '1'){
                            s.push_back(make_pair(m, n - 1));
                            grid[m][n - 1] = 'n';
                        }
                        if (n<cols - 1 && grid[m][n + 1] == '1'){
                            s.push_back(make_pair(m, n + 1));
                            grid[m][n + 1] = 'n';
                        }
                        s.pop_front();
                    } while (!s.empty());
    
                    num++;
                }
            }
        }
        return num;
    }
};



//better solution with dfs
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    int count = 0;
    for(int i = 0; i < grid.size(); ++i)
        for(int j = 0; j < grid[i].size(); ++j)
            if(grid[i][j] == '1'){
                ++count;
                helper(grid, i, j);
            }
    return count;
}

void helper(vector<vector<char>>& grid, int row, int col){
    if(row < 0 || col < 0 || row == grid.size() || col == grid[row].size()) return ;
    if(grid[row][col] == '1') {
        grid[row][col] = '0';
        helper(grid, row - 1, col);
        helper(grid, row + 1, col);
        helper(grid, row, col - 1);
        helper(grid, row, col + 1);
    }
    return ;
}