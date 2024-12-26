import java.util.Scanner;
import java.util.Arrays ; 

public class C {
    public static int gcd( int a , int b ){
        while( b != 0 ){
            int tem = a%b ; 
            a = b ; 
            b = tem ; 
        }
        return a ; 
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int a = sc.nextInt() ; 
            int b = sc.nextInt() ; 
            a = gcd(a,b) ; 
            int[] arr = new int[n] ; 
            for( int i=0 ; i<n ; ++i ){
                arr[i] = sc.nextInt()%a ;
            }
            Arrays.sort(arr) ; 
            int rs = arr[n-1] - arr[0] ; 
            for( int i=1 ;i<n ; ++i ){
                rs = Math.min( rs , arr[i-1]+ a- arr[i] ) ; 
            }
            System.out.println(rs) ;
        }
    }
}
