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
        ll l, r, m, sum;
        stack<ll> upd;
        Node *left;
        Node *right;
    };

    Node *root;
    vector<ll> &arr;

    SegTree(vector<ll> &a) : arr(a)
    {
        root = new Node;
        root->l = 0;
        root->r = a.size() - 1;
        root->m = (a.size() - 1) / 2;
        build(root);
    }

    void build(Node *node)
    {
        if (node->l == node->r)
        {
            node->sum = arr[node->l];
            node->upd.push(node->sum);
            return;
        }

        node->left = new Node;
        node->left->l = node->l;
        node->left->r = node->m;
        node->left->m = (node->l + node->m) / 2;
        build(node->left);

        node->right = new Node;
        node->right->l = node->m + 1;
        node->right->r = node->r;
        node->right->m = (node->m + 1 + node->r) / 2;
        build(node->right);

        node->sum = node->right->sum + node->left->sum;
    }

    void update(Node *node, ll &i, ll &x)
    {
        if (node->l == node->r)
        {
            node->sum = x;
            node->upd.push(x);
            return;
        }

        if (i <= node->m)
            update(node->left, i, x);
        else
            update(node->right, i, x);
        node->sum = node->left->sum + node->right->sum;
    }
    void update(ll i, ll x) { update(root, i, x); }

    void rollback(Node *node, ll &i)
    {
        if (node->l == node->r)
        {
            node->upd.pop();
            node->sum = node->upd.top();
            return;
        }

        if (i <= node->m)
            rollback(node->left, i);
        else
            rollback(node->right, i);
        node->sum = node->left->sum + node->right->sum;
    }
    void rollback(ll i) { rollback(root, i); }

    ll query(Node *node, ll l, ll r)
    {
        if (node->l == l && node->r == r)
            return node->sum;

        ll ans = 0;
        if (l <= node->m)
            ans += query(node->left, l, min(r, node->m));
        if (node->m < r)
            ans += query(node->right, max(l, node->m + 1), r);
        return ans;
    }
    ll query(ll l, ll r) { return query(root, l, r); }
};

struct Tree
{
    int type = -1;
    ll a, b, i;
    Tree *next;
    Tree *alt;
};

Tree *root = new Tree;
vector<Tree *> nxt = {root};
ll n, q;
vector<ll> arr;
vector<pair<ll, ll>> ans;

void add_update(ll k, ll a, ll x)
{
    nxt[k]->a = a;
    nxt[k]->b = x;
    nxt[k]->type = 0;
    nxt[k]->next = new Tree;
    nxt[k] = nxt[k]->next;
}

void add_query(ll k, ll a, ll b, ll i)
{
    nxt[k]->a = a;
    nxt[k]->b = b;
    nxt[k]->i = i;
    nxt[k]->type = 1;
    nxt[k]->next = new Tree;
    nxt[k] = nxt[k]->next;
}

void add_copy(ll &k)
{
    nxt[k]->type = 2;
    nxt[k]->alt = new Tree;
    nxt.push_back(nxt[k]->alt);
    nxt[k]->next = new Tree;
    nxt[k] = nxt[k]->next;
}

void explore(Tree *tr, SegTree &st)
{
    if (tr->type == 0)
    {
        st.update(tr->a, tr->b);
        if (tr->next)
            explore(tr->next, st);
        st.rollback(tr->a);
        return;
    }
    if (tr->type == 1)
    {
        ans.push_back({tr->i, st.query(tr->a, tr->b)});
        if (tr->next)
            explore(tr->next, st);
        return;
    }
    if (tr->type == 2)
    {
        explore(tr->alt, st);
        if (tr->next)
            explore(tr->next, st);
    }
}

int main()
{
    cin >> n >> q;
    arr.resize(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    SegTree st(arr);

    ll t, i = 0;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            ll k, a, x;
            cin >> k >> a >> x;
            k--;
            a--;
            add_update(k, a, x);
            continue;
        }
        if (t == 2)
        {
            ll k, a, b;
            cin >> k >> a >> b;
            k--;
            a--;
            b--;
            add_query(k, a, b, i++);
            continue;
        }
        ll k;
        cin >> k;
        k--;
        add_copy(k);
    }

    explore(root, st);

    sort(ans.begin(), ans.end());
    for (pair<ll, ll> &it : ans)
        cout << it.second << '\n';
}