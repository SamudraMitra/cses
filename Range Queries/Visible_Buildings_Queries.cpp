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
const ll INF = 1e10;
const ll LOGN = 17;
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
int32_t main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    v.push_back(INF);
    n++;
    vector<ll> nge = nextLargerElement(v);
    nge[n - 1] = n - 1;
    // vector<vector<ll>> dp(n, vector<ll>(LOGN + 1, n));
    ll dp[n][LOGN + 1];
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j <= LOGN; j++)
        {
            if (j == 0)
                dp[i][j] = nge[i];
            else
            {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    while (q--)
    {
        pair<ll, ll> query;
        cin >> query.first >> query.second;
        ll lo = 1;
        ll hi = n;
        ll ans = -1;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll x = query.first - 1;
            bool f = true;
            for (ll i = 0; i <= LOGN; i++)
            {
                if ((1ll << i) & mid)
                {
                    x = dp[x][i];
                    if (x > query.second - 1)
                    {
                        f = false;
                        break;
                    }
                }
            }
            if (!f)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}