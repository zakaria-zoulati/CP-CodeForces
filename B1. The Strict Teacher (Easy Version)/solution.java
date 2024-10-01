import java.util.Scanner ; 

public class B1 {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ;
        int t = sc.nextInt() ; 
        all:for(int p=0 ; p<t ; ++p ){
           int n = sc.nextInt() ; 
           int m = sc.nextInt() ; 
           int q = sc.nextInt() ; 
           int rs = 0 ; 
           int t1 = sc.nextInt() ; 
           int t2 = sc.nextInt() ; 
           int a  = sc.nextInt() ; 
           if( t1 > t2 ){
               int temp = t1 ; 
               t1 = t2 ; 
               t2 = temp ; 
           }
           if( a > t1 && a < t2 ){
               int b = t2 - t1 -1 ; 
               rs = b/2 + ( b%2 == 1 ? 1 : 0 ) ; 
           }else if( a < t1 ){
               rs = t1 - 1 ; 
           }else {
               rs = n - t2 ; 
           }
           
           System.out.println(rs) ; 
           
        }
    }
}