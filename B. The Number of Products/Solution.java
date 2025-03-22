import java.util.* ; 

public class Solution {
    public static void main( String[]  args ){
        Scanner sc = new Scanner( System.in ) ; 
        // int t = sc.nextInt() ; 
        int t = 1 ;
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           int[] arr = new int[n] ; 
           for( int i=0 ; i<n ; ++i ){
               arr[i] = sc.nextInt() ; 
           }
           
           long a = 0 ; 
           long b = 0 ;            
           
           int curr = 1 ; 
           int pos = 0 ;
           int neg = 0 ; 
           for( int i=0 ; i<n ; ++i ){
               if( arr[i] < 0 ){
                   curr *= -1 ; 
               }
               if( curr == 1 ){
                   pos++ ;
                   a += pos ; 
               }else {
                   a += neg ; 
                   neg++ ; 
               }
           }
           
           b = (long) n*(n+1)/2 - a ; 
           System.out.println( b + "  " + a ) ; 
           
        }
    }
}