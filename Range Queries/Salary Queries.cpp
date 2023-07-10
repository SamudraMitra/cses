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
#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)
#define parent(i) ((i - 1) / 2)
template <class T>
class SegmentTree
{
public:
    SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
    SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));

    T query(int l, int r);

    void update(int idx, T val);

private:
    T *tree;

    void buildTree(std::vector<T> data);

    int segTreeSize;

    T valueForExtraNodes;

    T(*combine)
    (T obj1, T obj2);

    int calculateSize(int n);

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
    return a + b;
}
int main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<pair<char, pair<ll, ll>>> queries;
    vector<ll> v(n);
    vector<ll> indices;
    unordered_set<ll> st;
    for (auto &i : v)
    {
        cin >> i;
        if (st.find(i) == st.end())
        {
            st.insert(i);
            indices.push_back(i);
        }
    }
    while (q--)
    {
        char ch;
        cin >> ch;
        ll x, y;
        cin >> x >> y;
        queries.push_back({ch, {x, y}});
        if (ch == '?')
        {
            if (st.find(x) == st.end())
            {
                st.insert(x);
                indices.push_back(x);
            }
            if (st.find(y) == st.end())
            {
                st.insert(y);
                indices.push_back(y);
            }
        }
        else
        {
            if (st.find(y) == st.end())
            {
                st.insert(y);
                indices.push_back(y);
            }
        }
    }
    sort(indices.begin(), indices.end());
    unordered_map<ll, ll> mp;
    ll c = 0;
    for (auto &i : indices)
    {
        mp[i] = c++;
    }

    vector<ll> freq(c, 0);
    for (auto &i : v)
    {
        freq[mp[i]]++;
    }

    SegmentTree<ll> seg(freq, 0, combine);
    for (auto &i : queries)
    {
        if (i.first == '?')
        {
            cout << seg.query(mp[i.second.first], mp[i.second.second]) << "\n";
        }
        else
        {
            ll k = i.second.first;
            ll x = i.second.second;
            ll currval = seg.query(mp[v[k - 1]], mp[v[k - 1]]);
            seg.update(mp[v[k - 1]], currval - 1);
            ll curval = seg.query(mp[x], mp[x]);
            seg.update(mp[x], curval + 1);
            v[k - 1] = x;
        }
    }
}