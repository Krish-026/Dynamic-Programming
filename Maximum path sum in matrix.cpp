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
#define int ll
#define Mod 1000000007
using namespace std;
// Recursion
// int fun(vector<vector<int>> arr, int i, int j)
// {
//     if (j < 0 || j >= arr[0].size())
//         return -1e9;
//     if (i == 0)
//         return arr[0][j];
//     int up = arr[i][j] + fun(arr, i - 1, j);
//     int upleftdiagonal = arr[i][j] + fun(arr, i - 1, j - 1);
//     int uprightdiagonal = arr[i][j] + fun(arr, i - 1, j + 1);
//     int ans = max(up, max(upleftdiagonal, uprightdiagonal));
//     return ans;
// }
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int ans = INT_MIN;
//     rep(j, 0, n - 1)
//     {
//         ans = max(ans, fun(matrix, m - 1, j));
//     }
//     return ans;
// }

// Memoization
// int fun(vector<vector<int>> arr, int i, int j, vector<vector<int>> dp)
// {
//     if (j < 0 || j >= arr[0].size())
//         return -1e9;
//     if (i == 0)
//         return arr[0][j];
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     int up = arr[i][j] + fun(arr, i - 1, j, dp);
//     int upleftdiagonal = arr[i][j] + fun(arr, i - 1, j - 1, dp);
//     int uprightdiagonal = arr[i][j] + fun(arr, i - 1, j + 1, dp);
//     dp[i][j] = max(up, max(upleftdiagonal, uprightdiagonal));
//     return dp[i][j];
// }
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     int ans = INT_MIN;
//     for (int j = 0; j < n; ++j)
//     {
//         ans = max(ans, fun(matrix, m - 1, j, dp));
//     }
//     return ans;
// }

// Tabulation
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     int ans = INT_MIN;
//     for (int j = 0; j < n; ++j)
//     {
//         dp[0][j] = matrix[0][j];
//     }
//     for (int i = 1; i < m; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             int up, uprightdiagonal, upleftdiagonal;
//             up = upleftdiagonal = uprightdiagonal = matrix[i][j];
//             up += dp[i - 1][j];
//             if (j > 0)
//                 upleftdiagonal += dp[i - 1][j - 1];
//             if (j < n - 1)
//                 uprightdiagonal += dp[i - 1][j + 1];
//             dp[i][j] = max(up, max(upleftdiagonal, uprightdiagonal));
//             if (i == n - 1)
//                 ans = max(dp[i][j], ans);
//         }
//     }
//     return ans;
// }

// Space Optimization
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     vector<int> prev(n, -1);
//     int ans = INT_MIN;
//     for (int j = 0; j < n; ++j)
//     {
//         prev[j] = matrix[0][j];
//     }
//     for (int i = 1; i < m; ++i)
//     {
//         vector<int> curr(n, 0);
//         for (int j = 0; j < n; ++j)
//         {
//             int up, uprightdiagonal, upleftdiagonal;
//             up = upleftdiagonal = uprightdiagonal = matrix[i][j];
//             up += prev[j];
//             if (j > 0)
//                 upleftdiagonal += prev[j - 1];
//             if (j < n - 1)
//                 uprightdiagonal += prev[j + 1];
//             curr[j] = max(up, max(upleftdiagonal, uprightdiagonal));
//         }
//         prev = curr;
//     }

//     for (int i = 0; i < n; i++)
//         ans = max(ans, prev[i]);
//     return ans;
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> prev(n, -1);
    int ans = INT_MIN;
    for (int i = 1; i < m; ++i)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; ++j)
        {
            if (j > 0 and j < n - 1)
                matrix[i][j] += max(matrix[i - 1][j], max(matrix[i - 1][j - 1], matrix[i - 1][j + 1]));
            else if (j > 0)
                matrix[i][j] += max(matrix[i - 1][j], matrix[i - 1][j - 1]);
            else if (j < n - 1)
                matrix[i][j] += max(matrix[i - 1][j], matrix[i - 1][j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        ans = max(ans, matrix[m - 1][i]);
    return ans;
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n, 0));
        rep(i, 0, m - 1)
        {
            rep(j, 0, n - 1)
            {
                cin >> arr[i][j];
            }
        }

        int ans = getMaxPathSum(arr);
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