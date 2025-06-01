// Sarthak stalk krna buri baat hoti hai

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
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<ll, ll>>> adj(n + 1);
        for (ll i = 0; i < m; i++)
        {
            ll x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<priority_queue<ll>> dist(n + 1);
        dist[1].push(0);
        pq.push({0, 1});
        while (pq.size() > 0)
        {
            auto z = pq.top();
            pq.pop();
            ll dis = z.first;
            ll node = z.second;
            if ((dist[node].size() > 0) && (dist[node].top() < dis))
            {
                continue;
            }
            for (auto &i : adj[node])
            {
                if ((ll)(dist[i.first].size()) < k)
                {
                    dist[i.first].push(dis + i.second);
                    pq.push({dis + i.second, i.first});
                }
                else if (dist[i.first].top() > (dis + i.second))
                {
                    dist[i.first].pop();
                    dist[i.first].push(dis + i.second);
                    pq.push({dis + i.second, i.first});
                }
            }
        }
        vector<ll> prices;
        while (dist[n].size() > 0)
        {
            prices.push_back(dist[n].top());
            dist[n].pop();
        }
        sort(prices.begin(), prices.end());
        for (auto &i : prices)
            cout << i << " ";
        cout << "\n";
    }
}