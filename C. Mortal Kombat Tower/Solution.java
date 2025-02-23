import java.util.*; 
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            for( int i=0 ; i<n ; ++i ){
                arr[i] = sc.nextInt() ; 
            }
            if( n <= 3 ){
                System.out.println( arr[0] ) ; 
                continue ; 
            }
            int[][] dp = new int[n][4] ;
            // Should do a good analytics for the first 
            dp[2][0] = arr[0] + arr[2] ; 
            dp[2][1] = Integer.MAX_VALUE ; 
            dp[2][2] = arr[0] + arr[1] ; 
            dp[2][3] = arr[0] ; 
            for( int i=3 ; i<n ; ++i ){
                // If the player 2 plays 
                dp[i][2] = Math.min( dp[i-1][0] , dp[i-1][1] ) ;
                dp[i][3] = dp[i-1][2] ;
                // If the player 1 plays 
                dp[i][0] = Math.min( dp[i-1][2] , dp[i-1][3] ) + arr[i] ; 
                dp[i][1] = dp[i-1][0] + arr[i] ; 
            }
            int rs = Math.min( dp[n-1][0] , dp[n-1][1] ) ; 
            rs = Math.min( rs , dp[n-1][2] ) ; 
            rs = Math.min( rs , dp[n-1][3] ) ; 
            System.out.println(rs) ; 
        }
    }
}
