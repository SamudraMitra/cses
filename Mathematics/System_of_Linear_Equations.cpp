#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int mod = 1e9 + 7;

ll inverse(ll x)
{
    ll power = mod - 2;
    ll result = 1;
    while (power > 0)
    {
        if (power & 1)
            result = result * x % mod;
        x = x * x % mod;
        power /= 2;
    }
    return result;
}

vector<vector<ll>> matrix;

void multiply(int row, int m, ll x)
{
    for (int i = 0; i <= m; i++)
    {
        matrix[row][i] = matrix[row][i] * x % mod;
    }
}

void subtract(int row1, int row2, int m, ll x)
{
    for (int i = 0; i <= m; i++)
    {
        matrix[row2][i] -= matrix[row1][i] * x;
        matrix[row2][i] = (matrix[row2][i] % mod + mod) % mod;
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(m + 1);
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
        cin >> matrix[i][m];
    }

    vector<int> chosen(n);
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j])
            {
                chosen[i] = j;
                multiply(i, m, inverse(matrix[i][j]));
                found = true;
                break;
            }
        }

        if (!found && matrix[i][m])
        {
            cout << "-1\n";
            return 0;
        }

        for (int j = 0; j < n; j++)
        {
            if (i == j || !matrix[j][chosen[i]])
                continue;
            subtract(i, j, m, matrix[j][chosen[i]]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (chosen[j] == i)
            {
                cout << matrix[j][m] << " ";
                found = true;
                break;
            }
        }
        if (!found)
            cout << 0 << " ";
    }
    cout << "\n";
}
