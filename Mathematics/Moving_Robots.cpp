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

ll dr[4] = {1, -1, 0, 0};
ll dc[4] = {0, 0, 1, -1};

int main()
{
    fastio;
    ll n;
    cin >> n;
    ld dp[n + 1][8][8];
    ld ans[8][8];
    for (ll i = 0; i < 8; i++)
    {
        for (ll j = 0; j < 8; j++)
        {
            ans[i][j] = 1;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // for (int k = 0; k <= n; k++)
            // {
            //     for (int i1 = 0; i1 < 8; i1++)
            //     {
            //         for (int j1 = 0; j1 < 8; j1++)
            //         {
            //             dp[k][i1][j1] = 0;
            //         }
            //     }
            // }
            memset(dp, 0, sizeof(dp));
            dp[0][i][j] = 1;
            for (int k = 0; k < n; k++)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        ld dir = 0;
                        for (int f = 0; f < 4; f++)
                        {
                            ll u = i1 + dr[f], v = j1 + dc[f];
                            if (u >= 0 && u < 8 && v >= 0 && v < 8)
                            {
                                dir++;
                            }
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            ll u = i1 + dr[f], v = j1 + dc[f];
                            if (u >= 0 && u < 8 && v >= 0 && v < 8)
                            {
                                dp[k + 1][u][v] += dp[k][i1][j1] / dir;
                            }
                        }
                    }
                }
            }
            for (int i1 = 0; i1 < 8; i1++)
            {
                for (int j1 = 0; j1 < 8; j1++)
                {
                    ans[i1][j1] *= (1 - dp[n][i1][j1]);
                }
            }
        }
    }
    ld expc = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            expc += ans[i][j];
        }
    }
    cout << fixed << setprecision(6) << expc;
}
