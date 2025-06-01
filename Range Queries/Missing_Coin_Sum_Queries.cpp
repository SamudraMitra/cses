#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 1;
const int B = 30;
const int K = 18;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> x(n + 1);
    vector<int> bit(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        bit[i] = 31 - __builtin_clz(x[i]);
    }

    vector<pair<int, int>> query(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].first >> query[i].second;
    }

    vector<ll> result(q + 1);
    vector<ll> sumq(n + 1);
    vector<vector<int>> minq(K, vector<int>(n + 1));

    for (int b = 0; b < B; b++)
    {
        for (int i = 1; i <= n; i++)
        {
            sumq[i] = sumq[i - 1];
            if (bit[i] == b)
            {
                sumq[i] += x[i];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            minq[0][i] = bit[i] == b ? x[i] : INF;
        }
        for (int k = 1; k < K; k++)
        {
            for (int i = 1; i <= n - (1 << (k - 1)); i++)
            {
                minq[k][i] =
                    min(minq[k - 1][i], minq[k - 1][i + (1 << (k - 1))]);
            }
        }

        for (int i = 1; i <= q; i++)
        {
            auto a = query[i].first;
            auto b = query[i].second;
            int level = 31 - __builtin_clz(b - a + 1);
            int min_x = min(minq[level][a], minq[level][b - (1 << level) + 1]);
            if (min_x <= result[i] + 1)
            {
                result[i] += sumq[b] - sumq[a - 1];
            }
        }
    }

    for (int i = 1; i <= q; i++)
    {
        cout << result[i] + 1 << "\n";
    }
}