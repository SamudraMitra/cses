#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1 << 18;

int tree[2 * N];

void set_val(int pos)
{
    pos += N;
    tree[pos] = 1;

    for (pos /= 2; pos >= 1; pos /= 2)
    {
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }
}

int get_sum(int a, int b)
{
    a += N;
    b += N;

    int sum = 0;
    while (a <= b)
    {
        if (a % 2 == 1)
        {
            sum += tree[a++];
        }
        if (b % 2 == 0)
        {
            sum += tree[b--];
        }
        a /= 2;
        b /= 2;
    }
    return sum;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> events;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        events.push_back({x, 2, i});
    }

    for (int i = 1; i <= q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        events.push_back({c, 1, a, b, i});
        events.push_back({d, 3, a, b, i});
    }

    sort(events.begin(), events.end());

    vector<int> result(q + 1);

    for (auto event : events)
    {
        if (event[1] == 1)
        {
            int sum = get_sum(event[2], event[3]);
            result[event[4]] -= sum;
        }

        if (event[1] == 2)
        {
            set_val(event[2]);
        }

        if (event[1] == 3)
        {
            int sum = get_sum(event[2], event[3]);
            result[event[4]] += sum;
        }
    }

    for (int i = 1; i <= q; i++)
    {
        cout << result[i] << "\n";
    }
}
