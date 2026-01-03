#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 * Brutforce:-
 *
 * Normal tabulation dp:-
 * keep the length till that index in dp array
 * now for each new element comapre with all the previous length's of dp array and if the previous element is stricty less than current take it in comparasion and calculatte the maximum length from all previous
 * now add 1 to max of all dps
 *
 * ans is maximums from all the dp array.
 */
class TabulationDp
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = dp[0];

        for (int i = 1; i < n; i++)
        {
            int maxi = -1;
            for (int j = (i - 1); j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    maxi = max(maxi, dp[j]);
                }
            }

            if (maxi != -1)
                dp[i] = (1 + maxi);

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test;
    cin >> test;

    for (int t = 1; t <= test; t++)
    {
        solve();
    }

    return 0;
}
