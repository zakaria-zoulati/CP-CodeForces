import java.util.* ; 
public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int[] arr = new int[n] ; 
        for( int i=0 ; i<n ; ++i ){
            arr[i] = sc.nextInt() ; 
        }
        Arrays.sort(arr) ; 
        boolean flag = true ; 
        for( int i=2 ; i<n ; ++i ){
            if( arr[i] < arr[i-1] + arr[i-2] ){
                System.out.println( "YES" ) ; 
                flag = false ; 
                break ;
            }
        }
        if( flag ){
            System.out.println( "NO" ); 
        }
    }   
}