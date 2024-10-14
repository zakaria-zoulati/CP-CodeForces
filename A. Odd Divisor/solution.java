import java.util.Scanner ; 

public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        for( int c = 0 ;  c < t ; ++c ){
            long n = sc.nextLong() ; 
            if( n%2 == 1 ){
                System.out.println("YES") ; 
            }else if( (n & ( n-1 ) ) == 0L )  {
                System.out.println("NO") ; 
            }else {
                System.out.println("YES") ; 
            }
        }
    }
}