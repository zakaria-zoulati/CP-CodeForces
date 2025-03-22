import java.util.* ; 

public class Solution {
    public static void main( String[]  args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int q = sc.nextInt() ; 
            sc.nextLine() ; 
            String a = sc.nextLine() ;
            String b = sc.nextLine() ; 
            int[][] f_a = new int[n+1][26] ;
            int[][] f_b = new int[n+1][26] ;
            for( int i=0 ; i<n ; ++i ){
                for( int j=0 ; j<26 ; ++j ){
                    f_a[i+1][j] = f_a[i][j] ; 
                    f_b[i+1][j] = f_b[i][j] ; 
                }
                f_a[ i+1 ][ a.charAt(i) - 'a' ]++  ; 
                f_b[ i+1 ][ b.charAt(i) - 'a' ]++ ; 
            }
            while( q-- > 0 ){
                int l = sc.nextInt() ; 
                int r = sc.nextInt() ; 
                int count = 0 ; 
                for( int i=0 ; i<26 ; ++i ){
                    count += Math.abs( ( f_a[r][i] - f_a[l-1][i] ) - ( f_b[r][i] - f_b[l-1][i] ) ) ; 
                }
                count >>= 1 ;
                System.out.println( count ) ; 
            }
        }
    }
}