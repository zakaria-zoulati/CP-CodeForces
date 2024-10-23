import java.util.Scanner ; 

public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        boolean flag = true ;
        int a = sc.nextInt() ; 
        while( a % 2 == 0 ){
            a >>= 1 ; 
        }
        while( a % 3 == 0 ){
            a /= 3  ;
        }
        
        for( int i=1 ; i<n ; ++i ){
            int c = sc.nextInt() ; 
            if( flag ){
                while( c % 2 == 0 ){
                    c >>= 1 ; 
                }
                while( c % 3 == 0 ){
                    c /= 3 ;
                }
                if( c != a ){
                    flag = false ; 
                }
            }
        }
        
        System.out.println( flag ? "YES" : "NO" ) ; 
    }
}

