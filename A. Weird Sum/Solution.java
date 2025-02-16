import java.util.* ; 
public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int m = sc.nextInt() ; 
        int[][] g = new int[n][m] ; 
        long[][] count = new long[ 100_001 ][2] ; 
        long rs = 0L ; 
        for( int i=0 ; i<n ; ++i ){
            for( int j=0 ; j<m ; ++j ){
                g[i][j] = sc.nextInt() ;
                // Use The lines while computing the grid
                rs += count[ g[i][j] ][1]*i - count[ g[i][j] ][0] ;  
                count[ g[i][j] ][0] += i ; 
                count[ g[i][j] ][1]++ ; 
            }
        }
        // Traverse By Columns 
        count = new long[ 100_001 ][2] ;
        for( int i=0 ; i<m ; ++i ){
            for( int j=0 ; j<n ; ++j ){
                rs += count[ g[j][i] ][1]*i - count[ g[j][i] ][0] ;  
                count[ g[j][i] ][0] += i ; 
                count[ g[j][i] ][1]++ ; 
            }
        }
        System.out.println(rs) ;
    }   
}