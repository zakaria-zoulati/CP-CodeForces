import java.util.Scanner ; 

public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            for( int i=0 ; i<n ; ++i ) arr[i] = sc.nextInt() ; 
            Arrays.sort(arr) ; 
            int score = (n-1)*( arr[n-1] - arr[0] )  ; 
            System.out.println(score) ; 
        }
    }
}
