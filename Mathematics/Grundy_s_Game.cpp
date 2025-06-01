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
class Mex
{
private:
    map<long long, long long> frequency;
    set<long long> missing_numbers;
    vector<long long> A;

public:
    Mex(vector<long long> &A) : A(A)
    {
        for (long long i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (long long x : A)
        {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    long long mex()
    {
        return *missing_numbers.begin();
    }

    void update(long long idx, long long new_value)
    {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};
ll f(ll n, vector<ll> &dp)
{
    if (n <= 2)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    vector<ll> temp;
    for (ll i = 1; i < n - i; i++)
    {
        ll term = f(i, dp) ^ f(n - i, dp);
        temp.push_back(term);
    }
    Mex m(temp);
    return (dp[n] = m.mex());
}
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    vector<ll> dp(2000, -1);
    while (t--)
    {
        ll n;
        cin >> n;
        if (n >= 2000)
        {
            cout << "first\n";
        }
        else
        {
            ll ans = f(n, dp);
            if (ans > 0)
            {
                cout << "first\n";
            }
            else
            {
                cout << "second\n";
            }
        }
    }
}
