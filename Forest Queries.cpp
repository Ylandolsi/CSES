#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long

class Solution
{
public:
    void solve() {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char x;
                cin >> x;
                if (x == '*') mat[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++)
                mat[i][j] += mat[i][j - 1];
            
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++)
                mat[i][j] += mat[i - 1][j];
            
        }
        for (int i = 0; i < q; i++){
            int x1, y1, x2, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            int SUM = mat[y2][x2];
            int DOWNL = mat[y2][x1 - 1];
            int UPR = mat[y1 - 1][x2];
            int UPL = mat[y1 - 1][x1 - 1];
            int all = SUM - DOWNL - UPR + UPL;
            cout << all << endl;
        }
    }
};

signed main()
{
    SPEED;
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif

    int t = 1;
    Solution sol;
    while (t--)
        sol.solve();
    return 0;
}
