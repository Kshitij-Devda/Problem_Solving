class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n < m) return 0;

        using long_long = unsigned long long;
        vector<long_long> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            long_long last = prev[0];
            for (int j = 1; j <= m; j++) {
                long_long temp = prev[j];
                long_long pick = 0, notpick = 0;

                if (s[i - 1] == t[j - 1]) {
                    pick = last;
                }
                notpick = temp;
                prev[j] = pick + notpick;

                last = temp;
            }
        }
        return (int)prev[m];
    }
};