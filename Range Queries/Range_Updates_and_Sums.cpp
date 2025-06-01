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

class segtree // 0 based indexing, only for sum queries
{
    struct node
    {
        ll sum;
        ll setAll;
        ll increment;
        bool setAllValid;
        node()
        {
            sum = 0;
            setAllValid = 0;
            increment = 0;
        }
        void Reset()
        {
            setAllValid = increment = 0;
        }
    };
    ll range;
    vector<node> tree;
    void build_recur(vector<ll> &v, ll l, ll r, ll node_no)
    {
        if (l == r)
        {
            if (l < v.size())
                tree[node_no].sum = v[l];
            else
                tree[node_no].sum = 0;
            return;
        }
        ll mid = (l + r) / 2;
        build_recur(v, l, mid, 2 * node_no + 1);
        build_recur(v, mid + 1, r, 2 * node_no + 2);
        tree[node_no].sum = tree[2 * node_no + 1].sum + tree[2 * node_no + 2].sum;
    }
    void incUpdate_recur(ll node, ll l, ll r, ll &L, ll &R, ll &X)
    {
        if (r < L || R < l || l >= range)
            return;
        if (L <= l && R >= r)
        {
            tree[node].increment += X;
            return;
        }
        applyAggr(node, l, r);
        ll mid = (l + r) / 2;
        incUpdate_recur(2 * node + 1, l, mid, L, R, X);
        incUpdate_recur(2 * node + 2, mid + 1, r, L, R, X);
        applyAggr(2 * node + 1, l, mid);
        applyAggr(2 * node + 2, mid + 1, r);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }
    void setUpdate_recur(ll node, ll l, ll r, ll &L, ll &R, ll &X)
    {
        if (r < L || R < l || l >= range)
            return;
        if (L <= l && R >= r)
        {
            tree[node].setAllValid = 1;
            tree[node].setAll = X;
            tree[node].increment = 0;
            return;
        }
        applyAggr(node, l, r);
        ll mid = (l + r) / 2;
        setUpdate_recur(2 * node + 1, l, mid, L, R, X);
        setUpdate_recur(2 * node + 2, mid + 1, r, L, R, X);
        applyAggr(2 * node + 1, l, mid);
        applyAggr(2 * node + 2, mid + 1, r);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }
    void compose(ll par, ll child)
    {
        if (tree[par].setAllValid)
        {
            tree[child].setAllValid = 1;
            tree[child].setAll = tree[par].setAll;
            tree[child].increment = tree[par].increment;
        }
        else
            tree[child].increment += tree[par].increment;
    }

    void applyAggr(ll node, ll l, ll r)
    {
        if (tree[node].setAllValid)
            tree[node].sum = (r - l + 1) * tree[node].setAll;

        tree[node].sum += (r - l + 1) * tree[node].increment;

        if (l != r)
        {
            compose(node, 2 * node + 1);
            compose(node, 2 * node + 2);
        }

        tree[node].Reset();
    }

    ll range_query_recur(ll node, ll l, ll r, ll &L, ll &R)
    {
        if (r < L || R < l || l >= range)
            return 0;
        applyAggr(node, l, r);
        if (L <= l && R >= r)
            return tree[node].sum;
        ll mid = (l + r) / 2;
        return range_query_recur(2 * node + 1, l, mid, L, R) + range_query_recur(2 * node + 2, mid + 1, r, L, R);
    }

public:
    segtree(vector<ll> &v)
    {
        range = v.size();
        tree.assign(4 * range, node());
        build_recur(v, 0, range - 1, 0);
    }

    ll range_query(ll L, ll R)
    {
        return range_query_recur(0, 0, range - 1, L, R);
    }

    void incUpdate(ll L, ll R, ll X)
    {
        incUpdate_recur(0, 0, range - 1, L, R, X);
    }

    void setUpdate(ll L, ll R, ll X)
    {
        setUpdate_recur(0, 0, range - 1, L, R, X);
    }
};
int32_t main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    segtree sg(v);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            sg.incUpdate(a - 1, b - 1, x);
        }
        else if (t == 2)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            sg.setUpdate(a - 1, b - 1, x);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            ll res = sg.range_query(a - 1, b - 1);
            cout << res << "\n";
        }
    }
}
