import java.util.Scanner ;

public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            if( n == 1 || n == 3 ){
                System.out.println(-1) ;  
            }else if( n%2 == 0 ){
                StringBuilder rs = new StringBuilder() ; 
                for( int i=0 ; i<n-2 ; ++i ){
                    rs.append('3') ; 
                }
                rs.append("66") ; 
                System.out.println(rs) ; 
            }else {
                StringBuilder rs = new StringBuilder() ;
                for( int i=0 ; i<n-5 ; ++i ){
                    rs.append("3") ; 
                }
                rs.append("36366") ; 
                System.out.println(rs) ; 
            }
            
        }
    }
}












