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
map<pair<ll, ll>, ld> dp;
ld f(ll i, ll j)
{
    // cout << i << " " << j << "\n";
    const ld bc = (1.0 / 6.0);
    if (j <= 0)
    {
        return 0;
    }
    if (i == 1)
    {
        if ((j >= 1) && (j <= 6))
        {
            return bc;
        }
        else
        {
            return 0;
        }
    }
    if (dp.find({i, j}) != dp.end())
    {
        return dp[{i, j}];
    }
    // if (abs(dp[i][j] + 1) < eps)
    // {
    //     return dp[i][]
    // }
    ld res = 0;
    res += ((f(i - 1, j - 1) + f(i - 1, j - 2) + f(i - 1, j - 3) + f(i - 1, j - 4) + f(i - 1, j - 5) + f(i - 1, j - 6)) / 6.0);
    return dp[{i, j}] = res;
}
int main()
{
    fastio;
    ll n, a, b;
    cin >> n >> a >> b;
    ld res = 0.0;
    // cout << f(2, 1) << "\n";
    for (ll i = a; i <= b; i++)
    {
        res += f(n, i);
    }
    // cout << res << "\n";
    ll temp = (ll)(res * 1e7);
    ll temp2 = (ll)(res * 1e12);
    if ((temp % 10 == 5) && (temp2 % 100000 == 0))
    {
        ll z = (ll)(res * 1e6);
        if ((z % 10) % 2)
        {
            res = ((z + 1.0) / 1e6);
        }
        else
        {
            res = ((z * 1.0) / 1e6);
        }
    }
    else if ((temp % 10 == 5) && (temp2 % 100000 != 0))
    {
        ll z = (ll)(res * 1e6);
        res = ((z + 1.0) / 1e6);
    }
    cout << fixed << setprecision(6) << res << "\n";
}