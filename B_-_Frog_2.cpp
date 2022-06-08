// https://atcoder.jp/contests/dp/tasks/dp_b
// Kth Jump
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
int minEnergy(vector<int> &h, int n, int k)
{
    if (n == 0)
        return 0;
    int minJump = INT_MAX;
    rep(i, 1, k)
    {
        // int mink = INT_MAX;
        if (n - i >= 0)
        {
            // mink = minEnergy(h, n - i, k) + abs(h[n] - h[n - i]);
            // minJump = min(mink, minJump);
            minJump = min(minEnergy(h, n - i, k) + abs(h[n] - h[n - i]), minJump);
        }
    }
    return minJump;
}
int K_jump(vector<int> &heights, int n, int jump)
{
    return minEnergy(heights, n - 1, jump);
}

// Tabulation
// int K_jump(vl &arr, int n, int k)
// {
//     vl dp(n, 0);
//     dp[0] = 0;
//     rep(i, 1, n - 1)
//     {
//         int minJump = INT_MAX;
//         rep(j, 1, k)
//         {
//             if (i - j >= 0)
//             {
//                 int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
//                 minJump = min(minJump, jump);
//             }
//         }
//         dp[i] = minJump;
//     }
//     return dp[n - 1];
// }
void solve()
{
    int n, jump;
    cin >> n >> jump;
    vi height(n);
    input(height, 0, n - 1);
    cout << K_jump(height, n, jump);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}