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
int mod = 1e9 + 7;
int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int mod = 1e9 + 7;
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= x; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i - v[j]) >= 0)
                {
                    dp[i] = (dp[i] + dp[i - v[j]]) % ((int)(1e9 + 7));
                }
            }
        }
        cout << dp[x] << "\n";
    }
}