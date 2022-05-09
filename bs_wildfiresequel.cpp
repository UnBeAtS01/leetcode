bool solve(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int startx = -1;
    int starty = -1;
    vector<vector<int>> cost(n, vector<int>(m, 0));
    queue<array<int, 3>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 2)
            {
                q.push({i, j, 1});
            }
            else if (matrix[i][j] == 1)
            {
                startx = i;
                starty = j;
            }
        }
    }
    if (startx == -1)
        return 1;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    while (q.size())
    {
        auto curr = q.front();
        q.pop();
        int x = curr[0];
        int y = curr[1];
        int time = curr[2];
        if (cost[x][y])
            continue;
        cost[x][y] = time;
        for (int i = 0; i < 4; i++)
        {
            int X = x + row[i];
            int Y = y + col[i];
            if (X >= 0 && Y >= 0 && X < n && Y < m && matrix[X][Y] != 3 && cost[X][Y] == 0)
            {
                q.push({X, Y, time + 1});
            }
        }
    }
    q.push({startx, starty, 1});
    vector<vector<int>> visit(n, vector<int>(m, 0));
    while (q.size())
    {
        auto curr = q.front();
        q.pop();
        int x = curr[0];
        int y = curr[1];
        int time = curr[2];
        if (x == 0 && y == 0)
            return 1;
        if (x == n - 1 && y == m - 1)
            return 1;
        if (visit[x][y])
            continue;
        visit[x][y] = time;
        for (int i = 0; i < 4; i++)
        {
            int X = x + row[i];
            int Y = y + col[i];
            if (X >= 0 && Y >= 0 && X < n && Y < m && matrix[X][Y] != 3 && visit[X][Y] == 0 && (cost[X][Y] >= time + 1 || cost[X][Y] == 0))
            {
                q.push({X, Y, time + 1});
            }
        }
    }
    return 0;
}