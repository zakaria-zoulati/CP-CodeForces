import java.util.*;

public class Solution {
    public static boolean check( long[] arr , long tar , int c ,  long k ){
        long cost = 0 ; 
        for( int i=arr.length - 1 ; i >= c ; --i ){
            if( arr[i] < tar ){
                cost += tar - arr[i] ; 
            }
        }
        return cost <= k ;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        long k = sc.nextLong() ; 
        long[] arr = new long[n] ; 
        for( int i=0 ; i<n ; ++i ){
            arr[i] = sc.nextLong() ; 
        }
        Arrays.sort(arr) ; 
        int center = n/2 ; 
        long l = 1 ; 
        long r = Integer.MAX_VALUE ;
        while( l <= r ){
            long mid = l + ( r - l )/2 ; 
            if( check( arr , mid , center , k )){
                l = mid + 1  ; 
            }else {
                r = mid - 1 ;
            }
        }
        System.out.println(l-1) ; 
    }
}
