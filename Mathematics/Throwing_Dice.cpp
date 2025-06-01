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
using namespace std;
const ll mod = 1e9 + 7;
vector<vector<long long>> multiplyMatrices(vector<vector<long long>> a, vector<vector<long long>> b)
{
    int n = a.size();    // Rows in a
    int m = a[0].size(); // Columns in a / Rows in b
    int p = b[0].size(); // Columns in b

    // Initialize result matrix with 0s
    vector<vector<long long>> result(n, vector<long long>(p, 0));

    // Multiply
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < m; ++k)
        {
            for (int j = 0; j < p; ++j)
            {
                result[i][j] += (a[i][k] * b[k][j]) % mod;
                result[i][j] %= mod;
            }
        }
    }

    return result;
}
vector<vector<ll>> binpow(vector<vector<ll>> a, long long b, long long m = mod)
{
    vector<vector<ll>> res(6, vector<ll>(6, 0));
    for (ll i = 0; i < 6; i++)
    {
        res[i][i] = 1;
    }
    while (b > 0)
    {
        if (b & 1)
            res = multiplyMatrices(res, a);
        a = multiplyMatrices(a, a);
        b >>= 1;
    }
    return res;
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    n--;
    vector<vector<ll>> mat = {{0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};
    vector<vector<ll>> ans = binpow(mat, n);
    vector<vector<ll>> ini = {{1},
                              {2},
                              {4},
                              {8},
                              {16},
                              {32}};
    ans = multiplyMatrices(ans, ini);
    cout << ans[0][0] << "\n";
}