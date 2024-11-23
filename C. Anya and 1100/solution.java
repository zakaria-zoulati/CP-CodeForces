import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine() ; 
        while (t-- > 0) {
            String in = sc.nextLine() ; 
            char[] chars = in.toCharArray() ; 
            int n = chars.length ; 
            int q = sc.nextInt() ; 
            int count = 0 ; 
            for( int i=0 ; i+3<n ; ++i ){
                if( chars[i]=='1' && chars[i+1] =='1' && chars[i+2] == '0' && chars[i+3] == '0' ){
                    ++count ;         
                    i += 3  ;
                }
            }
            while( q-- > 0 ){
                int j =  sc.nextInt() ; 
                int v = sc.nextInt() ; 
                j-- ; 
                char up = (char) ( '0' + v ) ; 
                int f = Math.max( j-3 , 0  ) ; 
                int e = Math.min( j+3 , n-1) ; 
                int before = 0 ; 
                int after = 0 ; 
                for( int k=f ; k+3<=e ; ++k ){
                    if( chars[k]=='1' && chars[k+1] =='1' && chars[k+2] == '0' && chars[k+3] == '0' ){
                        ++before ;         
                         k += 3  ;
                    }
                }
                chars[j] = up ; 
                for( int k=f ; k+3<=e ; ++k ){
                    if( chars[k]=='1' && chars[k+1]=='1' && chars[k+2]=='0' && chars[k+3]=='0' ){
                        ++after ; 
                        k += 3 ; 
                    }
                }
                count = count + ( after - before ) ; 
                System.out.println( count>0 ? "YES" : "NO" ) ; 
                sc.nextLine() ;
            }
        }
    }
}
