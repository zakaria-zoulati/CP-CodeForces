import java.util.Scanner ; 

public class A {
    public static int gcd( int a , int b ){
        while( b != 0 ){
            int t = a%b ; 
            a = b ; 
            b = t ;
        }
        return a ; 
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int[] arr = new int[n] ; 
        for( int i=0 ; i<n ; ++i ){
            arr[i] = sc.nextInt() ; 
        }
        int k= 0 ; 
        StringBuilder rs = new StringBuilder() ;
        for( int i=0; i<n-1 ; ++i ){
            if( gcd(arr[i],arr[i+1]) == 1 ){
                rs.append( arr[i] + " ") ; 
            }else {
                 rs.append( arr[i] + " " + 1 + " ") ; 
                 k++ ; 
            }
        }
        rs.append( arr[n-1] ) ;
        System.out.println(k) ; 
        System.out.println(rs) ; 
    }
}
