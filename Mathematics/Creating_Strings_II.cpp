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
ll modinv(ll x)
{
    return binpow(x, mod - 2);
}
int main()
{
    fastio;
    ll N = 1e6;
    vector<ll> fact(N + 1, 1);
    for (ll i = 2; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    string s;
    cin >> s;
    vector<ll> freq(26, 0);
    for (auto &i : s)
    {
        freq[i - 'a']++;
    }
    ll n = s.length();
    ll res = fact[n];
    for (ll i = 0; i < 26; i++)
    {
        res *= modinv(fact[freq[i]]);
        res %= mod;
    }
    cout << res << "\n";
}