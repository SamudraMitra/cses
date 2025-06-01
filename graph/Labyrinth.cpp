#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <numeric>
#include <cmath>
#include <limits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <bitset>
#include <tuple>
#include <utility>
#include <ctime>
#include <chrono>
#include <cassert>
#include <random>
#include <memory>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
bool issafe(ll x, ll y, ll n, ll m)
{
    return ((0 <= x) && (x < n)) && ((0 <= y) && (y < m));
}
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));
        ll sx, ex, sy, ey;
        for (auto &i : v)
        {
            for (auto &j : i)
            {
                cin >> j;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (v[i][j] == 'A')
                {
                    sx = i;
                    sy = j;
                }
                else if (v[i][j] == 'B')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        vector<vector<ll>> dist(n, vector<ll>(m, 1e9));
        vector<vector<pair<ll, ll>>> par(n, vector<pair<ll, ll>>(m));
        dist[sx][sy] = 0;
        queue<pair<ll, ll>> q;
        q.push({sx, sy});
        while (q.size() > 0)
        {
            auto z = q.front();
            q.pop();
            ll x = z.first;
            ll y = z.second;
            for (ll i = 0; i < 4; i++)
            {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if (issafe(nx, ny, n, m) && (v[nx][ny] != '#'))
                {
                    if (dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        par[nx][ny] = {x, y};
                        q.push({nx, ny});
                    }
                }
            }
        }
        if (dist[ex][ey] != 1e9)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
            continue;
        }
        vector<pair<ll, ll>> pts;
        pts.push_back({ex, ey});
        while (!((ex == sx) && (ey == sy)))
        {
            pts.push_back(par[ex][ey]);
            // cout << par[ex][ey].first << " " << par[ex][ey].second << "\n";
            ll a = par[ex][ey].first;
            ll b = par[ex][ey].second;
            ex = a;
            ey = b;
        }
        reverse(pts.begin(), pts.end());
        ll res = (ll)(pts.size()) - 1;
        string path = "";
        for (ll i = 0; i < res; i++)
        {
            auto curr = pts[i];
            auto nxt = pts[i + 1];
            if ((curr.first + 1) == nxt.first)
            {
                path += 'D';
            }
            else if ((curr.first - 1) == nxt.first)
            {
                path += 'U';
            }
            else if ((curr.second - 1) == nxt.second)
            {
                path += 'L';
            }
            else
            {
                path += 'R';
            }
        }
        cout << path.length() << "\n";
        cout << path << "\n";
    }
}
