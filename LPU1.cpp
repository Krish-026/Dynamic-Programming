#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long>
#define vvl vector<vl>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define pb push_back
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp make_pair
#define rep(a, b, c) for (long long a = b; a <= c; ++a)
#define repr(a, b, c) for (long long a = b; a >= c; --a)
#define input(a, b, n)                 \
    for (long long i = b; i <= n; ++i) \
        cin >> a[i];
#define output(a, b, n)                \
    for (long long i = b; i <= n; ++i) \
        cout << a[i] << " ";
#define Mod 1000000007
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vi arr(n, 0);
    input(arr, 0, n - 1);
    // for (int i = 0; i <= n - k; ++i)
    // {
    //     int ans = 0;
    //     int pos = i;
    //     for (int j = i; j < i + k; ++j)
    //     {
    //         int mx = __builtin_popcount(arr[j]);
    //         // cout << arr[j] << "  " << mx << endl;
    //         ans = max(mx, ans);
    //         if (mx == ans)
    //             pos = j;
    //     }
    //     cout << arr[pos] << " ";
    // }
    int pos = 0, ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ans = max(__builtin_popcount(arr[i]), ans);
        if (__builtin_popcount(arr[i]) == ans)
            pos = i;
    }

    for (int i = k; i < n; ++i)
    {
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}