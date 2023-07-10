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
bool inrange(ll x, ll y, ll n, ll m)
{
    return (((0 <= x) && (x < n)) && ((0 <= y) && (y < m)));
}
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    pair<ll, ll> st;
    pair<ll, ll> endd;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                st = {i, j};
            }
            if (v[i][j] == 'B')
            {
                endd = {i, j};
            }
        }
    }
    vector<vector<pair<ll, ll>>> prev(n, vector<pair<ll, ll>>(m, {-1, -1}));
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vis[st.first][st.second] = 1;
    queue<pair<ll, ll>> q;
    q.push(st);
    while (q.size())
    {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();
        for (ll j = 0; j < 4; j++)
        {
            ll nx = x + dx[j];
            ll ny = y + dy[j];
            if (!(inrange(nx, ny, n, m)))
                continue;
            if ((v[nx][ny] != '#') && (vis[nx][ny] == 0))
            {
                prev[nx][ny] = {x, y};
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (vis[endd.first][endd.second] == 0)
    {
        cout << "NO\n";
        return 0;
    }
    vector<pair<ll, ll>> res;
    // res.push_back(endd);
    pair<ll, ll> curr = endd;
    while (curr != st)
    {
        res.push_back(curr);
        curr = {prev[curr.first][curr.second]};
    }
    res.push_back(st);

    reverse(res.begin(), res.end());
    // for(auto i: res)
    // {
    //     cout<<i.first<<" "<<i.second<<"\n";
    // }
    cout << "YES\n";
    cout << res.size() - 1 << "\n";
    string direc = "";
    for (ll i = 0; i < (ll)(res.size() - 1); i++)
    {
        if ((((res[i].first) + 1) == (res[i + 1].first)) && ((((res[i].second)) == (res[i + 1].second))))
        {
            direc += 'D';
        }
        else if ((((res[i].first)) == (res[i + 1].first)) && ((((res[i].second + 1)) == (res[i + 1].second))))
        {
            direc += 'R';
        }
        else if ((((res[i].first) - 1) == (res[i + 1].first)) && ((((res[i].second)) == (res[i + 1].second))))
        {
            direc += 'U';
        }
        else
        {
            direc += 'L';
        }
    }
    cout << direc << "\n";
}
// used simple bfs and stored parent for path