import java.util.* ;    

public class Solution {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           int[][] arr = new int[n][3] ; 
           for( int i=0 ; i<n ; ++i ){
               arr[i][0] = sc.nextInt() ; 
           }
           for( int i=0 ; i<n ; ++i ){
               arr[i][1] = sc.nextInt() ; 
           }
           for( int i=0 ; i<n ; ++i ){
               arr[i][2] = sc.nextInt() ; 
           }
           int[][] max = new int[n][3] ;
           for( int i=n-2 ; i>=1 ; --i ){
               max[i][0] = Math.max( max[i+1][0] , arr[i+1][0] ) ; 
               max[i][1] = Math.max( max[i+1][1] , arr[i+1][1] ) ; 
               max[i][2] = Math.max( max[i+1][2] , arr[i+1][2] ) ; 
           }
           int[] left = new int[3] ; 
           left[0] = arr[0][0] ; 
           left[1] = arr[0][1] ;
           left[2] = arr[0][2] ; 
           int rs = -1 ;
           for( int i=1 ; i<n-1 ; ++i ){
              rs = Math.max( rs , arr[i][0] + left[1] + max[i][2] );
              rs = Math.max( rs , arr[i][0] + left[2] + max[i][1] );
              rs = Math.max( rs , arr[i][1] + left[0] + max[i][2] );
              rs = Math.max( rs , arr[i][1] + left[2] + max[i][0] );
              rs = Math.max( rs , arr[i][2] + left[0] + max[i][1] ); 
              rs = Math.max( rs , arr[i][2] + left[1] + max[i][0] ); 
              // Update The Max Left Array 
              left[0] = Math.max( left[0] , arr[i][0] ) ;  
              left[1] = Math.max( left[1] , arr[i][1] ) ;  
              left[2] = Math.max( left[2] , arr[i][2] ) ;  
           }
           System.out.println(rs) ; 
        }
    }
}