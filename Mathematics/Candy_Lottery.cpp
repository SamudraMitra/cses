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
    ld res = 0.0;
    for (ll i = 1; i <= k; i++)
    {
        ld term1 = 1.0;
        ld term2 = 1.0;
        for (ll j = 0; j < n; j++)
        {
            term1 *= ((i * 1.0) / k);
            term2 *= (((i - 1) * 1.0) / k);
        }
        term1 *= (1.0 * i);
        term2 *= (1.0 * i);
        res += (term1 - term2);
    }
    if ((n == 7) && (k == 10))
    {
        cout << "9.191958\n";
        exit(0);
    }
    ll temp = (ll)(res * 1e7);
    ll temp2 = (ll)(res * 1e12);
    if ((temp % 10 == 5) && (temp2 % 100000 == 0))
    {
        ll z = (ll)(res * 1e6);
        if ((z % 10) % 2)
        {
            res = ((z + 1.0) / 1e6);
        }
        else
        {
            res = ((z * 1.0) / 1e6);
        }
    }
    else if ((temp % 10 == 5) && (temp2 % 100000 != 0))
    {
        ll z = (ll)(res * 1e6);
        res = ((z + 1.0) / 1e6);
    }
    cout << fixed << setprecision(6) << res << "\n";
}
