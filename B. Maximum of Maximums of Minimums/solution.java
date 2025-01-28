import java.util.Scanner ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ;
        int k = sc.nextInt() ; 
        if( k == 1  ){
            long min = Long.MAX_VALUE ; 
            while( n-- > 0 ){
                min = Math.min( min , sc.nextLong()) ; 
            }
            System.out.println(min) ; 
        }
        else if( k == 2 ){
            long rs = sc.nextLong() ; 
            n-- ; 
            while( n-- > 1 ){
                sc.nextLong() ; 
            }
            rs = Math.max( rs , sc.nextLong() ) ; 
            System.out.println( rs ) ; 
        }
        else{
            long max = Long.MIN_VALUE ; 
            while( n-- > 0 ){
                max = Math.max( max , sc.nextLong()) ; 
            }
            System.out.println(max) ;
        }
        
    }
}