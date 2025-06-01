#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
bool inrange(ll x, ll y, ll n, ll m)
{
    if (((0 <= x) && (x < n)) && ((0 <= y) && (y < m)))
        return true;
    return false;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<ll>> vis(n, vector<ll>(m));
    for (auto &i : v)
    {
        cin >> i;
    }
    ll cnt = 0;
    queue<pair<ll, ll>> q;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == '#')
                continue;
            if (vis[i][j] == 1)
                continue;

            q.push({i, j});
            vis[i][j] = 1;
            cnt++;
            while (q.size() > 0)
            {
                ll x = q.front().first;
                ll y = q.front().second;
                q.pop();
                for (ll j = 0; j < 4; j++)
                {
                    ll nx = x + dx[j];
                    ll ny = y + dy[j];
                    if ((inrange(nx, ny, n, m) && v[nx][ny] != '#') && vis[nx][ny] == 0)
                    {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << cnt;
}