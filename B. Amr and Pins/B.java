import java.util.* ; 

public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int r = sc.nextInt() ; 
        long x = sc.nextLong() ; 
        long y = sc.nextLong() ; 
        long x1 = sc.nextLong() ; 
        long y1 = sc.nextLong() ; 
        
        long d1 = x - x1 ; 
        long d2 = y - y1 ;
        
        int distance = (int) Math.ceil( Math.sqrt( d1*d1 + d2*d2 ) ) ; 
            
        r  <<= 1 ; 
        
        int rs = distance / r + ( distance % r != 0 ? 1 : 0 ) ; 
        
        
        System.out.println( rs ) ; 
    }
}