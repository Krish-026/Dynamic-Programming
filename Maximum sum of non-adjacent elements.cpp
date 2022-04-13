// https : // www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
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

// Recursion
// int Solution(vi &arr, int n)
// {
//     if (n == 0)
//         return arr[0];
//     if (n < 0)
//         return 0;
//     int pick = arr[n] + Solution(arr, n - 2);
//     int NotPick = 0 + Solution(arr, n - 1);
//     return max(pick, NotPick);
// }

// Memoization
//  int Solution(vi &arr, vi &dp, int n)
//  {
//      if (n == 0)
//          return arr[0];
//      if (n < 0)
//          return 0;
//      if (dp[n] != -1)
//          return dp[n];

//     int pick = arr[n] + Solution(arr, dp, n - 2);
//     int NotPick = 0 + Solution(arr, dp, n - 1);
//     dp[n] = max(pick, NotPick);
//     return dp[n];
// }

// Tabulation
int Solution(vi &arr, vi &dp, int n)
{
    dp[0] = arr[0];
    rep(i, 1, n)
    {
        int pick = arr[i];
        if (i - 2 >= 0)
            pick += dp[i - 2];
        int NotPick = 0 + dp[i - 1];
        dp[i] = max(pick, NotPick);
    }
    return dp[n];
}

// Space Optimization
int Solution(vi &arr, int n)
{
    int prev1 = arr[0], prev2 = 0;
    rep(i, 1, n)
    {
        int curr = 0;
        int pick = arr[i];
        if (i - 2 >= 0)
            pick += prev2;
        int NotPick = 0 + prev1;
        curr = max(pick, NotPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &arr)
{
    int n = arr.size();
    return Solution(arr, n - 1);
    // vi dp(n, -1);
    // return Solution(arr, dp, n - 1);
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr, 0, n - 1);
        cout << maximumNonAdjacentSum(arr) << endl;
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