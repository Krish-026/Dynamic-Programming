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
// int fun(vector<vector<int>> &arr, int i, int j)
// {
//     if (i == 0 and j == 0)
//         return arr[i][j];
//     if (i < 0 || j < 0)
//         return 1e9;
//     int up = arr[i][j] + fun(arr, i - 1, j);
//     int left = arr[i][j] + fun(arr, i, j - 1);
//     return min(left, up);
// }
// int minSumPath(vector<vector<int>> &grid)
// {
//     int m = grid.size();
//     int n = grid[0].size();
//     return fun(grid, m - 1, n - 1);
// }

// Memoization
// int fun(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp)
// {
//     if (i == 0 and j == 0)
//         return arr[i][j];
//     if (i < 0 || j < 0)
//         return 1e9;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     int up = arr[i][j] + fun(arr, i - 1, j, dp);
//     int left = arr[i][j] + fun(arr, i, j - 1, dp);
//     return dp[i][j] = min(left, up);
// }

// Tabulation
// int fun(vector<vector<int>> &arr, int m, int n)
// {
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//     dp[0][0] = arr[0][0];
//     rep(i, 0, m)
//     {
//         rep(j, 0, n)
//         {
//             if (i == 0 and j == 0)
//             {
//                 dp[0][0] = arr[0][0];
//                 continue;
//             }
//             int up = 0, left = 0;
//             up = left = arr[i][j];
//             if (i - 1 >= 0)
//                 up += dp[i - 1][j];
//             else
//                 up += 1e9;
//             if (j - 1 >= 0)
//                 left += dp[i][j - 1];
//             else
//                 left += 1e9;
//             dp[i][j] = min(up, left);
//         }
//     }
//     return dp[m][n];
// }

// Space Optimization
int fun(vector<vector<int>> &arr, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    dp[0][0] = arr[0][0];
    rep(i, 0, m)
    {
        rep(j, 0, n)
        {
            if (i == 0 and j == 0)
            {
                dp[0][0] = arr[0][0];
                continue;
            }
            int up = 0, left = 0;
            up = left = arr[i][j];
            if (i - 1 >= 0)
                up += dp[i - 1][j];
            else
                up += 1e9;
            if (j - 1 >= 0)
                left += dp[i][j - 1];
            else
                left += 1e9;
            dp[i][j] = min(up, left);
        }
    }
    return dp[m][n];
}

int minSumPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    return fun(grid, m - 1, n - 1);
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        rep(i, 0, m - 1)
        {
            rep(j, 0, n - 1)
            {
                cin >> grid[i][j];
            }
        }
        int ans = minSumPath(grid);
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