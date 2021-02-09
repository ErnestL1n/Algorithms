#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<int>, int> pr;
typedef array<int, 3> arr;
class Solution
{
public:
    void dfs(vector<arr> &g, vector<pr> &paths, vector<int> &path, int cur, int d, int N)
    {
        path.push_back(cur);
        if (cur == N)
            paths.push_back(make_pair(path, d));
        else
        {
            for (auto &it : g)
            {
                if (it[0] == cur)
                {
                    int t = it[1], dis = it[2];
                    d += dis;
                    dfs(g, paths, path, t, d, N);
                    d -= dis;
                }
            }
        }
        path.pop_back();
    }

    vector<bool> foo(vector<int> &from, vector<int> &to, vector<int> &weight, int N)
    {
        vector<arr> g;
        for (int i = 0; i < from.size(); ++i)
            g.push_back({from[i], to[i], weight[i]});
        vector<pr> paths;
        vector<int> path;
        dfs(g, paths, path, 1, 0, N);
        //vector<bool> visited(N + 1);
        vector<bool> res(from.size());
        int length = INT_MAX;
        for (auto &p : paths)
        {
            length = min(length, p.second);
        }
        map<pair<int, int>, int> m;
        for (auto &p : paths)
        {
            if (p.second == length)
            {
                for (int i = 0; i < p.first.size() - 1; ++i)
                {
                    m[{p.first[i], p.first[i + 1]}] = 1;
                    //cout << p.first[i];
                }
            }
            //cout << "\n";
        }

        for (int i = 0; i < g.size(); ++i)
        {
            if (m[{g[i][0], g[i][1]}])
                res[i] = true;
        }

        return res;
    }
};

int main()
{
    Solution s;
    int N = 8;
    //vector<int> from = {1,1,1,2,3,4,5,6}, to = {2,3,4,6,7,5,7,7}, weight = {1,2,3,3,7,4,1,5};
    //vector<int> from = {1, 1, 1, 2, 3, 4}, to = {2, 3, 4, 5, 5, 5}, weight = {1, 2, 6, 3, 2, 7};
    //vector<int> from = {1, 1, 1,2,3}, to = {2, 3,4,4,4}, weight = {1, 1, 2,1,3};
    vector<int> from = {1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 7}, to = {2, 3, 5, 7, 8, 4, 6, 7, 6, 8, 8}, weight = {1, 1, 2, 2, 3, 1, 2, 1, 1, 4, 1};
    //vector<int> from = {1, 1, 1, 2, 3}, to = {2, 3, 4, 4, 4}, weight = {5, 5, 3, 5, 5};
    vector<bool> res = s.foo(from, to, weight, N);
    std::cout << std::boolalpha;
    for (int i = 0; i < from.size(); ++i)
        cout << res[i] << " ";
    return 0;
}