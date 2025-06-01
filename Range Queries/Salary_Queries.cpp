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
    vector<pair<char, pair<ll, ll>>> queries(q);
    for (auto &i : queries)
    {
        cin >> i.first >> i.second.first >> i.second.second;
        if (i.first == '?')
        {
            st.insert(i.second.first);
            st.insert(i.second.second);
        }
        else
        {
            st.insert(i.second.second);
        }
    }
    vector<ll> temp;
    for (auto &i : st)
    {
        temp.push_back(i);
    }
    sort(temp.begin(), temp.end());
    // unordered_map<ll,ll> mp;
    ll x = temp.size();
    ll maxres = x;
    // for(ll i=0;i<x;i++)
    // {
    //     mp[temp[i]] = i;
    //     maxres = max(maxres,i);
    // }
    for (auto &i : a)
    {
        i = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
    }
    for (auto &j : queries)
    {
        if (j.first == '?')
        {
            j.second.first = lower_bound(temp.begin(), temp.end(), j.second.first) - temp.begin();
            j.second.second = lower_bound(temp.begin(), temp.end(), j.second.second) - temp.begin();
        }
        else
        {
            j.second.second = lower_bound(temp.begin(), temp.end(), j.second.second) - temp.begin();
        }
    }
    vector<ll> sal(maxres + 1, 0);
    for (auto &i : a)
    {
        sal[i]++;
    }
    ll m = sal.size();
    /*
    for(ll i=1;i<m;i++)
    {
        sal[i]+=sal[i-1];
    }
    for(ll i=m-1;i>=0;i--)
    {
        sal[i] = sal[i]-((i>0)?sal[i-1]:0);
    }
    */
    SegmentTree<ll> seg(sal, 0ll, combine);
    for (auto &i : queries)
    {
        if (i.first == '?')
        {
            ll a = i.second.first - 1;
            ll b = i.second.second;
            if (a >= 0)
            {
                ll res = seg.query(0, b) - seg.query(0, a);
                cout << res << "\n";
            }
            else
            {
                ll res = seg.query(0, b);
                cout << res << "\n";
            }
        }
        else
        {
            ll idx = i.second.first - 1;
            ll val = i.second.second;
            ll oldval = a[idx];
            a[idx] = val;
            sal[oldval]--;
            sal[val]++;
            seg.update(oldval, sal[oldval]);
            seg.update(val, sal[val]);
        }
    }
    /*


    1 4 0 0 2

    2 1 1 0 1 0 0
    prefarray sal->   2 3 4 4 5 5 5 5 5
    diffarray(sal) -> 2 1 1 0 1 0 0 0 0

    ? 0 1
    ! 3 3
    ? 0 1


    */
}