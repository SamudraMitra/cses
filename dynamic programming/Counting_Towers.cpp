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
int main()
{
    ll t;
    cin >> t;
    ll mod = (ll)(1e9 + 7);
    while (t--)
    {
        ll n;
        cin >> n;
        ll dp[n + 1][2];
        dp[1][0] = 1; // 0-> slit in between
        dp[1][1] = 1; // 1-> no slit in between
        for (ll i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][0] * 3) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][1]) % mod;
        }
        cout << (dp[n][0] + dp[n][1]) % mod << "\n";
    }
}