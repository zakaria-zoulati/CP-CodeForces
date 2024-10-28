import java.util.Scanner ; 

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        for(int p=0 ; p<t ; ++p){
            int n = sc.nextInt() ; 
            int x = sc.nextInt() ;
            int[] arr = new int[n] ; 
            for(int i=0 ; i<n ; ++i ){
                int a = sc.nextInt() ; 
                if( a < n ){
                    arr[ a ]++ ; 
                }
            }
            int rs = n ; 
            for( int i=0 ; i<n ; ++i ){
                if( arr[i] == 0 ){
                    rs = i ; 
                    break ; 
                }
                if( arr[i] > 1 && i+x<n ){
                    arr[i+x] += arr[i] - 1 ; 
                }
            }
            System.out.println(rs) ; 
        }
    }
}

              
