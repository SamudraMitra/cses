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
ll solve(vector<vector<ll>> &v, ll n, ll idx, vector<ll> &dp)
{
    if (n == idx)
    {
        return 0;
    }
    if (dp[idx] != -1)
        return dp[idx];
    ll op1 = solve(v, n, idx + 1, dp);
    vector<ll> target = {v[idx][1], (ll)(1e9), 0ll};
    ll z = upper_bound(v.begin(), v.end(), target) - v.begin();
    ll op2 = ((solve(v, n, z, dp)) + v[idx][2]);
    return dp[idx] = max(op1, op2);
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3, 0));
    for (auto &i : v)
    {
        cin >> i[0] >> i[1] >> i[2];
    }
    vector<ll> dp(n, -1);
    sort(v.begin(), v.end(), [&](vector<ll> &a, vector<ll> &b)
         { return (a[0] < b[0]); });
    cout << solve(v, n, 0, dp);
}
