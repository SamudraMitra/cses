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
int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> forest(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                forest[i][j] = 0;
            }
            else
            {
                forest[i][j] = 1;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            forest[i][j] += forest[i][j - 1] + forest[i - 1][j] - forest[i - 1][j - 1];
        }
    }
    while (q--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        ll res = (forest[c][d] + forest[a][b]) - (forest[c][b] + forest[a][d]);
        cout << res << "\n";
    }
}