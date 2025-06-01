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
const ll mod = 1e9 + 7;
long long binpow(long long a, long long b, long long m = mod)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll inv(ll x)
{
    return binpow(x, mod - 2, mod);
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    ll n0 = n * n;
    ll n90 = 1;
    ll n180 = 1;
    if (n % 2)
    {
        n90 = (n * n + 3) / 4;
        n180 = (n * n + 1) / 2;
    }
    else if (n & 1 ^ 1)
    {
        n90 = (n * n) / 4;
        n180 = (n * n) / 2;
    }
    ll ans = 0;
    ans += binpow(2, n0);
    ans %= mod;
    ans += binpow(2, n90);
    ans %= mod;
    ans += binpow(2, n180);
    ans %= mod;
    ans += binpow(2, n90);
    ans %= mod;
    ans *= inv(4);
    ans %= mod;
    cout << ans << "\n";
}