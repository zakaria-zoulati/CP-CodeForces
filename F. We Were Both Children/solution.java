import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        while( t-- > 0  ){
            int n = sc.nextInt() ; 
            int[] arr = new int[n+1] ; 
            int[] map = new int[n+1] ; 
            for(int i=0 ; i<n ; ++i){
                int a = sc.nextInt() ; 
                if( a > n ) continue ; 
                arr[ a ]++ ; 
            }
            int rs = 0 ; 
            for(int i=1 ; i<=n ; ++i){
                if(arr[i]==0 ) continue ; 
                for(int j=1; j*i<=n ; ++j){
                    map[i*j] += arr[i] ; 
                }
            }
            
            for( int item : map ){
                rs = Math.max( rs , item ) ; 
            }
            System.out.println(rs) ; 
        }
    }
}
