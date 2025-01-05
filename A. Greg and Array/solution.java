import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        int m = sc.nextInt() ; 
        int k = sc.nextInt() ; 
        long[] arr = new long[n] ; 
        for( int i=0 ; i<n ; ++i ){
            arr[i] = sc.nextLong() ; 
        }
        int[][] op = new int[m][3] ; 
        for( int i=0 ; i<m ; ++i ){
            for( int j=0 ; j<2 ; ++j ){
                op[i][j] = sc.nextInt() - 1 ; 
            }
            op[i][2] = sc.nextInt() ; 
        }
        int[] ranges = new int[m] ;
        for( int i=0 ; i<k ; ++i ){
            int l = sc.nextInt() - 1 ; 
            int r = sc.nextInt() - 1 ; 
            ranges[l]++ ; 
            if( r+1 < m ){
                ranges[r+1]-- ;
            }
        }
        // The number of times the query will be applied to the array
        for( int i=1 ; i<m ; ++i ){
            ranges[i] += ranges[i-1] ;
        }
        
        long[] diff = new long[n] ; 
        diff[0] = arr[0] ;
        for( int i=1 ; i<n ; ++i ){
            diff[i] = arr[i] - arr[i-1] ;
        }
        
        // Apply The m oprations with the appropriate frequency on the array
        for( int i=0 ; i<m ; ++i ){
            if( ranges[i] == 0 ) continue ;
            long in = (long) ranges[i]*op[i][2] ; 
            int l = op[i][0] ; 
            int r = op[i][1] ;
            diff[l] += in ; 
            if( r+1<n ){
                diff[r+1] -= in ;
            }
        }
        
        // Reconstruct the array 
        for( int i=1 ; i<n ; ++i ){
            diff[i] += diff[i-1] ; 
        }
        
        // Print The final array 
        for( int i=0 ; i<n ; ++i ){
            System.out.print( diff[i] + " " );
        }
        System.out.println("") ; 
    }
}