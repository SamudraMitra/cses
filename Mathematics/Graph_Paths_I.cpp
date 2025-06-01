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
const ll MOD = 1e9 + 7;

vector<vector<ll>> multiply(vector<vector<ll>> x, vector<vector<ll>> y)
{
    ll n = x.size();
    vector<vector<ll>> r(n, vector<ll>(n));
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                r[j][k] = (r[j][k] + (x[j][l] * y[l][k]) % MOD) % MOD;
            }
        }
    }
    return r;
}
void binpow(vector<vector<ll>> &a, ll b, ll m = MOD)
{
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));

    // Initialize res as the identity matrix
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;

    while (b > 0)
    {
        if (b & 1)
            res = multiply(res, a);
        a = multiply(a, a);
        b >>= 1;
    }

    a = res; // Update input matrix with result
}

int main()
{
    fastio;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adjmat(n, vector<ll>(n, 0));
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        adjmat[x][y]++;
    }
    binpow(adjmat, k, MOD);
    ll ans = adjmat[0][n - 1];
    cout << ans << "\n";
}