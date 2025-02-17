import java.util.* ; 
// A string of at most 3 element That is divisible by 8 
public class C {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        String s = sc.nextLine() ; 
        int n = s.length() ; 
        // The case of a simple string of length 1 
        for( int i=0 ; i<n ; ++i ){
            if( s.charAt(i) == '8' ){
                System.out.println("YES") ; 
                System.out.println("8") ; 
                return ; 
            }else if( s.charAt(i) == '0' ){
                System.out.println("YES") ; 
                System.out.println("0") ; 
                return ; 
            }
        }
        int[] left = new int[8] ; 
        int[][] right = new int[n][8] ;
        for( int j=1 ; j<n ; ++j ){
            for( int i=0 ; i<8 ; ++i ){
                right[j][i] = -1 ;  
            }
        }
        for( int i=1 ; i<8 ; ++i ){
            left[i] = -1 ; 
        }
            
        
        for( int i=n-1 ; i>= 1 ; --i ){
            for( int j=0 ; j<8  ; ++j ){
                right[i-1][j] = right[i][j] ; 
            }
            int curr = ( (int) s.charAt(i) - '0' ) % 8 ; 
            right[i-1][curr] = i ; 
        }
        
        // The i is either the rightMost ( 2 length Case ) or the middle ( In the case of 3 digits )
        for( int k=0 ; k<n ; ++k ){
            char curr = s.charAt(k) ;
            int mod = ( (int) s.charAt(k) - '0' ) % 8 ; 
            
            // The case of two 
            for( int i=0 ; i<8 ; ++i ){
                if( left[i] == -1 ) continue ; 
                int x = mod + 2*i ; 
                if( x % 8 == 0 ){
                    StringBuilder rs = new StringBuilder() ; 
                    rs.append( s.charAt( left[i] )) ; 
                    rs.append( curr ) ; 
                    System.out.println( "YES" ) ; 
                    System.out.println( rs ) ; 
                    return  ; 
                }
            }
            
            // The Third Length Case 
            for( int i=1 ; i<8 ; ++i ){
                if( left[i] == -1 ) continue ; 
                for( int j=1 ; j<8 ; ++j ){
                    if( right[k][j] == -1 ) continue ; 
                    int x = j + mod*2 + 4*i ; 
                    if( x % 8 == 0 ){
                        StringBuilder rs = new StringBuilder() ; 
                        rs.append( s.charAt( left[i] )) ; 
                        rs.append( curr ) ; 
                        rs.append( s.charAt( right[k][j] ) ) ; 
                        System.out.println( "YES" ) ; 
                        System.out.println( rs ) ; 
                        return  ; 
                    }
                }
            }
            left[mod] = k ; 
        }
        System.out.println("NO") ; 
    }   
}