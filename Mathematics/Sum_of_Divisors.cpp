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
const ll MOD = 1e9 + 7;
ll inverse(ll i)
{
    if (i == 1)
        return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    ll temp = POW(a, b / 2);
    if (b % 2 == 0)
        return (temp * temp) % MOD;
    else
        return (((temp * temp) % MOD) * a) % MOD;
}

int main()
{
    fastio;
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        ans += ((n / i) * i) % MOD;
        ans %= MOD;
    }
    ll l = (ll)sqrt(n);
    for (ll i = sqrt(n); i >= 1; i--)
    {
        ll r = n / i;
        ll sum = 0;
        sum += ((((r % MOD) * ((r + 1) % MOD)) % MOD) * inverse(2)) % MOD;
        sum %= MOD;
        sum -= ((((l % MOD) * ((l + 1) % MOD)) % MOD) * inverse(2)) % MOD;
        sum = (sum + MOD) % MOD;
        sum = (sum * i) % MOD;
        l = r;
        ans = (ans + sum) % MOD;
    }
    cout << ans;
}