#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 *Link:- https://leetcode.com/problems/maximum-product-subarray/
 * Brutforce:-
 *  Simple calculate product of each subarray
 *  TC:- O(n^2) SC:- O(1)
 *
 */
// -----------------------------------------------------------------------
/**
 * Approach 1:-
 *
 * 1.Calculate prefix and suffix product and keep taking max at each step
 *  TC:- O(n) SC:- O(1)
 *
 */
class Solution1
{
public:
    int maxProduct(vector<int> &nums)
    {
        int curr_sum = 1, post = 1;
        int ans = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {

            if (curr_sum == 0)
                curr_sum = 1;
            if (post == 0)
                post = 1;

            curr_sum *= nums[i];
            post *= nums[n - i - 1];

            ans = max(ans, max(curr_sum, post));
        }

        return ans;
    }
};

// -----------------------------------------------------------------------
/**
 * Approach 1:-
 *
 * 1.Using DP
 *  Key point is that negative number becomes positive and positive becomes negatie once it is multiplied by negative number , hence we swap them if the current number is negative
 * -> Also if the current number is zero we start reset the array hence max(curr, curr*maxi) and min(curr, curr*mini);
 *  TC:- O(n) SC:- O(1)
 *
 */
class Solution2
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        int mini = nums[0], maxi = nums[0], ans = nums[0];

        for (int i = 1; i < n; i++)
        {
            int curr = nums[i];

            if (curr < 0)
            {
                swap(mini, maxi);
            }

            mini = min(curr, mini * curr);
            maxi = max(curr, maxi * curr);

            ans = max(ans, max(mini, maxi));
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
