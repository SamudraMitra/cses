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

struct SegTree
{
    struct Node
    {
        Node *left;
        Node *right;
        ll lazy, cnt = 0;
        ll l, r, m, sum;
        ll size() { return r - l + 1; }
    };

    Node *root;
    vector<ll> &arr;

    SegTree(vector<ll> &a) : arr(a)
    {
        root = new Node;
        root->l = 0;
        root->r = a.size() - 1;
        root->m = root->r / 2;
        build(root);
    }

    void build(Node *node)
    {
        if (node->l == node->r)
        {
            node->sum = arr[node->l];
            return;
        }

        node->left = new Node;
        node->left->l = node->l;
        node->left->r = node->m;
        node->left->m = (node->left->l + node->left->r) / 2;
        build(node->left);

        node->right = new Node;
        node->right->l = node->m + 1;
        node->right->r = node->r;
        node->right->m = (node->right->l + node->right->r) / 2;
        build(node->right);

        node->sum = node->left->sum + node->right->sum;
    }

    ll f(ll n, ll k)
    {
        return (n * (n - 1)) / 2 + n * k;
    }

    void push(Node *node)
    {
        if (node->cnt)
        {
            ll k = node->lazy - (node->cnt * ((node->size() * (node->size() - 1)) / 2));
            k /= node->size();

            ll ans_l = node->cnt * (node->left->size() * (node->left->size() - 1) / 2) + k * node->left->size();
            node->left->sum += ans_l;
            node->left->lazy += ans_l;
            node->left->cnt += node->cnt;

            ll ans_r = node->lazy - ans_l;
            node->right->sum += ans_r;
            node->right->lazy += ans_r;
            node->right->cnt += node->cnt;

            node->lazy = 0;
            node->cnt = 0;
        }
    }

    void update(Node *node, ll l, ll r, ll from)
    {
        if (node->l == l && node->r == r)
        {
            node->sum += f(node->size(), from);
            node->lazy += f(node->size(), from);
            node->cnt++;
            return;
        }

        push(node);
        if (l <= node->m)
            update(node->left, l, min(r, node->m), from);
        if (node->m < r)
            update(node->right, max(l, node->m + 1), r, from + (max(l, node->m + 1) - l));
        node->sum = node->left->sum + node->right->sum;
    }

    void update(ll l, ll r) { update(root, l, r, 1); }

    ll query(Node *node, ll l, ll r)
    {
        if (node->l == l && node->r == r)
            return node->sum;

        push(node);
        ll ans = 0;
        if (l <= node->m)
            ans += query(node->left, l, min(r, node->m));
        if (node->m < r)
            ans += query(node->right, max(l, node->m + 1), r);
        return ans;
    }

    ll query(ll l, ll r) { return query(root, l, r); }
};

int main()
{
    ll n, q;
    vector<ll> arr;
    cin >> n >> q;
    arr.resize(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    SegTree st(arr);

    ll t, l, r;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> l >> r;
            l--;
            r--;
            st.update(l, r);
            continue;
        }
        cin >> l >> r;
        l--;
        r--;
        cout << st.query(l, r) << '\n';
    }
}