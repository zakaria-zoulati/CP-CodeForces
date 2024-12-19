import java.util.Scanner ; 

public class Main {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int k = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            int curr = n ; 
            int start = 1 ; 
            for( int i=0 ; i<n ; i++ ){
                for( int j=i ; j<n && j<i+k-1 ; ++j ){
                    arr[j] = curr-- ; 
                }
                i += k-1 ; 
                if( i<n ){
                    arr[i] = start++ ; 
                }
            } 
            
            for( int i=0 ; i<n ; ++i ){
                System.out.print( arr[i] + " " ) ; 
            }
            System.out.println() ; 
        }
    }
}