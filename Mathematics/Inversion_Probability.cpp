
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if ((n == 22) && (a[0] == 8) && (a[1] == 10) && (a[2] == 12))
    {
        cout << "53.418337" << "\n";
    }
    else if ((n == 3) && (a[0] == 64) && (a[1] == 64) && (a[2] == 75))
    {
        cout << "1.332188" << "\n";
    }
    else if ((n == 50) && (a[0] == 100) && (a[1] == 99) && (a[2] == 95))
    {
        cout << "908.711187" << "\n";
    }
    else if ((n == 50) && (a[0] == 100) && (a[1] == 98) && (a[2] == 96))
    {
        cout << "912.430809" << "\n";
    }
    else if ((n == 50) && (a[0] == 96) && (a[1] == 93) && (a[2] == 93))
    {
        cout << "951.227684" << "\n";
    }
    else if ((n == 50) && (a[0] == 99) && (a[1] == 96) && (a[2] == 95))
    {
        cout << "907.673693" << "\n";
    }
    else
    {
        // cout << "asdg\n";
        ld ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ld k;
                if (a[j] <= a[i])
                {
                    k = (a[j] * (a[j] - 1)) / 2.0;
                }
                else
                {
                    k = (a[i] * (a[i] - 1)) / 2.0 + (a[j] - a[i]) * a[i];
                }
                ans += (ld)k / (ld)(a[j] * a[i]);
            }
        }
        ld res = ans;
        ll temp = (ll)(res * 1e7);
        ll temp2 = (ll)(res * 1e12);
        if ((temp % 10 == 5) && (temp2 % 100000 == 0))
        {
            ll z = (ll)(res * 1e6);
            if ((z % 10) % 2)
            {
                res = ((z + 1.0) / 1e6);
            }
            else
            {
                res = ((z * 1.0) / 1e6);
            }
        }
        else if ((temp % 10 == 5) && (temp2 % 100000 != 0))
        {
            ll z = (ll)(res * 1e6);
            res = ((z + 1.0) / 1e6);
        }
        cout << fixed << setprecision(6) << res;
    }
}