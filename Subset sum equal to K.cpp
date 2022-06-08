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
// Tabulation
// bool subsetSumToK(int n, int target, vector<int> &arr)
// {
//     vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
//     for (int i = 0; i < n; i++)
//         dp[i][0] = true;
//     if (arr[0] <= target)
//     {
//         dp[0][arr[0]] = true;
//     }
//     for (int ind = 1; ind < n; ++ind)
//     {
//         for (int targt = 1; targt <= target; ++targt)
//         {
//             bool notPick = dp[ind - 1][targt];
//             bool pick = false;
//             if (targt >= arr[ind])
//                 pick = dp[ind - 1][targt - arr[ind]];
//             dp[ind][targt] = pick || notPick;
//         }
//     }
//     return dp[n - 1][target];
// }

bool subsetSumToK(int n, int target, vector<int> &arr)
{
    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if (arr[0] <= target)
        prev[arr[0]] = true;
    for (int i = 1; i < n; ++i)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int t = 1; t <= target; ++t)
        {
            bool notPick = prev[t];
            bool pick = false;
            if (t >= arr[i])
                pick = prev[t - arr[i]];
            curr[t] = pick || notPick;
        }
        prev = curr;
    }
    return prev[target];
}
// Memoization
// bool fun(vector<int> &arr, int i, int target, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return true;
//     if (i == 0)
//         return (arr[i] == target);
//     if (dp[i][target] != -1)
//         return dp[i][target];
//     bool NotPick = fun(arr, i - 1, target, dp);
//     bool pick = false;
//     if (target >= arr[i])
//         pick = fun(arr, i - 1, target - arr[i], dp);
//     return dp[i][target] = pick || NotPick;
// }
// bool subsetSumToK(int n, int target, vector<int> &arr)
// {
//     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//     return fun(arr, n - 1, target, dp);
// }

// Recursion
// bool fun(vector<int> &arr, int i, int target)
// {
//     if (target == 0)
//         return true;
//     if (i == 0)
//         return (arr[i] == target);
//     bool NotPick = fun(arr, i - 1, target);
//     bool pick = false;
//     if (target >= arr[i])
//         pick = fun(arr, i - 1, target - arr[i]);
//     return pick || NotPick;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr)
// {
//     return fun(arr, n - 1, k);
// }
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        input(arr, 0, n - 1);
        bool ans = subsetSumToK(n, k, arr);
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