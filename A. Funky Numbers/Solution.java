import java.util.* ; 

public class Solution {
    public static boolean isTriangular( long n ){
        if( n == 0 ) return false ; 
        long l = 1 ; 
        long r = n ; 
        while( l < r ){
            long mid = l + ( r - l )/2 ; 
            long a = mid * mid + mid - 2*n ; 
            if( a < 0 ){
                l = mid+1 ;
            }else if( a > 0 ){
                r = mid-1 ; 
            }else {
                return true ; 
            }
        }
        return l*l + l - 2*n == 0L ; 
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        long n = sc.nextLong() ; 
        long i = 1 ; 
        while( i*(i+1)/2 <= n ){
            if( isTriangular( n - i*(i+1)/2  ) ){
                System.out.println( "YES" ) ; 
                return  ; 
            }
            i++ ; 
        }
        System.out.println( "NO" ) ; 
    }
}