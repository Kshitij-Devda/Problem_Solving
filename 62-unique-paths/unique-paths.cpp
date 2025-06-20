class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n > m) swap(m,n);        // m is always greater than n

        long ans = 1;               // long to avoid OVERFLOW!!!

        m-- , n--;                  // we just need m-1 and n-1

        for(int i = m+n , j = 1 ; i > m || j <= n ; i-- , j++){

            ans *= i;               // multiply and divide on every
            if(j <= n) ans /= j;    // iteration so you increase and
                                    // decrease value.
        }
        return ans;
    }
};