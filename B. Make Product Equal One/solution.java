import java.util.Scanner ; 

public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt(); 
        long rs = 0L ;  
        int n_c = 0 ; 
        boolean z = false ; 
        for( int c=0 ; c<n ; ++c ){
            int a = sc.nextInt() ; 
            if( a == 0 ){
                rs++ ; 
                z = true ; 
            }
            else if( a > 0 ){
                rs += a - 1 ; 
            }else {
                n_c++ ; 
                rs += -1 - a ; 
            }
        }
        if( n_c % 2 == 1 ){
            if( !z ){
                rs += 2 ;   
            }
        }
        System.out.println( rs ) ; 
    }
}