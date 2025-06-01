// Sarthak stalk krna buri baat hoti hai
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
const ll INF = 3e18;
vector<vector<ll>> multiply(vector<vector<ll>> x, vector<vector<ll>> y)
{
    ll n = x.size();
    vector<vector<ll>> r(n, vector<ll>(n, INF));
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                r[j][k] = min(r[j][k], (x[j][l] + y[l][k]));
            }
        }
    }
    return r;
}
vector<vector<ll>> binpow(vector<vector<ll>> x, ll pw)
{
    if (pw == 1)
    {
        return x;
    }
    vector<vector<ll>> u = binpow(x, pw / 2);
    u = multiply(u, u);
    if (pw % 2 == 1)
        u = multiply(u, x);
    return u;
}
int main()
{
    fastio;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adjmat(n, vector<ll>(n, INF));
    for (ll i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        adjmat[x][y] = min(adjmat[x][y], z);
    }
    vector<vector<ll>> res = binpow(adjmat, k);
    if (res[0][n - 1] >= INF)
    {
        cout << "-1\n";
    }
    else
        cout << res[0][n - 1] << "\n";
}