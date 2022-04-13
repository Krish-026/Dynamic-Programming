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
#define int ll
#define mod (int)(1e9 + 7)
// Recursion
// int fun(int i, int j, vector<vector<int>>&mat){
// 	if(i >= 0 and j >= 0 and mat[i][j] == -1)
// 		return 0;
// 	if(i == 0 and j == 0)
// 		return 1;
// 	if(i < 0 || j < 0)
// 		return 0;
// 	int up = fun(i-1, j, mat);
// 	int left = fun(i, j-1, mat);
// 	return up+left;
// }

// Memoization
//  int fun(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&dp){
//  	if(i >= 0 and j >= 0 and mat[i][j] == -1)
//  		return 0;
//  	if(i == 0 and j == 0)
//  		return 1;
//  	if(i < 0 || j < 0)
//  		return 0;
//  	if(dp[i][j] != -1)
//  		return dp[i][j];
//  	int up = fun(i-1, j, mat, dp) % mod;
//  	int left = fun(i, j-1, mat, dp) %mod;
//  	return dp[i][j] = (up+left)%mod;
//  }

// Tabulation
//  int fun(int m, int n, vector<vector<int>>&mat, vector<vector<int>>&dp){
//  	for(int i = 0; i <= m; ++i){
//  		for(int j = 0; j <= n; ++j){
//  			int up = 0, left = 0;
//  			if(mat[i][j] == -1){
//  				dp[i][j] = 0;
//  				continue;
//  			}
//  			if(i == 0 and j == 0){
//  				dp[i][j] = 1;
//  				continue;
//  			}
//  			if(i - 1 >= 0)
//  				up = dp[i-1][j] % mod;
//  			if(j - 1 >= 0)
//  				left = dp[i][j-1] %mod;
//  			dp[i][j] = (up + left) %mod;
//  		}
//  	}
//  	return dp[m][n];
//  }

// Space Optimixation
int fun(int m, int n, vector<vector<int>> &mat, vector<int> &prev)
{
    for (int i = 0; i <= m; ++i)
    {
        vector<int> curr(n + 1, -1);
        for (int j = 0; j <= n; ++j)
        {
            int up = 0, left = 0;
            if (mat[i][j] == -1)
            {
                curr[j] = 0;
                continue;
            }
            if (i == 0 and j == 0)
            {
                curr[j] = 1;
                continue;
            }
            if (i - 1 >= 0)
                up = prev[j] % mod;
            if (j - 1 >= 0)
                left = curr[j - 1] % mod;
            curr[j] = (up + left) % mod;
        }
        prev = curr;
    }
    return prev[n];
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<int> dp(m, -1);
    // vector<vector<int>>dp(n, vector<int>(m, -1));
    return fun(n - 1, m - 1, mat, dp);
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        rep(i, 0, n - 1)
                rep(j, 0, m - 1)
                    cin >>
            mat[i][j];
        int ans = mazeObstacles(n, m, mat);
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