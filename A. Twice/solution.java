import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int rs = 0 ; 
            int[] arr = new int[n+1] ; 
            for( int i=0 ; i<n ; ++i ){
                arr[ sc.nextInt() ]++ ; 
            }
            for( int i=1 ; i<=n ; ++i ){
                rs += arr[i]/2 ; 
            }
            System.out.println(rs) ; 
        }
    }
}
