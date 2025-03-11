import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           int k = sc.nextInt() ; 
           int[] arr = new int[32] ;
           for( int i=0 ; i<n ; ++i ){
               int a = sc.nextInt() ; 
               int curr = 0 ;
               while( a > 0 ){
                   if( a % 2 == 1 ){
                       arr[curr]++ ; 
                   }
                   a >>= 1 ; 
                   curr++ ; 
               }
           }
           int rs = 0 ; 
           for( int i=30 ; i>=0 ; --i ){
               if( n - arr[i] <= k ){
                   rs |= ( 1 << i ) ; 
                   k -= ( n - arr[i] ) ; 
               }
           }
           
           System.out.println( rs ) ; 
        }
    }
    
}