import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        int mod = 998244353 ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] dp = new int[4] ; 
            for( int i=0 ; i<n ; ++i ){
                int a = sc.nextInt() ; 
                if( a == 1 ){
                    dp[1]++ ; 
                }else if( a == 2 ){
                    dp[2] = ( 2*dp[2]  + dp[1] ) % mod ; 
                }else {
                    dp[3] = ( dp[3] + dp[2] ) % mod ; 
                    // We can have multiple 2s between the ones and the threes 
                }
            }
            System.out.println( dp[3] ) ; 
        }
    }
}