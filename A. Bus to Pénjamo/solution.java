import java.util.Scanner ; 

public class A {
    
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        for( int c = 0 ;  c < t ; ++c ){
            int n = sc.nextInt() ; 
            int r = sc.nextInt() ; 
            int rs = 0 ; 
            int cache = 0 ; 
            for(int i=0 ; i<n ; ++i){
                int a = sc.nextInt() ; 
                if( a % 2 == 0 ){
                    rs += a ; 
                }else {
                    rs += ( a - 1 ) ; 
                    cache += 1 ; 
                }
            }
            r -= ( rs )/2 ; 
            if( cache <= r ){
                rs += cache ; 
            }
            else if( cache == 2*r ) {
                // Norhing
            }
            else {
                rs += ( r - ( cache % r ) ) ; 
            }
            System.out.println( rs ) ; 
        }
    }
    
}