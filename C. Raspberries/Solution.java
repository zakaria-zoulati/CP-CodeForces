import java.util.* ;    

public class Solution {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           int k = sc.nextInt() ; 
           int[] arr = new int[n] ; 
           for( int i=0 ; i<n ; ++i ){
               arr[i] = sc.nextInt() ; 
           }
           int rs = Integer.MAX_VALUE ; 
           if( k == 4 ){
               int prev = arr[0] % 2 ; 
               rs = Math.min( rs , arr[0]%4 == 0 ? 0 : 4 - arr[0]%4 ) ; 
               for( int i=1 ; i<n ; ++i ){
                   rs = Math.min( rs , arr[i]%4 == 0 ? 0 : 4 - arr[i]%4 ) ; 
                   rs = Math.min( rs , arr[i] % 2 + prev ) ; 
                   prev = Math.min( prev , arr[i] % 2 ) ; 
               }
           }else {
               for( int i : arr ){
                   rs = Math.min( rs , i%k == 0 ? 0 : k-i%k ) ; 
               }
           }
           
           System.out.println(rs) ; 
        }
    }
}