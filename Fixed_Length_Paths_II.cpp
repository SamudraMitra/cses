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
#define SZ 200005
#define ll long long

vector<int> adj[SZ];
int n, k1, k2;
long long ans;

int suf(deque<int> &suf, int idx)
{
    if (idx < 0)
        return suf[0];
    if (idx > suf.size() - 1)
        return 0;
    return suf[idx];
}

// suf[i] = sum of nodes having depth in range [i, inf)
void mergeSuffixes(deque<int> &sa, deque<int> &sb)
{
    if (sa.size() < sb.size())
        swap(sa, sb);
    for (int i = 0; i < sb.size(); i++) // calculate the answer
        ans += 1LL * (suf(sb, i) - suf(sb, i + 1)) * (suf(sa, k1 - i) - suf(sa, k2 - i + 1));
    for (int i = 0; i < sb.size(); i++) // merge the deques
        sa[i] += sb[i];
}

deque<int> dfs(int u, int p)
{
    deque<int> suf_parent = {1};
    for (int v : adj[u])
    {
        if (v != p)
        {
            deque<int> suf_child = dfs(v, u);
            suf_child.push_front(suf_child.front());
            mergeSuffixes(suf_parent, suf_child);
        }
    }
    return suf_parent;
}

int main()
{
    fastio;
    cin >> n >> k1 >> k2;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans;
    return 0;
}
