import java.util.* ;    

public class Solution {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           int[] arr = new int[n] ; 
           for( int i=0 ; i<n ; ++i ){
               arr[i] = sc.nextInt() ; 
           }
           long rs = Long.MIN_VALUE ; a
           for( int i=0 ; i<n ; ++i ){
               long curr = arr[i] ; 
               rs = Math.max( rs , curr );
               while( i+1<n && Math.abs(arr[i+1] % 2) != Math.abs(arr[i] % 2) ){
                   curr = Math.max( arr[i+1] , arr[i+1] + curr ) ; 
                   i++ ;
                   rs = Math.max( rs , curr ) ; 
               }
           }
           System.out.println( rs ) ; 
        }
    }
}