import java.util.Scanner ; 

public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ;
            StringBuilder rs = new StringBuilder() ; 
            rs.append( "1" ) ; 
            for( int i=1 ; i<n ; ++i ) rs.append("0") ; 
            System.out.println(rs) ; 
        }
    }
}
