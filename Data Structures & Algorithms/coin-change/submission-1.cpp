class Solution {
    vector<int> memo;

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (memo[amount] != -2)
            return memo[amount];

        int ans = INT_MAX;

        for (int coin : coins) {
            int res = dfs(coins, amount - coin);

            if (res >= 0)
                ans = min(ans, 1 + res);
        }

        memo[amount] = (ans == INT_MAX) ? -1 : ans;
        return memo[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -2);
        return dfs(coins, amount);
    }
};