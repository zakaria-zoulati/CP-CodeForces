import java.util.* ; 

public class G {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        long n = sc.nextLong() ; 
        
        long l = 1 ; 
        long r = Long.MAX_VALUE ; 
        
        while( l < r ){
            long mid = l + ( r - l )/2 ;
            long odds = ( mid / 2 ) + mid%2 - 1; 
            long four_k = mid >= 8 ? ( (mid /4) -1 ) : 0 ; 
            
            long total = odds + four_k ; 
            
            if( total >= n ){
                r = mid   ; 
            }else {
                l = mid + 1 ; 
            }
        }
        System.out.println( l ) ; 
        
    }
}