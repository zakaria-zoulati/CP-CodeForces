import java.util.*;

public class Solution {
    public static long modE( long curr , long pow , long mod ){
        if( pow == 0 ){
            return 1L; 
        }else if( pow == 1 ){
            return curr ; 
        }
        long half = pow/2 ; 
        long temp = pow % 2 == 0 ? 1 : curr;  
        curr = (curr*curr)% mod ; 
        return (modE( curr , pow/2 , mod ) * temp ) % mod ;
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long k = sc.nextLong() ; 
        long mod = 1_000_000_007 ; 

        long total = ( 1L << k ) - 2 ; 
        long rs = ( 6 * modE( 4 , total , mod ) ) % mod ; 
        
        System.out.println(rs) ; 
    }
}
