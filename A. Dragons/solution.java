import java.util.Scanner ; 
import java.util.Arrays ; 

public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int s = sc.nextInt() ; 
        int n = sc.nextInt() ; 
        int[][] x = new int[n][2] ; 
        for( int i=0 ; i<n ; ++i ){
            x[i][0] = sc.nextInt() ; 
            x[i][1] = sc.nextInt() ; 
        }
        Arrays.sort( x , (a,b) -> a[0] - b[0] ) ;
        for( int i=0;i<n ; ++i ){
            if( x[i][0] >= s ){
                System.out.println("NO") ; 
                return ; 
            }
            s += x[i][1] ; 
        }
        System.out.println("YES") ; 
    }
}
