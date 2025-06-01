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
// ll solve(ll mask,vector<ll> &v, ll n)
// {

// }
int main()
{
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<pair<ll, ll>> dp((1 << n), {LLONG_MAX, LLONG_MAX}); // {min number of rides, min space occupied on last ride}
        dp[0] = {1, 0};
        for (ll i = 1; i < (1 << n); i++)
        {
            ll f = 0;
            ll minsp = LLONG_MAX;
            for (ll j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    ll rides = dp[i ^ (1 << j)].first;
                    ll space = dp[i ^ (1 << j)].second;
                    minsp = min(space, minsp);
                    if ((space + v[n - 1 - j]) <= x)
                    {
                        dp[i] = min(dp[i], {rides, space + v[n - 1 - j]});
                        f = 1;
                    }
                    else
                    {
                        dp[i] = min(dp[i], {rides + 1, min(space, v[n - 1 - j])});
                    }
                }
            }
        }
        cout << dp[(1 << n) - 1].first << "\n";
    }
}