import java.util.* ;    

public class Solution {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        // int t = 1 ;
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           int[] arr = new int[n] ; 
           for( int i=0 ; i<n ; ++i ){
               arr[i] = sc.nextInt() ; 
           }
           int min = Integer.MAX_VALUE ; 
           for( int i : arr ){
               min = Math.min( min , i ) ; 
           }
           if( arr[0] == min ){
               System.out.println( "Bob" ) ; 
           }else {
               System.out.println( "Alice" ) ; 
           }
           
        }
    }
}