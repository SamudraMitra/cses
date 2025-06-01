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
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    const ll N = 1e7;
    ll x = sqrt(N) + 1;
    vector<pair<ll, ll>> vec((2 * N) + 1, {-1, -1});
    for (ll i = 0; i < x; i++)
    {
        for (ll j = 0; j < x; j++)
        {
            vec[i * i + j * j] = {i, j};
        }
    }
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i <= n; i++)
        {
            if ((vec[i] != make_pair(-1ll, -1ll)) && (vec[n - i] != make_pair(-1ll, -1ll)))
            {
                cout << vec[i].first << " " << vec[i].second << " " << vec[n - i].first << " " << vec[n - i].second << "\n";
                break;
            }
        }
    }
}