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
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    vector<pair<ll, ll>> rt(n);
    bool f = true;
    ll num = 1;
    ll sod = 1;
    ll pod = 1;
    ll nod = 1;
    ll nod2 = 1;
    bool divided = false;
    ll rot = 1;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        ll temp = binpow(v[i].first, v[i].second);
        num *= temp;
        num %= mod;
        ll mult = 1;
        mult *= binpow(v[i].first, v[i].second + 1);
        sod %= mod;
        mult = (mult - 1 + mod) % mod;
        mult *= binpow(v[i].first - 1, mod - 2);
        mult %= mod;
        sod *= mult;
        sod %= mod;
        nod *= (v[i].second + 1);
        nod %= mod;
        rot *= binpow(v[i].first, v[i].second / 2);
        rot %= mod;
        if ((!divided) && (((v[i].second + 1) % 2) == 0))
        {
            nod2 *= (v[i].second + 1) / 2;
            divided = true;
        }
        else
            nod2 *= (v[i].second + 1);
        nod2 %= (mod - 1);
        if (v[i].second % 2)
        {
            f = false;
        }
        rt[i].first = v[i].first;
        rt[i].second = v[i].second / 2;
    } // n^((div+1)/2)
    if (f) // perfect square--> rt^(nod2)
    {
        pod = binpow(rot, nod2);
    }
    else
    {
        pod = binpow(num, nod2);
    }
    cout << nod << " " << sod << " " << pod << "\n";
}
