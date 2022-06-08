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
void subsetSumToK(int n, int target, vector<int> &arr, vector<bool> &prev)
{
    prev[0] = true;
    if (target >= arr[0])
        prev[arr[0]] = true;
    for (int i = 1; i < n; ++i)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int j = 1; j <= target; ++j)
        {
            bool notpick = prev[j];
            bool pick = false;
            if (j >= arr[i])
                pick = prev[j - arr[i]];
            curr[j] = notpick || pick;
        }
        prev = curr;
    }
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total_sum = 0;
    for (int i = 0; i < n; ++i)
        total_sum += arr[i];
    vector<bool> dp(total_sum / 2 + 2, false);

    subsetSumToK(n, total_sum / 2 + 2, arr, dp);

    int ans = INT_MAX;
    for (int i = 0; i < dp.size(); ++i)
    {
        if (dp[i])
        {
            // int s1 = i;
            // int s2 = total_sum - s1;
            // ans = min(ans, abs(s1 - s2));
            ans = min(ans, abs(2 * i - total_sum));
        }
    }
    return ans;
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
        int ans = minSubsetSumDifference(arr, n);
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