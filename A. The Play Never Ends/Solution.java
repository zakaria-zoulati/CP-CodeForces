import java.util.* ; 

public class Solution { 
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        // int t = 1 ; 

        while( t-- > 0 ){
            int k = sc.nextInt() ; 
            if( k % 3 == 1 ){
                System.out.println( "YES" ) ;
            }else {
                System.out.println( "NO" ) ; 
            }
        }
    }   
}

