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
void addno(ll i, unordered_set<ll> &done, vector<ll> &nextnode, vector<ll> &no)
{
    if (done.find(i) != done.end())
        return;
    addno(nextnode[i], done, nextnode, no);
    done.insert(i);
    no[i] = no[nextnode[i]] - 1;
}
ll dp[200005][30];
ll findpar(ll node, ll k)
{
    ll x = node;
    for (ll i = 0; i < 30; i++)
    {
        if (k & (1ll << i))
        {
            // x = f(x, i, dp, par);
            x = dp[x][i];
        }
    }
    return x;
}
int main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> nextnode(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> nextnode[i];
        dp[i][0] = nextnode[i];
    }
    vector<ll> vis(n + 1, 0);
    for (ll i = 1; i < 30; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    // vector<ll> answer(n + 1, -1);
    vector<vector<ll>> cycles;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            unordered_set<ll> tempset;
            vector<ll> tempvec;
            ll x = i;
            bool flag = true;
            while (tempset.find(x) == tempset.end())
            {
                tempset.insert(x);
                tempvec.push_back(x);
                if (vis[x])
                {
                    flag = false;
                    break;
                }
                x = nextnode[x];
            }
            if (!flag)
            {
                for (auto &i : tempvec)
                    vis[i] = 1;
                continue;
            }
            ll z = find(tempvec.begin(), tempvec.end(), x) - tempvec.begin();
            ll m = tempvec.size();
            vector<ll> cycle;
            for (ll i = z; i < m; i++)
            {
                vis[tempvec[i]] = 1;
                cycle.push_back(tempvec[i]);
            }
            for (ll i = z - 1; i >= 0; i--)
            {
                vis[tempvec[i]] = 1;
            }
            cycles.push_back(cycle);
        }
    }
    vector<ll> no(n + 1, -1);
    unordered_set<ll> done;
    vector<ll> cycleidx(n + 1, -1);
    ll idx = 0;
    for (auto &i : cycles)
    {
        ll c = 0;
        for (auto &j : i)
        {
            no[j] = c++;
            cycleidx[j] = idx;
            done.insert(j);
        }
        idx++;
    }
    for (ll i = 1; i <= n; i++)
    {
        addno(i, done, nextnode, no);
    }
    // for (ll i = 1; i <= n; i++)
    //     cout << cycleidx[i] << " " << no[i] << "\n";
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if ((cycleidx[x] == cycleidx[y]) && ((cycleidx[x] != -1) && (cycleidx[y] != -1)))
        {
            ll b = cycles[cycleidx[x]].size();
            cout << ((no[y] - no[x] + b) % b) << "\n";
        }
        else if ((cycleidx[x] == -1) || (cycleidx[y] == -1))
        {
            if ((cycleidx[x] == -1) && (cycleidx[y] == -1))
            {
                if (no[x] > no[y])
                    cout << "-1\n";
                else
                {
                    ll jump = no[y] - no[x];
                    if (findpar(x, jump) == y)
                        cout << jump << "\n";
                    else
                        cout << "-1\n";
                }
            }
            else
            {
                // if (no[x] > no[y])
                // {
                if ((cycleidx[x] != -1) && (cycleidx[y] == -1))
                    cout << "-1\n";
                else
                {
                    ll lo = 0;
                    ll hi = n;
                    ll ans = -1;
                    while (lo <= hi)
                    {
                        ll mid = (lo + hi) / 2;
                        if (cycleidx[findpar(x, mid)] != -1)
                        {
                            ans = mid;
                            hi = mid - 1;
                        }
                        else
                        {
                            lo = mid + 1;
                        }
                    }
                    ll interm = findpar(x, ans);
                    if (cycleidx[interm] == cycleidx[y])
                    {
                        ll h = cycles[cycleidx[y]].size();
                        cout << ((no[interm] - no[x]) + ((no[y] - no[interm] + h) % h)) << "\n";
                    }
                    else
                    {
                        cout << "-1\n";
                    }
                }
            }
        }
        else
        {
            cout << "-1\n";
        }
    }
}
// this is a successor graph,.. so it can be divided into components having a cycle and a paths pointing to the cycle so if the nodes belong to the same cycle,.. then the distance is (dfs number(v)-dfs number(u)+cyclelength)%cyclelength else if both are not part of any cycle,.. then if we jump from u by (dfs number(v)-dfs number(v)), and we reach v,.. then the answer is jump else its -1 now if one node is in a cycle and the other isnt then the one outside the cycle,.. we find the nearest cycle node to it using binary jumping and binary search let this closest cycle node be called interm(as in intermediate node) now dist = distance between u and interm +  distance between interm and y(can be found using (dfs number(y)-dfs number(interm)+cyclelength)%cyclelength.. as shown int the above case)
