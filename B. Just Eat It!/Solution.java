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
           boolean flag = false ; 
           long curr = 0L ; 
           for( int i : arr ){
               curr += i ; 
               if( curr <= 0 ){
                   flag = true ; 
                   break ; 
               } 
           } 
           if( flag ){
               System.out.println( "NO" ) ; 
           }else {
               curr = 0 ; 
               for( int i=n-1 ; i>=0 ; --i ){
                   curr += arr[i] ; 
                   if( curr <= 0 ){
                       flag = true ;
                       break ; 
                   }
               }
               System.out.println( flag ? "NO" : "YES" ) ; 
           }

        }
    }
}