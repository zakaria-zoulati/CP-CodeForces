import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        long[] arr = new long[n] ; 
        for( int i=0 ; i<n ; ++i ){
            arr[i] = sc.nextLong() ; 
        }
        long sum = 0L ; 
        long max = 0L ;
        long e = 0L ; 
        for( long i : arr ){
            e = Math.max( e , i ) ;
            sum += i ;
        }
        if( sum % 2 == 1 ){
            System.out.println( "NO" ) ; 
        }else if( e > sum-e ){
            System.out.println( "NO" ) ; 
        }else {
            System.out.println( "YES" ) ; 
        }
    }
}
