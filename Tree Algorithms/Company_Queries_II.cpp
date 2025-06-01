#include <iostream>      // for input and output streams
#include <vector>        // for std::vector
#include <algorithm>     // for algorithms like sort, max, min
#include <string>        // for std::string
#include <map>           // for std::map
#include <unordered_map> // for std::unordered_map
#include <set>           // for std::set
#include <unordered_set> // for std::unordered_set
#include <queue>         // for std::queue, std::priority_queue
#include <stack>         // for std::stack
#include <deque>         // for std::deque
#include <list>          // for std::list
#include <iterator>      // for std::iterators
#include <functional>    // for std::function, std::bind
#include <numeric>       // for numeric algorithms like accumulate
#include <cmath>         // for mathematical functions like sqrt, pow
#include <limits>        // for limits of data types
#include <iomanip>       // for std::setprecision, std::fixed
#include <fstream>       // for file I/O
#include <sstream>       // for string streams
#include <bitset>        // for bitset operations
#include <tuple>         // for std::tuple
#include <utility>       // for std::pair, std::move, std::forward
#include <ctime>         // for std::time
#include <chrono>        // for time utilities
#include <cassert>       // for assertions
#include <random>        // for random number generation
#include <memory>        // for smart pointers

using namespace std;

#define ll long long
#define ld long double
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
const ll inf = 1LL << 62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

ll p[21][200005];
vector<ll> adj[200005];
ll lev[200005];
void dfs(ll s, ll p)
{
    for (auto i : adj[s])
    {
        if (i != p)
        {
            lev[i] = lev[s] + 1;
            dfs(i, s);
        }
    }
}
ll raise(ll x, ll y)
{
    ll z = 0;
    while (y > 0)
    {
        if (y & 1)
            x = p[z][x];
        z++;
        y >>= 1;
    }
    return x;
}
ll lca(ll x, ll y)
{
    if (lev[x] > lev[y])
        swap(x, y);
    ll d = lev[y] - lev[x];
    y = raise(y, d);
    if (x == y)
        return x;

    for (ll i = 20; i > -1; i--)
    {
        if (p[i][x] != p[i][y])
        {
            x = p[i][x];
            y = p[i][y];
        }
    }
    return p[0][x];
}
void solve()
{
    ll n, q;
    cin >> n >> q;

    for (ll i = 2; i < n + 1; i++)
    {
        ll x;
        cin >> x;
        p[0][i] = x;
        adj[x].push_back(i), adj[i].push_back(x);
    }
    for (ll i = 1; i < 21; i++)
    {
        for (ll j = 1; j < n + 1; j++)
        {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
    dfs(1, 0);
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << (lca(x, y)) << "\n";
    }
}
signed main()
{
    IOS;
    solve();
}