import java.util.* ; 

public class C {
    public static boolean isPrime( int n ){
        if( n == 3 ) return true ; 
        if( n % 3 == 0 ) return false ;  
        int i = 5 ; 
        while( i*i <= n ){
            if( n % i == 0 || n%(i+2) == 0 ){
                return false ; 
            }
            i += 6 ; 
        }
        return true ; 
    }
    public static boolean check( int n ){
        if( n == 1 ){
            return false ; 
        }
        if( n == 2 ){
            return true ; 
        }
        // Making in it 1 
        if( n % 2 == 1 ){
            return true ; 
        }
        // The number is even 
        if( (n & (n-1) ) == 0 ){
            return false ; 
        }
        if( n % 4 == 0 ){
            return true ; 
        }
        // There is only one 2 and some other odd factors 
        // I should Get the 2 
        if( isPrime( n >> 1 ) ){
            return false ;
        }
        return true ; 
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           if( check( n ) ){
               System.out.println( "Ashishgup" ) ; 
           }else {
               System.out.println( "FastestFinger" ) ; 
           }
           
        }
    }
}