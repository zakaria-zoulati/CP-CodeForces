import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            
            long[] arr = new long[n];
            long cost = 0L ; 
            for (int i = 0; i < n; ++i) {
                arr[i] = sc.nextInt();
                cost += arr[i] ; 
                arr[i] = -arr[i] + ( n-i-1 ); 
            }
            Arrays.sort( arr )  ;
            for( int i=0 ; i<k ; ++i ){
                cost += arr[i] ; 
            }
            cost -= (long) k*(k-1) >> 1 ; 
            
            System.out.println(cost);
        }
    }
}