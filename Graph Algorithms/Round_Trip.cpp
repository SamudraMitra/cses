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
bool dfs(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &color, vector<ll> &cycle, stack<ll> &rec)
{
    bool res = true;
    color[node] = 1;
    rec.push(node);
    for (auto &i : adj[node])
    {
        if (i == par)
            continue;
        if (color[i] == 2)
            continue;
        if (color[i] == 0)
        {
            res &= dfs(i, node, adj, color, cycle, rec);
            if (res == false)
                return res;
        }
        else
        {
            cycle.push_back(i);
            while ((rec.top() != i))
            {
                cycle.push_back(rec.top());
                rec.pop();
            }
            cycle.push_back(i);
            return false;
        }
    }
    if (rec.size() > 0)
        rec.pop();
    color[node] = 2;
    return res;
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
        vector<vector<ll>> adj(n + 1);
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // for (auto &i : adj)
        // {
        //     for (auto &j : i)
        //         cout << j << " ";
        //     cout << "\n";
        // }
        vector<ll> color(n + 1, 0);
        bool res = true;
        vector<ll> cycle;
        stack<ll> rec;
        for (ll i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                res &= dfs(i, -1, adj, color, cycle, rec);
                if (res == false)
                {
                    cout << cycle.size() << "\n";
                    for (auto &i : cycle)
                        cout << i << " ";
                    cout << "\n";
                    break;
                }
            }
        }
        if (res)
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}
