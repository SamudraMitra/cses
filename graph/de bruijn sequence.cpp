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
int main()
{
    fastio;
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "01\n";
        return 0;
    }
    ll N = (1 << (n - 1)) - 1;
    vector<vector<ll>> adj(N + 1);
    vector<ll> indeg(N + 1);
    vector<ll> outdeg(N + 1);
    for (ll i = 0; i <= N; i++)
    {
        ll num1 = (i * 2) % (1 << (max(0ll, (n - 1))));
        ll num2 = ((i * 2) + 1) % (1 << (max(0ll, (n - 1))));
        // cout << i << " " << num1 << " " << num2 << "\n";
        adj[i].push_back(num1);
        adj[i].push_back(num2);
        outdeg[i] += 2;
        indeg[num1]++;
        indeg[num2]++;
    }
    vector<ll> path;
    stack<ll> st;
    st.push(0);
    while (st.size() > 0)
    {
        ll x = st.top();
        if ((indeg[x] == 0) && (outdeg[x] == 0))
        {
            path.push_back(x);
            st.pop();
        }
        else
        {
            ll k = adj[x].back();
            adj[x].pop_back();
            indeg[k]--;
            outdeg[x]--;
            st.push(k);
        }
    }
    reverse(path.begin(), path.end());
    // for (auto &i : path)
    // {
    //     cout << i << " ";
    // }
    string res = "";
    for (ll i = 0; i < n - 1; i++)
    {
        res += '0';
    }
    ll m = path.size();

    for (ll i = 0; i < m - 1; i++)
    {
        if (path[i + 1] == ((path[i] * 2) % (1 << (max(0ll, (n - 1))))))
        {
            res += '0';
        }
        else
        {
            res += '1';
        }
    }
    // reverse(res.begin(), res.end());
    cout << res << "\n";
    // for (auto &i : path)
    // {
    //     cout << i << " ";
    // }
}
// recommended reading material:
// A De Bruijn sequence is a string that contains every string of length n exactly
// once as a substring, for a fixed alphabet of k characters. The length of such a
// string is (k^n) + n−1 characters. For example, when n = 3 and k = 2, an example of
// a De Bruijn sequence is
// 0001011100.
// The substrings of this string are all combinations of three bits: 000, 001, 010,
// 011, 100, 101, 110 and 111.
// It turns out that each De Bruijn sequence corresponds to an Eulerian path in
// a graph. The idea is to construct a graph where each node contains a string of
// n−1 characters and each edge adds one character to the string. The following
// graph corresponds to the above scenario

//---refer to the image in the readme file---

// An Eulerian path in this graph corresponds to a string that contains all
//  strings of length n. The string contains the characters of the starting node and
//  all characters of the edges. The starting node has n−1 characters and there are
//  k^n characters in the edges, so the length of the string is (k^n)+ n−1.
