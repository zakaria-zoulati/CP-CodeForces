import java.util.Scanner ;

public class sol {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt()  ;
        for( int c=0 ; c<t  ; ++c ){
            int a = sc.nextInt() ;
            int b = sc.nextInt() ;
            if( a >= b  ){
                System.out.println( a ) ;
            }else {
                int i=1  ;
                int rs = b-a <= a ? 2*a - b : 0 ;
                System.out.println(rs) ;
            }
        }
    }
}
