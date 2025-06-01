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
vector<ll> nextLargerElement(vector<ll> &arr)
{
    ll n = arr.size();
    stack<pair<ll, ll>> s;
    vector<ll> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().first <= arr[i])
            s.pop();
        res[i] = s.empty() ? -1 : s.top().second;
        s.push({arr[i], i});
    }
    return res;
}
const ll INF = 1e10;
const ll LOGN = 18;
int main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    v.push_back(INF);
    n++;
    vector<ll> nge = nextLargerElement(v);
    nge[n - 1] = n - 1;
    vector<ll> pref(n);
    pref[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        pref[i] = v[i] + pref[i - 1];
    }
    pair<ll, ll> dp[n][LOGN + 1];
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j <= LOGN; j++)
        {
            if (j == 0)
            {
                ll jump_to = nge[i];
                ll cost = ((nge[i] - i - 1) * v[i]) - (pref[nge[i] - 1] - pref[i]);
                dp[i][j] = {jump_to, cost};
            }
            else
            {
                dp[i][j] = {dp[dp[i][j - 1].first][j - 1].first, dp[i][j - 1].second + dp[dp[i][j - 1].first][j - 1].second};
            }
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j <= LOGN; j++)
    //     {
    //         cout << dp[i][j].second << " ";
    //     }
    //     cout << "\n";
    // }
    // for (auto &i : pref)
    //     cout << i << " ";
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ll x = a;
        ll cost = 0;
        ll i;
        for (i = LOGN; i >= 0; i--)
        {
            if (dp[x][i].first <= b)
            {
                ll ed = dp[x][i].first;
                ll st = x;
                cost += dp[x][i].second;
                x = dp[x][i].first;
            }
        }
        if (x <= b)
        {
            ll ed = b;
            ll st = x;
            cost += ((ed - st) * v[x]) - (pref[ed] - pref[st]);
        }
        cout << cost << "\n";
    }
}