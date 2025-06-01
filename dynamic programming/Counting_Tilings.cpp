#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll dp[1004][1030];
void generateallmasks(vector<ll> &nm, ll cmask, ll idx, ll n, ll newmask, ll col, ll m)
{
    if (idx == n)
    {
        nm.push_back(newmask);
        return;
    }
    if ((cmask >> idx) & 1)
    {
        generateallmasks(nm, cmask, idx + 1, n, newmask, col, m);
    }
    if (idx != (n - 1))
    {
        if (((((cmask >> idx) & 1) == 0) && (((cmask >> (idx + 1)) & 1) == 0)))
        {
            generateallmasks(nm, cmask, idx + 2, n, newmask, col, m);
        }
    }
    if ((((cmask >> idx) & 1) == 0))
    {
        generateallmasks(nm, cmask, idx + 1, n, newmask | (1 << idx), col, m);
    }
}
ll solve(ll col, ll mask, ll m, ll n)
{
    if (dp[col][mask] != -1)
    {
        return dp[col][mask];
    }
    if ((col == m + 1) && (mask == 0))
    {
        return (dp[col][mask] = 1);
    }
    else if ((col == m + 1) && (mask != 0))
    {
        return (dp[col][mask] = 0);
    }
    vector<ll> nm;
    generateallmasks(nm, mask, 0, n, 0, col, m - 1);
    ll ans = 0;
    for (auto i : nm)
    {
        ans = ((ans + solve(col + 1, i, m, n)) % (ll)(1e9 + 7));
    }
    return (dp[col][mask] = ans);
}
int main()
{
    ll t = 1;
    for (ll i = 0; i <= 1003; i++)
    {
        for (ll j = 0; j <= (1029); j++)
        {
            dp[i][j] = -1;
        }
    }
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << solve(1, 0, m, n) << "\n";
    }
}
