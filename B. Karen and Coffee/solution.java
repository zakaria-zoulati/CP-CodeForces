import java.util.Scanner ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int k = sc.nextInt() ; 
        int q = sc.nextInt() ; 
        int[] diff = new int[200_001] ; 
        for( int i=0 ; i<n ; ++i ){
            int l = sc.nextInt() ; 
            int r = sc.nextInt() ; 
            diff[l]++ ; 
            if( r+1<=200_000 ){
                diff[r+1]-- ; 
            }
        }
        int[] pref = new int[200_001] ; 
        for( int i=1 ; i<200_001 ; ++i ){
            diff[i] += diff[i-1] ; 
            pref[i] += pref[i-1] ; 
            if( diff[i] >= k ){
                pref[i]++ ; 
            }
        }
        
        while( q-- > 0 ){
            int a = sc.nextInt() ; 
            int b = sc.nextInt() ; 
            int rs = pref[b] - pref[a-1] ;
            System.out.println(rs) ; 
        }
        
    }
}