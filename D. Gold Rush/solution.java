import java.util.Scanner;

public class D {
    public static boolean check( int n  , int m ){
        if( n == m ){
            return true ; 
        }
        if( m > n || n%3 != 0 ) return false ; 
        return check( n/3 , m ) || check( 2*n/3 , m ) ; 
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt() ; 
            int m = sc.nextInt() ; 
            if( check( n , m ) ){
                System.out.println("YES") ; 
            }else {
                System.out.println("NO") ; 
            }
            
        }
    }
}
