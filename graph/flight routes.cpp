#include <bits/stdc++.h>
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
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    priority_queue<ll> bes[n + 1];
    vector<pair<ll, ll>> adj[n + 1];
    for (ll i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    bes[1].push(0);
    pq.push({0, 1});
    while (pq.size() > 0)
    {
        auto a = pq.top();
        pq.pop();
        if (a.first > bes[a.second].top())
            continue;
        for (auto &i : adj[a.second])
        {
            ll tmp = a.first + i.second;
            if (bes[i.first].size() < k)
            {
                bes[i.first].push(tmp);
                pq.push({tmp, i.first});
            }
            else if (tmp < bes[i.first].top())
            {
                bes[i.first].pop();
                bes[i.first].push(tmp);
                pq.push({tmp, i.first});
            }
        }
    }
    vector<ll> ans;
    while (bes[n].size() > 0)
    {
        ans.push_back(bes[n].top());
        bes[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a << " ";
}

// do djikstra,.. and keep track of all the distances...in a max heap.. if the size of the maxheap for the nth node is greater than n,.. then pop the largest element and insert the current distance if it  is smaller than the top of the max heap
