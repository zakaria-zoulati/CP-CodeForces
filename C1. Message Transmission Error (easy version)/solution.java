import java.util.Scanner  ;
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String in = sc.nextLine() ; 
        int n = in.length() ; 
        for(int i=1 ; i<n ; ++i){;
            if( in.charAt(i) != in.charAt(0)) continue ;
            if( n-i-1 < i ) continue  ;
            if(  in.substring( 0 , n-i ).equals( in.substring(i ,n ) ) ){
                System.out.println("YES") ; 
                System.out.println( in.substring( 0, n-i ) ) ; 
                return ; 
            }
        }
        System.out.println("NO") ;
    }
}
