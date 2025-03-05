import java.util.* ; 

public class A {
    public static long countFactors( long n ){
        if( n == 3L || n == 2L || n == 1L ) return 1L ; 
        long count = 0L ; 
        long m = n ; 
        if( m % 2 == 0 ){
            while( m %  2 == 0 ){
                m >>= 1 ; 
                count++ ; 
            }
        } 
        if( m % 3 == 0 ){
            while( m % 3 == 0 ){
                m /= 3 ; 
                count++ ; 
            }
        }
        long i = 5 ; 
        while( i*i <= n ){
            if( m % i == 0  ){
                while( m % i == 0 ){
                    m /= i ; 
                    count++ ; 
                }
            }
            if( m % (i+2) == 0 ){
                while( m % (i+2) == 0 ){
                    m /= (i+2) ; 
                    count++ ; 
                }
            }
            i += 6 ; 
        }
        if( m > 1 ){
            count++ ; 
        } 
        return count ; 
    }
    public static long getFactors( long n ){
       int count = 0 ; 
       long rs = 1L ; 
       long m = n ; 
       while( m % 2 == 0L && count < 2 ){
           rs <<= 1 ; 
           count++ ; 
           m >>= 1 ; 
       }
       while( m % 3 == 0L && count < 2 ){
           rs *= 3 ; 
           count++ ; 
           m /= 3 ;
       }
       long i = 5 ; 
       while( i*i <= n && count < 2 ){
           while( m % i == 0 && count < 2 ){
               count++ ; 
               rs *= i ; 
               m /= i ; 
           }
           while( m % (i+2) == 0 && count < 2 ){
               count++ ; 
               rs *= (i+2) ; 
               m /= (i+2) ; 
           }
           i += 6 ; 
       }
       return rs  ;
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        
        long n = sc.nextLong() ; 
        
       // Get the number of distinct prime factors 
       long factors = countFactors(n) ; 
       
       // If There is only one 
       if( factors == 2L ){
           System.out.println( 2 ) ; 
       }else if( factors == 1L ){
           System.out.println( 1 ) ; 
           System.out.println( 0 ) ; 
       }else {
           long two_factors = getFactors(n) ; 
           System.out.println( 1 ) ; 
           System.out.println( two_factors ) ; 
       }
    }
}