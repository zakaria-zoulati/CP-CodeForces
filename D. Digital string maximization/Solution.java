import java.util.* ; 
public class Solution {
    public static void swap( char[] chars , int i , int j ){
        char tem = chars[i] ; 
        chars[i] = chars[j] ; 
        chars[j] = tem ; 
    }
    public static void operate( char[] chars , int i ){
        if( i == 0 || chars[i] == '0' ){
            return ; 
        }
        if( chars[i-1] + 1 < chars[i] ){
            chars[i]-- ; 
            swap( chars , i , i-1 ) ; 
            operate( chars , i-1 ) ; 
        }
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ;
        int t = sc.nextInt() ; 
        sc.nextLine() ; 
        while( t-- > 0 ){
            String s = sc.nextLine() ; 
            int n = s.length() ; 
            char[] chars = s.toCharArray() ;
            for( int i=1 ; i<n ; ++i ){
                if( chars[i] == '0' ) continue ; 
                else if( chars[i] > chars[i-1] + 1 ){
                    operate( chars , i ) ; 
                }
            }
            System.out.println( new String( chars ) ) ;
        }
    }
}