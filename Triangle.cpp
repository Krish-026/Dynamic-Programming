// https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
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
#define int ll
using namespace std;
// Recursion
// int fun(vector<vector<int>> &arr, int n, int i, int j)
// {
//     if (i == n - 1)
//         return arr[i][j];
//     int down = arr[i][j] + fun(arr, n, i + 1, j);
//     int diagonal = arr[i][j] + fun(arr, n, i + 1, j + 1);
//     return min(down, diagonal);
// }
// int minimumPathSum(vector<vector<int>> &triangle, int n)
// {
//     return fun(triangle, n, 0, 0);
// }

// Memoization
// int fun(vector<vector<int>> &arr, int n, int i, int j, vector<vector<int>> &dp)
// {
//     if (i == n - 1)
//         return arr[i][j];
//     int down = arr[i][j] + fun(arr, n, i + 1, j, dp);
//     int diagonal = arr[i][j] + fun(arr, n, i + 1, j + 1, dp);
//     return dp[i][j] = min(down, diagonal);
// }
// int minimumPathSum(vector<vector<int>> &triangle, int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return fun(triangle, n, 0, 0, dp);
// }

// int minimumPathSum(vector<vector<int>> &triangle, int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     rep(j, 0, n - 1)
//     {
//         dp[n - 1][j] = triangle[n - 1][j];
//     }
//     repr(i, n - 2, 0)
//     {
//         repr(j, i, 0)
//         {
//             int down = triangle[i][j] + dp[i + 1][j];
//             int diagonal = triangle[i][j] + dp[i + 1][j + 1];

//             dp[i][j] = min(down, diagonal);
//         }
//     }
//     return dp[0][0];
// }

// Space Optimization
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> dp(n, 0);
    rep(i, 0, n - 1)
    {
        dp[i] = triangle[n - 1][i];
    }
    repr(i, n - 2, 0)
    {
        vector<int> temp(n, INT_MAX);
        repr(j, i, 0)
        {
            int down = triangle[i][j] + dp[j];
            int diagonal = triangle[i][j] + dp[j + 1];
            temp[j] = min(down, diagonal);
        }
        dp = temp;
    }
    return dp[0];
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        rep(i, 0, n - 1)
        {
            rep(j, 0, i)
            {
                cin >> arr[i][j];
            }
        }
        int ans = minimumPathSum(arr, n);
        cout << ans << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}