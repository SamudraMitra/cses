// Sarthak stalk krna buri baat hoti hai
#include <iostream>      // for input and output streams
#include <vector>        // for std::vector
#include <algorithm>     // for algorithms like sort, max, min
#include <string>        // for std::string
#include <map>           // for std::map
#include <unordered_map> // for std::unordered_map
#include <set>           // for std::set
#include <unordered_set> // for std::unordered_set
#include <queue>         // for std::queue, std::priority_queue
#include <stack>         // for std::stack
#include <deque>         // for std::deque
#include <list>          // for std::list
#include <iterator>      // for std::iterators
#include <functional>    // for std::function, std::bind
#include <numeric>       // for numeric algorithms like accumulate
#include <cmath>         // for mathematical functions like sqrt, pow
#include <limits>        // for limits of data types
#include <iomanip>       // for std::setprecision, std::fixed
#include <fstream>       // for file I/O
#include <sstream>       // for string streams
#include <bitset>        // for bitset operations
#include <tuple>         // for std::tuple
#include <utility>       // for std::pair, std::move, std::forward
#include <ctime>         // for std::time
#include <chrono>        // for time utilities
#include <cassert>       // for assertions
#include <random>        // for random number generation
#include <memory>        // for smart pointers

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
const ll mod = 1e9 + 7;
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> freq(1e6 + 1, 0);
    for (auto &i : v)
    {
        cin >> i;
        freq[i]++;
    }
    ll N = 1e6;
    ll ans = 0;
    for (ll i = 1; i <= N; i++)
    {
        ll res = 0;
        for (ll j = i; j <= N; j += i)
        {
            res += freq[j];
        }
        if (res > 1)
        {
            ans = i;
        }
    }
    cout << ans << "\n";
}