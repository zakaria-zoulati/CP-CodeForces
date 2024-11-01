import java.util.Scanner ;

public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            if( n < 9 ){
                System.out.println(0) ; 
            }else {
                int rs = 1 ; 
                n -= 9 ; 
                rs += n/10 ; 
                System.out.println(rs) ; 
            }
        }
    }
}












