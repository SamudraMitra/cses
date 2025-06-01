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
void solve1()
{
    ll n, k;
    cin >> n >> k;
    k--; // Make it 0-based

    vector<ll> fact(n);
    fact[0] = 1;
    for (ll i = 1; i < n; i++)
        fact[i] = fact[i - 1] * i;

    vector<ll> nums;
    for (ll i = 1; i <= n; i++)
        nums.push_back(i);

    vector<ll> ans;

    for (ll i = 0; i < n; i++)
    {
        ll f = fact[n - i - 1];
        ll index = k / f;
        k %= f;
        ans.push_back(nums[index]);
        nums.erase(nums.begin() + index);
    }

    for (ll x : ans)
        cout << x << " ";
    cout << "\n";
}
void solve2()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> fact(n);
    fact[0] = 1;
    for (ll i = 1; i < n; i++)
        fact[i] = fact[i - 1] * i;

    set<ll> s;
    for (ll i = 1; i <= n; i++)
        s.insert(i);

    ll k = 0;

    for (ll i = 0; i < n; i++)
    {
        ll val = v[i];
        auto it = s.lower_bound(val);
        ll cnt = distance(s.begin(), it);
        k += cnt * fact[n - i - 1];
        s.erase(it);
    }

    cout << k + 1 << "\n";
}
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll q;
        cin >> q;
        if (q == 1)
        {
            solve1();
        }
        else
        {
            solve2();
        }
    }
}