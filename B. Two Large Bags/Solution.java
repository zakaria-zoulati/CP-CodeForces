import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] f = new int[n+1] ; 
            for( int i=0 ; i<n ; ++i ){
                f[ sc.nextInt() ]++ ; 
            }
            boolean rs = true ; 
            int actions = 0 ; 
            for( int i=1 ; i<=n ; ++i ){
                if( f[i] % 2 == 0  ){
                    if( i+1 <=n && f[i] > 0  ){
                        f[i+1] += f[i] - 2 ; 
                    }
                }
                if( f[i] % 2 == 1 ) {
                    if( f[i] == 1 || i == n ) {
                        rs = false ; 
                        break ; 
                    }else {
                        if( i+1 <=n ){
                            f[i+1] += f[i] -2 ; 
                        }
                    }
                }
            }
            System.out.println( rs ? "YES" : "NO" ) ; 
        }
    }
}
