import java.util.* ; 

public class Main { 
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        // int t = 1 ; 

        while( t-- > 0 ){
            int n = sc.nextInt() ; 

            int times = n/15 ; 
            
            int rs = ( times )*3 + Math.min(  n - times*15 + 1 , 3 ) ; 

            System.out.println( rs ) ; 
        }
    }   
}

