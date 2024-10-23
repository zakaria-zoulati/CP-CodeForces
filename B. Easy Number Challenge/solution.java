import java.util.Scanner ; 

public class F {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int mod = 1 << 30 ; 
        int rs = 0; 
        int a = sc.nextInt() ; 
        int b = sc.nextInt() ; 
        int c = sc.nextInt() ;
        
        int len  = a*b*c + 1 ; 
        int[] dp = new int[len] ;
        
        // Sieve of divisors
        for (int i = 1; i < len; ++i) {
            for (int j = i; j < len; j += i) {
                ++dp[j];  // i is a divisor of j
            }
        }
        
        for( int i=1 ; i<=a ; ++i ){
            for( int j=1 ; j<=b ; ++j ){
                for( int k=1 ; k<=c ; ++k ){
                    rs = ( rs + dp[i*j*k] ) % mod ; 
                }
            }
        }
        
        System.out.println(rs) ; 
    }
}
