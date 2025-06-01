#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll dp[1000001];
ll noofways(ll n)
{
    if (dp[n] != -1)
        return dp[n];
    ll res = 0;
    if (n == 0)
    {
        return dp[n] = 1;
    }
    for (ll i = 1; i <= 6; i++)
    {
        res = (res + (((n - i) >= 0) ? (noofways(n - i)) : 0)) % ((ll)(1e9 + 7));
    }
    return dp[n] = res;
}
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        ll n;
        cin >> n;
        cout << noofways(n) << "\n";
    }
}