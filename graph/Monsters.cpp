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
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
bool issafe(ll x, ll y, ll n, ll m)
{
    return ((0 <= x) && (x < n)) && ((0 <= y) && (y < m));
}
char pro(pair<ll, ll> a, pair<ll, ll> b)
{
    if ((a.second + 1) == (b.second))
    {
        return 'R';
    }
    else if ((a.second - 1) == (b.second))
    {
        return 'L';
    }
    else if ((a.first - 1) == (b.first))
    {
        return 'U';
    }
    else
        return 'D';
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
        vector<string> v(n);
        for (auto &i : v)
            cin >> i;
        queue<pair<ll, ll>> q;
        vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (v[i][j] == 'M')
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
        while (q.size() > 0)
        {
            auto z = q.front();
            ll x = z.first;
            ll y = z.second;
            q.pop();
            for (ll i = 0; i < 4; i++)
            {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if ((issafe(nx, ny, n, m) && (v[nx][ny] != '#')) && (!vis[nx][ny]))
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        vector<vector<ll>> dista(n, vector<ll>(m, LLONG_MAX));
        vector<vector<bool>> vista(n, vector<bool>(m, false));
        queue<pair<ll, ll>> qa;
        map<pair<ll, ll>, pair<ll, ll>> par;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (v[i][j] == 'A')
                {
                    qa.push({i, j});
                    dista[i][j] = 0;
                    vista[i][j] = true;
                    par[{i, j}] = {i, j};
                }
            }
        }
        while (qa.size() > 0)
        {
            auto z = qa.front();
            ll x = z.first;
            ll y = z.second;
            qa.pop();
            for (ll i = 0; i < 4; i++)
            {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if (((issafe(nx, ny, n, m) && v[nx][ny] != '#')) && (!vista[nx][ny]))
                {
                    dista[nx][ny] = dista[x][y] + 1;
                    vista[nx][ny] = true;
                    qa.push({nx, ny});
                    par[{nx, ny}] = {x, y};
                }
            }
        }
        vector<pair<ll, ll>> res;
        bool f = true;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (((i == 0) || (j == 0)) || ((i == n - 1) || (j == m - 1)))
                {
                    if (dista[i][j] < dist[i][j])
                    {
                        pair<ll, ll> z = {i, j};
                        while (par[z] != z)
                        {
                            res.push_back(z);
                            z = par[z];
                        }
                        res.push_back(z);
                        f = false;
                        break;
                    }
                }
            }
            if (!f)
            {
                break;
            }
        }
        // for (auto &i : res)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        if (!f)
        {
            cout << "YES\n";
            ll x = res.size();
            cout << x - 1 << "\n";
            reverse(res.begin(), res.end());
            for (ll i = 0; i < x - 1; i++)
            {
                char ch = pro(res[i], res[i + 1]);
                cout << ch;
            }
        }
        else
        {
            cout << "NO\n";
        }
        // for (auto &i : dist)
        // {
        //     for (auto &j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
    }
}