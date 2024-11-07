import java.util.Scanner ; 
import java.util.Arrays ;
public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int n = sc.nextInt() ; 
        int a = sc.nextInt() ; 
        int b = sc.nextInt() ; 
        int c = sc.nextInt() ; 
        int b1 = n/a ; 
        int b2 = n/b ; 
        int rs = 0 ;
        for( int i=0 ; i<=b1 ; ++i ){
            for( int j=0 ; j<=b2 ; ++j ){
                int num = a*i+b*j ; 
                if( num > n ) break ; 
                if( (n-num)%c == 0 ){
                    rs = Math.max( rs , (n-num)/c + i +j ) ; 
                }
            }
        }
        System.out.println(rs) ; 
    }
}
