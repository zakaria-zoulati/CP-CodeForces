import java.util.Scanner ; 
import java.util.Arrays ; 
public class B {
    public static void  main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            long m = sc.nextLong() ; 
            long rs = 0 ; 
            int start = 0 ; 
            long max = 0  ; 
            long[] arr = new long[n] ; 
            for(int i=0 ; i<n ; i++){
                arr[i] = sc.nextLong() ; 
            }
            Arrays.sort(arr) ; 
            for(int i=0 ; i<n ; i++){
                max += arr[i] ; 
                while( max>m || ( start <n && arr[i] - arr[start] >1L)){
                    max -= arr[start] ; 
                    start++ ; 
                }
                rs = Math.max( rs , max ) ; 
            } 
            System.out.println(rs) ; 
        }
    }
}