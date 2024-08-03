import java.util.Scanner ; 
import java.util.Arrays ; 
public class C {
    public static void  main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            long[] arr = new long[n] ; 
            for(int i=0 ; i<n ; i++ ){
                arr[i] = sc.nextLong() ; 
            }
             if( n == 2 ){
                System.out.println( Math.min( arr[0] , arr[1] ) ) ;
                continue; 
            }
            long max = 0 ; 
            for(int i=0 ;i+2<n ; i++){
                long [] inter = { arr[i] , arr[i+1] , arr[i+2]  } ;  
                Arrays.sort( inter ) ; 
                max = Math.max( max , inter[1] ) ; 
            }
            System.out.println(max) ; 
        }
       
    }
}