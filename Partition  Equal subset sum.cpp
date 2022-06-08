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
bool subsetSumToK(vector<int> &arr, int n, int target)
{
    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if (arr[0] <= target)
    {
        prev[arr[0]] = true;
    }
    for (int i = 1; i < n; ++i)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int t = 1; t <= target; ++t)
        {
            bool notPick = prev[t];
            bool pick = false;
            if (arr[i] <= t)
                pick = prev[t - arr[i]];
            curr[t] = pick || notPick;
        }
        prev = curr;
    }
    return prev[target];
}
bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    if (sum & 1) // See if sum is odd or even. If odd then we can't divide it and return false;
        return false;
    return subsetSumToK(arr, n, sum / 2);
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        input(arr, 0, n - 1);
        bool ans = canPartition(arr, n);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
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