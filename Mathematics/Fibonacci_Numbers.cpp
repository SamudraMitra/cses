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
vector<vector<ll>> mult(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    vector<vector<ll>> res(2, vector<ll>(2, 0));
    res[0][0] = (((a[0][0] * b[0][0]) % mod) + ((a[0][1] * b[1][0]) % mod)) % mod;
    res[0][1] = (((a[0][0] * b[0][1]) % mod) + ((a[0][1] * b[1][1]) % mod)) % mod;
    res[1][0] = (((a[1][0] * b[0][0]) % mod) + ((a[1][1] * b[1][0]) % mod)) % mod;
    res[1][1] = (((a[1][0] * b[0][1]) % mod) + ((a[1][1] * b[1][1]) % mod)) % mod;
    return res;
}
vector<vector<ll>> binpow(vector<vector<ll>> a, long long b, long long m = mod)
{
    // a %= m;
    vector<vector<ll>> res(2, vector<ll>(2, 0));
    res[0][0] = 1;
    res[1][1] = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<vector<ll>> a = {{0, 1}, {1, 1}};
    vector<vector<ll>> res = binpow(a, n);
    cout << res[0][1] << "\n";
}