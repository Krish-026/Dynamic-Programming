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
int countPartitions(int n, int d, vector<int> &arr)
{
    int tsum = 0;
    for (int i = 0; i < n; ++i)
        tsum += arr[i];
    if ((tsum - d) % 2 || (tsum - d) < 0)
        return 0;
    // given : s1 - s2 = d and s1 + s2 = tsum; tsum - 2*s2 = d; (tsum - d ) / 2 = s2
    int s1 = (tsum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));
    int target = s1;
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 and arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= target; ++j)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = (pick + notpick) % Mod;
        }
    }
    int ans = dp[n - 1][s1];
    return ans;
}

// int subsetSumToK(vector<int> &arr, int n, int target, vector<vector<int>> &dp)
// {
//     if (n == 0)
//     {
//         if (target == 0 and arr[0] == 0)
//             return 2;
//         if (target == 0 or arr[0] == target)
//             return 1;
//         return 0;
//     }
//     if (dp[n][target] != -1)
//         return dp[n][target];

//     int notpick = subsetSumToK(arr, n - 1, target, dp);
//     int pick = 0;
//     if (arr[n] <= target)
//         pick = subsetSumToK(arr, n - 1, target - arr[n], dp);

//     return dp[n][target] = pick + notpick;
// }

// int countPartitions(int n, int d, vector<int> &arr)
// {
//     int t_sum = 0;
//     for (int i = 0; i < n; ++i)
//         t_sum += arr[i];
//     if ((t_sum - d) % 2 == 1)
//         return 0;
//     if ((t_sum - d) < 0)
//         return 0;
//     int s1 = (t_sum - d) / 2;
//     vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
//     return subsetSumToK(arr, n - 1, s1, dp);
// }
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vi arr(n);
        input(arr, 0, n - 1);
        int ans = countPartitions(n, d, arr);
        cout << ans << endl;
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