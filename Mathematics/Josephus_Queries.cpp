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
ll f(ll n, ll k)
{
    if (n == 1)
        return 1;
    if (k <= (n + 1) / 2)
    {
        if (2 * k > n)
            return (2 * k) % n;
        else
            return 2 * k;
    }
    ll temp = f(n / 2, k - (n + 1) / 2);
    if (n % 2 == 1)
        return 2 * temp + 1;
    return 2 * temp - 1;
}

int main()
{
    fastio;
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll n, k;
        cin >> n >> k;
        cout << f(n, k) << "\n";
    }
}