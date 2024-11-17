import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int k = sc.nextInt() ; 
            int n = 0 ; 
            int m = 0 ; 
            boolean[] rs = new boolean[k+1] ; 
            for( int i=0 ; i<k ; ++i ){
                int e = sc.nextInt() ; 
                if( (k-2)%e == 0 && rs[ (k-2)/e ] ){
                    n = e ; 
                    m = (k-2)/e ; 
                }
                rs[e] = true ; 
            }
            System.out.println( n + " " + m ) ; 
        }
    }
}
