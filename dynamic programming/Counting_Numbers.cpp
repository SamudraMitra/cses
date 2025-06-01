#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll dp[20][2][11][2];
ll solve(string &s, ll idx, ll eq, ll n, ll prev, ll started)
{
    if ((idx >= n) && (started))
    {
        return (dp[idx][eq][prev][started] = 1);
    }
    else if ((idx >= n) && (!started))
    {
        return (dp[idx][eq][prev][started] = 0);
    }
    if (dp[idx][eq][prev][started] != -1)
    {
        return (dp[idx][eq][prev][started]);
    }
    else
    {
        ll ans = 0;
        if (started)
        {
            if (eq)
            {
                for (ll i = 0; i <= (s[idx] - '0'); i++)
                {
                    if (i != prev)
                    {
                        ans += solve(s, idx + 1, (i == (s[idx] - '0')), n, i, 1);
                    }
                }
            }
            else
            {
                for (ll i = 0; i <= 9; i++)
                {
                    if (i != prev)
                    {
                        ans += solve(s, idx + 1, 0, n, i, 1);
                    }
                }
            }
        }
        else
        {
            if (eq)
            {
                for (ll i = 0; i <= (s[idx] - '0'); i++)
                {
                    if (i != prev)
                        ans += solve(s, idx + 1, ((s[idx] - '0') == i), n, ((i == 0) ? 10 : i), ((i == 0) ? 0 : 1));
                }
            }
            else
            {
                for (ll i = 0; i <= 9; i++)
                {
                    ans += solve(s, idx + 1, 0, n, ((i == 0) ? 10 : i), ((i == 0) ? 0 : 1));
                }
            }
        }
        return (dp[idx][eq][prev][started] = ans);
    }
}
int main()
{
    ll t = 1;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        string s1 = to_string(a);
        string s2 = to_string(b);
        for (ll i = 0; i < 20; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                for (ll k = 0; k < 11; k++)
                {
                    for (ll l = 0; l < 2; l++)
                    {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        ll ans = solve(s2, 0, 1, s2.length(), 10, 0);
        for (ll i = 0; i < 20; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                for (ll k = 0; k < 11; k++)
                {
                    for (ll l = 0; l < 2; l++)
                    {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        if (a >= 0)
            ans -= solve(s1, 0, 1, s1.length(), 10, 0);
        else
            ans++;
        cout << ans << "\n";
    }
}