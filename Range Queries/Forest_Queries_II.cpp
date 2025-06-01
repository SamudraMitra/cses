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
class BIT2D
{
    ll max_x;
    ll max_y;
    vector<vector<ll>> tree;
    ll sumy(ll a, ll b)
    {
        ll ans = 0;
        for (; b > 0; b -= (b & -b))
            ans += tree[a][b];
        return ans;
    }

public:
    BIT2D(vector<vector<ll>> v) // provide the 2d matrix with 0 based indexing
    {
        max_x = v.size();
        max_y = v[0].size();
        tree.resize(max_x + 1, vector<ll>(max_y + 1, 0));
        for (ll i = 1; i <= max_x; i++)
        {
            for (ll j = 1; j <= max_y; j++)
            {
                update(i, j, v[i - 1][j - 1]);
            }
        }
    }
    void update(ll x, ll y, ll val) // 1 based indexing
    {
        ll y1;
        while (x <= max_x)
        {
            y1 = y;
            while (y1 <= max_y)
            {
                tree[x][y1] += val;
                y1 += (y1 & -y1);
            }
            x += (x & -x);
        }
    }
    ll query(ll a, ll b) // 1 based indexing
    {
        ll ans = 0;
        for (; a > 0; a -= (a & -a))
        {
            ll b1 = b;
            for (; b1 > 0; b1 -= (b1 & -b1))
                ans += tree[a][b1];
        }
        return ans;
    }
};
int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> forest(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                forest[i][j] = 0;
            }
            else
            {
                forest[i][j] = 1;
            }
        }
    }
    BIT2D BIT2(forest);
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x, y;
            cin >> x >> y;
            if (forest[x - 1][y - 1] == 1)
            {
                BIT2.update(x, y, -1);
            }
            else
            {
                BIT2.update(x, y, 1);
            }
            forest[x - 1][y - 1] = 1 - forest[x - 1][y - 1];
        }
        else
        {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            ll res = BIT2.query(a - 1, b - 1) + BIT2.query(c, d) - (BIT2.query(c, b - 1) + BIT2.query(a - 1, d));
            cout << res << "\n";
        }
    }
}