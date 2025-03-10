import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            sc.nextLine() ; 
            String s1 = sc.nextLine() ; 
            String s2 = sc.nextLine() ; 
            // Find the deired path first 
            StringBuilder rs = new StringBuilder() ; 
            rs.append( s1.charAt(0) ) ; 
            for( int i=1 ; i<n ; ++i ){
                if( s1.charAt(i) == s2.charAt(i-1) ){
                    rs.append( s1.charAt(i) ) ; 
                }else if( s2.charAt(i-1) == '0' ){
                    rs.append( s2.substring(i-1,n-1) ) ; 
                    break ; 
                }else {
                    rs.append( '0' ) ; 
                }
            }
            rs.append( s2.charAt(n-1) ) ; 
            int len1 = 0 ; 
            int len2 = 0 ;
            for( int i=0 ; i<n ; ++i ){
                if( rs.charAt(i) == s1.charAt(i) ) {
                    len1++ ; 
                }else {
                    break ; 
                }
            }
            for( int i=n-1; i>=0 ; --i ){
                if( rs.charAt(i+1) == s2.charAt(i) ){
                    len2++ ; 
                }else {
                    break ;
                }
            }
            int count = 0 ; 
            for( int i=1 ; i<=n ; ++i ){
                if( len1 >= i && len2 >= n-i+1  ){
                    ++count ; 
                }
            }
            System.out.println( rs ) ; 
            System.out.println( count ) ; 
        }
    }
}