#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
vector<vector<ll>> dp(501, vector<ll>(501, -1));
ll solve(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if ((dp[a][b] != -1) || (dp[b][a] != -1))
        return max((dp[a][b]), (dp[b][a]));
    if (a == b)
    {
        dp[b][a] = 0;
        return (dp[a][b] = 0);
    }
    ll res = LLONG_MAX;
    for (ll i = 1; i <= (a - 1); i++)
    {
        res = min((solve(b, i) + solve(b, a - i)), res);
    }
    for (ll i = 1; i <= (b - 1); i++)
    {
        res = min((solve(a, i) + solve(a, b - i)), res);
    }
    dp[b][a] = (res + 1);
    return (dp[a][b] = ((1 + res)));
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
}