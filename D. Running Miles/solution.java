import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = sc.nextInt();
            }
            int[] left  = new int[n] ;
            left[0] = arr[0] ; 
            int[] right = new int[n] ; 
            right[n-1] = arr[n-1] - (n-1) ; 
            // fill the left array
            for( int i=1 ; i<n-2 ; ++i ){
                left[i] = Math.max( arr[i] + i , left[i-1] ) ; 
            }
            // fill the right array 
            for( int i=n-2 ; i>1 ; --i ){
                right[i] = Math.max( arr[i] - i , right[i+1] ) ; 
            }
            
            long rs = 0L ; 
            for( int i=1 ; i<n-1 ; ++i ){
                rs = Math.max( rs , (long) arr[i] + right[i+1] + left[i-1] ) ;  
            }

            System.out.println(rs);
        }
    }
}
