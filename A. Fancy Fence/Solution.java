import java.util.* ; 
public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int a = sc.nextInt() ; 
            int x = 180 - a ; 
            if( 360 % x == 0 ){
                System.out.println( "YES" ) ; 
            }else {
                System.out.println( "NO" ) ; 
            }
        }
    }   
}