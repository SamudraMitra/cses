#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    vector<ll> triangles;
    ll triangle = 0;
    for (ll i = 1; triangle <= 1e12; i++)
    {
        triangle = (i * (i + 1)) / 2;
        triangles.push_back(triangle);
    }

    while (t--)
    {
        ll n;
        cin >> n;

        if (find(triangles.begin(), triangles.end(), n) != triangles.end())
        {
            cout << "1\n";
            continue;
        }

        bool found = false;
        int right = triangles.size() - 1;
        for (int left = 0; left <= right; left++)
        {
            while (right > 0 && triangles[left] + triangles[right] > n)
            {
                right--;
            }
            if (triangles[left] + triangles[right] == n)
            {
                cout << "2\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "3\n";
        }
    }
}