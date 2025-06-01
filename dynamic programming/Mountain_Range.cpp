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
class sparsetable
{
    ll N;
    ll m;
    vector<vector<ll>> sparse_table;

public:
    ll func(ll x, ll y) // operation
    {
        return max(x, y);
    }
    sparsetable(vector<ll> &v)
    {
        ll n = v.size();
        N = n;
        m = log2(n) + 3;
        sparse_table.resize(N + 1, vector<ll>(m + 1, 0));
        for (ll i = n; i >= 1; i--)
        {
            for (ll j = 0; j <= m; j++)
            {
                if ((j != 0) && (i + (1 << (j - 1)) > n))
                    break;
                if (j == 0) // basecase
                    sparse_table[i][j] = v[i - 1];
                else
                    sparse_table[i][j] = func(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll range_query(ll L, ll R) // 1 based
    {
        L++;
        R++;
        ll W = R - L + 1;
        ll x = (ll)(log2(W));
        ll res = func(sparse_table[L][x], sparse_table[R - (1 << x) + 1][x]);
        return res;
    }
};
#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)
#define parent(i) ((i - 1) / 2)
template <class T>
class SegmentTree
{
public:
    // tree constructors.
    SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
    SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));

    // query the range l to r, 0 based array indexing.
    T query(int l, int r);

    // update the element at index idx to val.
    void update(int idx, T val);
    /// TODO lazy propagation
private:
    // represents the segment tree.
    T *tree;

    // builds the segment tree.
    void buildTree(std::vector<T> data);

    // size of the segment tree array.
    int segTreeSize;

    // extra nodes must be added to array to make its size a power of 2
    // this is the value to be filled for the those nodes.
    T valueForExtraNodes;

    // specifies how to combine child node results to form parent node result.
    T (*combine)(T obj1, T obj2);

    // used to calculate the size of array needed to store the tree.
    int calculateSize(int n);

    // helps to solve a range query.
    T queryHelper(int l, int r, int st, int ed, int node);
};

template <class T>
SegmentTree<T>::SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2))
{
    this->combine = combine;
    valueForExtraNodes = value;
    segTreeSize = calculateSize(data.size());
    buildTree(data);
}

template <class T>
SegmentTree<T>::SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2))
{
    this->combine = combine;
    valueForExtraNodes = value;
    segTreeSize = calculateSize(n);

    std::vector<T> data;
    for (int i = 0; i < n; i++)
        data.push_back(ar[i]);

    buildTree(data);
}

template <class T>
int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while (pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2 * pow2 - 1;
}

template <class T>
T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize / 2;
    return queryHelper(l, r, st, ed, 0);
}

template <class T>
T SegmentTree<T>::queryHelper(int l, int r, int st, int ed, int node)
{
    if ((r < st) || (l > ed) || (l > r))
        return valueForExtraNodes;
    if (st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed) / 2, left(node));
    T rightVal = queryHelper(l, r, (st + ed) / 2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template <class T>
void SegmentTree<T>::buildTree(std::vector<T> data)
{
    int n = data.size();
    tree = new T[segTreeSize];
    int extraNodes = (segTreeSize / 2 + 1) - n;
    for (int i = segTreeSize - 1; i >= 0; i--)
    {
        if (extraNodes > 0)
        {
            tree[i] = valueForExtraNodes;
            extraNodes--;
        }
        else if (n > 0)
        {
            tree[i] = data[n - 1];
            n--;
        }
        else
            tree[i] = combine(tree[left(i)], tree[right(i)]);
    }
}

template <class T>
void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize / 2) + idx;
    tree[segTreeIdx] = val;
    while (parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if (right(segTreeIdx) < segTreeSize)
            tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if (segTreeIdx == 0)
            break;
    }
}
ll combine(ll a, ll b)
{
    return max(a, b);
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    vector<ll> dp(n, 0);
    SegmentTree<ll> seg(dp, 0, combine);
    vector<pair<ll, ll>> temp(n);
    for (ll i = 0; i < n; i++)
    {
        temp[i] = {v[i], i};
    }
    sparsetable st(v);
    sort(temp.begin(), temp.end());
    for (ll i = 0; i < n; i++)
    {
        ll idx = temp[i].second;
        // cout << idx << "\n";
        ll op1 = 0;
        ll op2 = 0;
        if ((idx + 1) < n)
        {

            ll lo = idx + 1; // 9
            ll hi = n - 1;   // 9
            ll ans = 0;
            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2; // 9
                if (st.range_query(idx + 1, mid) < v[idx])
                {
                    ans = mid;    // 9
                    lo = mid + 1; // 10
                }
                else
                {
                    hi = mid - 1;
                }
            }
            if (ans == 0)
            {
                op1 = 0;
            }
            else
            {
                op1 = seg.query(idx + 1, ans);
            }
        }
        if (idx > 0)
        {
            ll lo = 1;
            ll hi = idx;
            ll ans = 0;
            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                if (st.range_query(idx - mid, idx - 1) < v[idx])
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            if (ans == 0)
            {
                op2 = 0;
            }
            else
            {
                op2 = seg.query(idx - ans, idx - 1);
            }
        }
        seg.update(idx, max(op1, op2) + 1);
    }
    // cout << "-----\n";
    cout << seg.query(0, n - 1) << "\n";
}