import java.util.* ; 

public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        
        int n = sc.nextInt() ; 
        int k = sc.nextInt() ; 
        // computes The Bonus Given To The i-Th Engineer
        int[] a = new int[n] ; 
        for( int i=0 ; i<n ; ++i ){
            a[i] = sc.nextInt();
        }
        // Computes The Expected Bonus for one unit of work
        int[] b = new int[n] ; 
        for( int i=0 ; i<n ; ++i ){
            b[i] = sc.nextInt() ; 
        } 
        // Compute the maximum Unit of Work By al The engineers 

        long tasks = 0L ; 
        for( int i=0 ; i<n ; ++i ){
            if( a[i] >= b[i] ){
                tasks += a[i]/b[i] ; 
            }
        }
        int[] c = new int[n] ; 
        if( tasks < k  ){
            for( int i=0 ; i<n ; ++i ){
                System.out.print( c[i] + " " ) ; 
            }
        }else {
            for( int i=0 ; i<n ; ++i ){
                if( k == 0 ) break ; 
                if( a[i] < b[i] ) continue ; 
                int capacity = a[i]/b[i] ; 
                // The number of Units of Work Such That the 
                int l = 0 ; 
                int r = capacity ; 
                while( l < r ){
                    int mid = l + ( r - l )/2 ; 
                    if( tasks - capacity >= k - mid  ){
                        r = mid ; 
                    }else {
                        l = mid + 1 ; 
                    }
                }
                tasks -= capacity ; 
                c[i] = l ; 
                k -= l ; 
            }
            // Printing The array c 
            for( int i=0 ; i<n ; ++i ){
                System.out.print( c[i] + " " ) ; 
            }
        }
    }
}