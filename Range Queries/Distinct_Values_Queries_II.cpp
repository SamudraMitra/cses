#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (int i = 0; i < n; i++)
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
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

    T (*combine)(T obj1, T obj2);

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
int combine(int a, int b)
{
    return min(a, b);
}
const int INF = 1e9;
int main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    map<int, int> mp;
    vector<int> nxtocc(n, n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (mp.find(v[i]) != mp.end())
        {
            nxtocc[i] = mp[v[i]];
        }
        mp[v[i]] = i;
    }
    unordered_map<int, set<int>> nxtoccadj;
    for (int i = 0; i < n; i++)
    {
        nxtoccadj[v[i]].insert(i);
    }
    for (auto &i : nxtoccadj)
    {
        i.second.insert(n + 1);
        i.second.insert(-1);
    }
    SegmentTree<int> seg(nxtocc, INF, combine);
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            if (v[x] == y)
                continue;
            nxtoccadj[y].insert(n + 1);
            nxtoccadj[y].insert(-1);
            if (nxtoccadj[y].find(x) == nxtoccadj[y].end())
            {
                nxtoccadj[v[x]].erase(x);
                nxtoccadj[y].insert(x);
                int oldval = v[x];
                int newval = y;
                int idx = x;
                auto z1 = nxtoccadj[newval].upper_bound(idx);
                int nextofnewval = *z1;
                int prevofnewval = *prev(prev(z1));
                if ((prevofnewval > 0) && (prevofnewval < n))
                {
                    nxtocc[prevofnewval] = idx;
                    seg.update(prevofnewval, idx);
                }
                nxtocc[idx] = nextofnewval;
                seg.update(idx, nextofnewval);

                auto z2 = nxtoccadj[oldval].upper_bound(idx);
                int nextofoldval = *z2;
                int prevofoldval = *prev(z2);

                if ((prevofoldval > 0) && (prevofoldval < n))
                {
                    nxtocc[prevofoldval] = nextofoldval;
                    seg.update(prevofoldval, nextofoldval);
                }
            }
            v[x] = y;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int minnxtocc = seg.query(a, b);
            if (minnxtocc <= b)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
}