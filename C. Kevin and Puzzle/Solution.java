import java.util.*;

public class Solution {
    static int mod = 998244353;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = sc.nextInt();
            }
            int rs = 0 ; 
            if (n == 1) {
               rs = arr[0] == 0 ? 2 : 1 ; 
            }else if( n == 2 ){
                if( arr[0] == 0 ){
                    rs += arr[1] == 0 ? 2 : 1 ; 
                    rs += arr[1] == 1 ? 1 : 0 ; 
                }else {
                    rs = arr[1] == 1 ? 1 : 0 ; 
                }
            }else {
                // The dp holds the configs such that the i is honest 
                int[] dp = new int[n];
                dp[0] = arr[0] == 0 ? 1 : 0 ;
                if( arr[0] == 0  ){
                     if( arr[1] <= 1 ){
                         dp[1] = 1 ; 
                     }
                }else {
                    dp[1] = arr[1] == 1 ? 1 : 0 ; 
                }
                
                for( int i=2 ; i<n ; ++i ){
                    if( arr[i] == arr[i-1] ){
                        dp[i] = ( dp[i] + dp[i-1] ) % mod ; 
                    }
                    if( arr[i] == arr[i-2] +1 ){
                        dp[i] = ( dp[i] + dp[i-2] ) % mod ; 
                    }
                }
                // The number of configs such that the last is honest ( dp[n-1] )
                // + 
                // The number of configs such that the last is liar ( dp[n-2] )
                rs = ( dp[n-1] + dp[n-2] ) % mod ; 
            }
            
            System.out.println(rs);
        }
    }
}
