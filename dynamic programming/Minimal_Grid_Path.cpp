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
bool issafe(ll a, ll b, ll n, ll m)
{
    return ((0 <= a) && (a < n)) && ((0 <= b) && (b < m));
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    string s = "";
    // for (ll i = 0; i < n; i++)
    // {
    //     s += 'A';
    // }
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    vector<pair<ll, ll>> curr;
    curr.push_back({0, 0});
    string res = "";
    while (curr.size() > 0)
    {
        ll x = curr[0].first;
        ll y = curr[0].second;
        res += v[x][y];
        vector<pair<ll, ll>> temp;
        char minch = 'Z';
        for (auto &i : curr)
        {
            if (issafe(i.first + 1, i.second, n, n))
            {
                if ((temp.size() == 0) || (temp.back() != make_pair(i.first + 1, i.second)))
                {
                    temp.push_back({i.first + 1, i.second});
                    minch = min(minch, v[i.first + 1][i.second]);
                }
            }
            if (issafe(i.first, i.second + 1, n, n))
            {
                if ((temp.size() == 0) || (temp.back() != make_pair(i.first, i.second + 1)))
                {
                    temp.push_back({i.first, i.second + 1});
                    minch = min(minch, v[i.first][i.second + 1]);
                }
            }
        }
        vector<pair<ll, ll>> newcurr;
        for (auto &i : temp)
        {
            if (v[i.first][i.second] == minch)
            {
                if ((newcurr.size() == 0) || (newcurr.back() != make_pair(i.first, i.second)))
                    newcurr.push_back({i.first, i.second});
            }
        }
        curr = newcurr;
    }
    cout << res << "\n";
}
