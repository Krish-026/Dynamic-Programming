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

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; ++i)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= tar; ++j)
        {
            int notPick = dp[i - 1][j];
            int pick = 0;
            if (num[i] <= j)
                pick = dp[i - 1][j - num[i]];
            dp[i][j] = pick + notPick;
        }
    }

    return dp[n - 1][tar];
}

// Memoization
// int countSubsetSumToK(vector<int> &arr, int n, int target, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return 1;
//     if (n == 0)
//         return (arr[0] == target);
// // The above two case fails when num[i] = 0; so use below code
// //
// // if(n == 0){
// //     if(target == 0 and arr[0] == 0) return 2; // two choice at arr[0] = 0; pick or not pick
// //     if(target == 0 || target == arr[0]) return 1;// when last target is achieved of last = arr[0] ;
// //     else    return 0;
// // }
//     if (dp[n][target] != -1)
//         return (dp[n][target]);
//     int notPick = countSubsetSumToK(arr, n - 1, target, dp);
//     int pick = 0;
//     if (arr[n] <= target)
//         pick = countSubsetSumToK(arr, n - 1, target - arr[n], dp);

//     return dp[n][target] = pick + notPick;
// }
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
//     return countSubsetSumToK(num, n - 1, tar, dp);
// }

// Recursion
// int countSubsetSumToK(vector<int> &arr, int n, int target)
// {
//     if (target == 0)
//         return 1;
//     if (n == 0)
//         return (arr[0] == target);
//     int notPick = countSubsetSumToK(arr, n - 1, target);
//     int pick = 0;
//     if (arr[n] <= target)
//         pick = countSubsetSumToK(arr, n - 1, target - arr[n]);

//     return pick + notPick;
// }
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     return countSubsetSumToK(num, n - 1, tar);
// }
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        vi arr(n);
        input(arr, 0, n - 1);
        int ans = findWays(arr, target);
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