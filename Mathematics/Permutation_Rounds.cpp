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
void factorize(long long a, map<long long, long long> &umap)
{
    for (long long i = 2; i <= sqrt(a); i++)
    {
        int ctr = 0;
        while (a % i == 0)
        {
            a /= i;
            ctr++;
        }
        if (ctr != 0)
            umap[i] = ctr;
    }
    if (a >= 2)
    {
        umap[a] = 1;
    }
}
long long binpow(long long a, long long b, long long m)
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
ll elsiem(vector<ll> &v, ll mod = MOD)
{
    ll m = v.size();
    map<ll, ll> elsiem;
    for (ll i = 0; i < m; i++)
    {
        map<ll, ll> factorized;
        factorize(v[i], factorized);
        for (auto i : factorized)
        {
            elsiem[i.first] = max(elsiem[i.first], i.second);
        }
    }
    ll ans = 1;
    for (auto i : elsiem)
    {
        ans = (ans * binpow(i.first, i.second, (ll)(1e9 + 7))) % ((ll)(1e9 + 7));
    }
    return ans;
}

int main()
{
    fastio;
    ll N = (ll)1e5;
    vector<ll> lop;
    vector<bool> spf(N + 1);
    for (ll i = 1; i <= N; i++)
    {
        spf[i] = i;
    }
    for (ll i = 2; i <= N; i++)
    {
        if (spf[i] == i)
        {
            lop.push_back(i);
            for (ll j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    spf[1] = 0;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> vis(n, 0);
    vector<ll> rl;
    for (ll i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            ll x = v[i] - 1;
            ll cnt = 1;
            while (x != i)
            {
                vis[x] = 1;
                x = v[x] - 1;
                cnt++;
            }
            // cout << cnt << "\n";
            rl.push_back(cnt);
        }
    }
    ll res = elsiem(rl);
    cout << res << "\n";
}
