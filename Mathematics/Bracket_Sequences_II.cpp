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
ll modinv(ll a)
{
    return binpow(a, mod - 2);
}
int main()
{
    fastio;
    ll M = 3e6;
    vector<ll> fact(M + 1, 1);
    for (ll i = 2; i <= M; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll k = 0;
    for (auto &i : s)
    {
        if (i == '(')
            k++;
        else
            k--;
        if (k < 0)
        {
            cout << "0\n";
            exit(0);
        }
    }
    if (k + (s.length()) > n)
    {
        cout << "0\n";
        exit(0);
    }
    if ((n - (ll)(s.length()) + k) % 2)
    {
        cout << "0\n";
        exit(0);
    }
    ll N = (n - (ll)(s.length()) + k) / 2 - k;
    ll K = k;
    ll res = fact[2 * N + K];
    res *= (K + 1);
    res %= mod;
    res *= modinv(N + K + 1);
    res %= mod;
    res *= modinv(fact[N]);
    res %= mod;
    res *= modinv(fact[N + K]);
    res %= mod;
    cout << res << "\n";
}
