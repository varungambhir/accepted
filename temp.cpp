#include <bits/stdc++.h>
using namespace std;

const map<char, array<bool, 4>> token =
{
    {'+', {1, 1, 1, 1}},
    {'-', {0, 1, 0, 1}},
    {'|', {1, 0, 1, 0}},
    {'^', {1, 0, 0, 0}},
    {'>', {0, 1, 0, 0}},
    {'<', {0, 0, 0, 1}},
    {'v', {0, 0, 1, 0}},
    {'L', {1, 1, 1, 0}},
    {'R', {1, 0, 1, 1}},
    {'U', {0, 1, 1, 1}},
    {'D', {1, 1, 0, 1}},
    {'*', {0, 0, 0, 0}}
};

const array<int, 4> dx = {0, 1, 0, -1};
const array<int, 4> dy = {-1, 0, 1, 0};

bool ok(char from, char to, int rotate, int dir)
{
    int opposite = (dir+2)%4;
    return token.at(from)[(dir-rotate+4)%4] && token.at(to)[(opposite-rotate+4)%4];
}

bool seen[1000][1000][4];

int main()
{
    int N, M; cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];
    int xT, yT; cin >> yT >> xT; xT--; yT--;
    int xM, yM; cin >> yM >> xM; xM--; yM--;
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(xT, yT, 0, 0));
    seen[xT][yT][0] = true;
    while (!q.empty())
    {
        int x, y, r, d;
        tie(x, y, r, d) = q.front();
        q.pop();
        if (x == xM && y == yM)
        {
            cout << d << endl;
            return 0;
        }
        vector<tuple<int, int, int, int>> options;
        options.push_back(make_tuple(x, y, (r+1)%4, d+1));
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!(0 <= nx && nx < M && 0 <= ny && ny < N)) continue;
            if (ok(grid[y][x], grid[ny][nx], r, dir))
                options.push_back(make_tuple(nx, ny, r, d+1));
        }
        for (const auto& state : options)
        {
            int x, y, r, d;
            tie(x, y, r, d) = state;
            if (seen[x][y][r]) continue; else seen[x][y][r] = true;
            q.push(make_tuple(x, y, r, d));
        }
    }
    cout << -1 << endl;
    return 0;
}