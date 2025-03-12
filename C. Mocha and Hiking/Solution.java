import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            for( int i=0 ; i<n ; ++i ){
                arr[i] = sc.nextInt() ; 
            }
            if( arr[0] == 1 ){
                System.out.print( n+1 + " ") ; 
                for( int i=1 ; i<=n ; ++i ){
                    System.out.print( i + " " ) ; 
                }
                System.out.println() ; 
                continue ; 
            }
            int[] curr = new int[n+1];
            curr[n] = -1 ; 
            for( int i=0; i<n ; ++i ){
                if( arr[i] == 0 ){
                    curr[i] = i+1 ; 
                    if( (i+1 < n && arr[i+1] == 1) || ( i+1 == n ) ){
                        curr[i+1] = n+1  ;
                        for( int j=i+2 ; j<=n ; ++j ){
                            curr[j] = j ; 
                        }
                        for( int j=0 ; j<=n ; ++j ){
                            System.out.print( curr[j] + " " ) ; 
                        }
                        System.out.println() ; 
                        break ; 
                    }
                }else {
                    curr[i] = i+1  ; 
                }
            }
            if( curr[n] == -1 ){
                System.out.println(-1) ; 
            }
            
        }
    }
}