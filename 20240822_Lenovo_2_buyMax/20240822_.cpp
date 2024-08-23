#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> w(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> w[i];
    }
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    dp[0][0] = a[0] * w[0];

    for (int col = 1; col < n; col++)
    {
        dp[0][col] = max(a[col] * w[0], dp[0][col-1]);
    }

    for (int row = 1; row < dp.size(); row++)
    {
        for (int col = row; col < dp[row].size(); col++)
        {
            dp[row][col] = dp[row - 1][col - 1] + a[col]*w[row];
        }
    }

    cout << dp[m - 1][n - 1] << endl;

    return 0;
}