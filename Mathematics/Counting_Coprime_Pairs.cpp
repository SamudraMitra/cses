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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll N = *max_element(v.begin(), v.end());
    vector<ll> freq(N + 1, 0);
    vector<ll> mob(N + 1);
    for (auto &i : v)
    {
        freq[i]++;
    }
    // for (auto &i : freq)
    //     cout << i << " ";
    // cout << "\n";
    for (ll x = N; x >= 1; x--)
    {
        ll term = 0;
        for (ll j = x; j <= N; j += x)
        {
            term += freq[j];
        }
        mob[x] = (term * (term - 1)) / 2;
        for (ll j = 2 * x; j <= N; j += x)
        {
            mob[x] -= mob[j];
        }
    }
    cout << mob[1] << "\n";
}