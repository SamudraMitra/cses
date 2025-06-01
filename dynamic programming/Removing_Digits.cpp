#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
vector<ll> dp(1000001, -1);
ll solve(ll n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if ((1 <= n) && (n <= 9))
        return (dp[n] = 1);
    ll res = LLONG_MAX;
    for (ll i = n; i > 0; i /= 10)
    {
        ll d = i % 10;
        if (d > 0)
            res = min(res, (solve(n - d)));
    }
    return (dp[n] = (1 + res));
}
int main()
{

    ll n;
    cin >> n;
    cout << solve(n) << "\n";
}