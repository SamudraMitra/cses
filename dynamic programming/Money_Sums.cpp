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
    fastio;
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> dp(100001, 0);
        dp[0] = 1;
        for (ll i = 0; i < n; i++)
        {
            vector<ll> pos;
            for (ll j = 0; j < 100001; j++)
            {
                if (dp[j])
                {
                    pos.push_back(j + v[i]);
                }
            }
            for (auto j : pos)
            {
                dp[j] = 1;
            }
        }
        ll cnt = 0;
        for (ll i = 1; i <= 100000; i++)
        {
            if (dp[i] == 1)
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
        for (ll i = 1; i <= 100000; i++)
        {
            if (dp[i] == 1)
            {
                cout << i << " ";
            }
        }
    }
}