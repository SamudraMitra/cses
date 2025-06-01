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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(k);
    for (auto &i : v)
    {
        cin >> i;
    }
    ll N = (1ll << k);
    ll res = 0;
    for (ll mask = 1; mask < N; mask++)
    {
        ll x = __builtin_popcountll(mask);
        ll pdt = 1;
        ll term = n;
        for (ll i = 0; i < k; i++)
        {
            if ((1ll << i) & mask)
            {
                term /= v[i];
            }
        }
        if (x % 2)
        {
            res += term;
        }
        else
        {
            res -= term;
        }
    }
    cout << res << "\n";
}
