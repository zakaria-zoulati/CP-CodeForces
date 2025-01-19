import java.util.* ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int k = sc.nextInt() ; 
            int score = 0 ; 
            int[] f = new int[n+1] ; 
            for( int i=0 ; i<n ; ++i ){
                int curr = sc.nextInt() ; 
                if( curr < k  ){
                    if( k-curr<=n && f[ k - curr ] > 0  ){
                        score++  ;
                        f[k-curr]-- ; 
                    }else {
                        f[curr]++  ;
                    }
                }
            }
            System.out.println(score) ; 
        }
    }
    
}