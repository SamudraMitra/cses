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
    vector<ll> nextnode(n + 1);
    for (ll i = 1; i <= n + 1; i++)
    {
        cin >> nextnode[i];
    }
    vector<ll> vis(n + 1, 0);
    vector<ll> answer(n + 1, -1);
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            unordered_set<ll> tempset;
            vector<ll> tempvec;
            ll x = i;
            bool flag = true;
            while (tempset.find(x) == tempset.end())
            {
                tempset.insert(x);
                tempvec.push_back(x);
                if (vis[x])
                {
                    flag = false;
                    break;
                }
                x = nextnode[x];
            }
            // for (auto &i : tempvec)
            //     cout << i << " ";
            // cout << "\n";
            // if (flag)
            // {
            ll z = find(tempvec.begin(), tempvec.end(), x) - tempvec.begin();
            ll m = tempvec.size();
            for (ll i = z; i < m; i++)
            {
                vis[tempvec[i]] = 1;
                if (answer[tempvec[i]] == -1)
                    answer[tempvec[i]] = m - z;
            }
            for (ll i = z - 1; i >= 0; i--)
            {
                vis[tempvec[i]] = 1;
                if (answer[tempvec[i]] == -1)
                    answer[tempvec[i]] = answer[tempvec[i + 1]] + 1;
            }
            // }
            // else
            // {

            // }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << answer[i] << " ";
}
