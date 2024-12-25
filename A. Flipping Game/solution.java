import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        int[] arr = new int[n] ; 
        for( int i=0 ; i<n ; ++i ){
            arr[i] = sc.nextInt() ; 
        }
        int[][][] dp = new int[n][n][2] ; 
        dp[0][0][arr[0]] = 1 ; 
        for( int i=1 ; i<n ; ++i ){
            dp[0][i][0] = dp[0][i-1][0] ; 
            dp[0][i][1] = dp[0][i-1][1] ; 
            dp[0][i][arr[i]]++ ; 
        }
        for( int i=1 ; i<n ; ++i ){
            for( int j=i ; j<n ; ++j ){
                dp[i][j][0] = dp[0][j][0] - dp[0][i-1][0] ;
                dp[i][j][1] = dp[0][j][1] - dp[0][i-1][1] ;
            }
        }
        int ones = dp[0][n-1][1] ; 
        int rs = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            for( int j=i ; j<n ; ++j ){
                rs = Math.max( rs ,  ones - dp[i][j][1] + dp[i][j][0] ) ; 
            }
        }
        System.out.println(rs) ; 
    }
}
