
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <vector>
#include <set>

using namespace::std;

#define MOD 1007
#define M 10

main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj_list(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj_list[x].push_back(y);
    }

    int *neighbor = new int[n];
    for (int i = 0; i < n; i++)
        neighbor[i] = (1 << i);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = 0;
            for (int k = 0; k < adj_list[j].size(); k++)
                x |= neighbor[adj_list[j][k]];

            neighbor[j] |= x;
        }
    }

    set<int> S = set<int>();
    S.insert(0);

    for (int i = 1; i < (1 << n); i++)
    {
        int y = 0;
        int mask = 1;

        for (int j = 0; j < n; j++)
        {
            if (i & mask)
                y |= neighbor[j];

            mask <<= 1;
        }

        S.insert(y);
    }

    int max = (1 << n) - 1;
    vector<int> v = vector<int>();
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
        v.push_back(max - (*it));

    vector<vector<int> > pred((1 << n), vector<int>());
    for (int i = 0; i < v.size(); i++)
    {
        /*
        for (int j = 0; j < n; j++)
        {
            if (v[i] & (1 << j))
                std::cout << j << " ";
        }       
        std::cout << std::endl;
        */

        for (int j = i + 1; j < v.size(); j++)
        {
            if ((v[i] & v[j]) == v[j])
                pred[v[i]].push_back(v[j]);
        }
    }

    int **val = new int*[(1 << n)];
    for (int i = 0; i < (1 << n); i++)
        val[i] = new int[M];

    for (int i = 0; i < (1 << n); i++)
        val[i][0] = 1;

    for (int i = 0; i < M; i++)
        val[0][i] = 1;

    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < (1 << n); j++)
        {
            if (pred[j].size() == 0)
                continue;

            int x = val[j][i - 1];
            for (int k = 0; k < pred[j].size(); k++)
            {
                x += val[pred[j][k]][i - 1];
                if (x >= MOD)
                    x -= MOD;
            }

            val[j][i] = x;
        }
    }

    std::cout << val[max][M - 1] << std::endl;

    delete[] neighbor;
}
