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
    return a + b;
}
int main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    set<ll> st;
    for (auto &i : a)
    {
        cin >> i;
        st.insert(i);
    }
    vector<pair<ll, ll>> queries(q);
    for (auto &i : queries)
    {
        cin >> i.first >> i.second;
    }
    vector<pair<ll, ll>> qc(queries);
    vector<ll> temp;
    for (auto &i : st)
    {
        temp.push_back(i);
    }
    sort(temp.begin(), temp.end());
    ll x = temp.size();
    ll maxres = x;
    vector<vector<ll>> adj(x + 1);
    ll idx = 0;
    for (auto &i : a)
    {
        i = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
        adj[i].push_back(idx++);
    }
    // for(auto &i: a)
    // cout<<i<<" ";
    // cout<<"\n\n";
    // for(auto &i: queries)
    // {
    //     cout<<i.first<<" "<<i.second<<"\n";
    // }

    vector<ll> fo(x + 1, -1);
    vector<ll> segvec(n, 0);
    for (ll i = n - 1; i >= 0; i--)
    {
        fo[a[i]] = i;
    }
    for (ll i = 0; i <= x; i++)
    {
        if (fo[i] >= 0)
        {
            segvec[fo[i]] = 1;
        }
    }
    SegmentTree<ll> seg(segvec, 0ll, combine);
    queries.push_back({1, 1});
    sort(queries.begin(), queries.end());
    q++;
    map<pair<ll, ll>, ll> rmp;
    for (ll i = 0; i < q; i++)
    {
        // if(i==0)
        // {

        // }
        if ((i != 0) && (queries[i].first != queries[i - 1].first))
        {
            for (ll j = queries[i - 1].first - 1; j < queries[i].first - 1; j++)
            {
                if (seg.query(j, j) == 1)
                {
                    auto z = lower_bound(adj[a[j]].begin(), adj[a[j]].end(), queries[i].first - 1);
                    if (z != adj[a[j]].end())
                    {
                        ll newpos = *lower_bound(adj[a[j]].begin(), adj[a[j]].end(), queries[i].first - 1);
                        seg.update(newpos, 1);
                    }
                }
            }
            ll res = seg.query(queries[i].first - 1, queries[i].second - 1);
            rmp[{queries[i].first, queries[i].second}] = res;
        }
        else
        {
            ll res = seg.query(queries[i].first - 1, queries[i].second - 1);
            rmp[{queries[i].first, queries[i].second}] = res;
        }
    }
    for (auto &i : qc)
    {
        cout << rmp[{i.first, i.second}] << "\n";
    }
    /*
    1 1 0 1 0
    2 1 2 0 1

    1 3
    2 4
    1 5
    */
}