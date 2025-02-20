import java.util.*; 

public class B {
    public static boolean check_palindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) { 
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length();
         
        if( check_palindrome(s) ){
            System.out.println("First") ; 
            return ;
        }
        
        int[] f = new int[26] ; 
        for( int i=0 ; i<n ; ++i ){
            f[ s.charAt(i) - 'a' ]++ ; 
        }
        
        int one = 0 ; 
        for( int i=0 ; i<26 ; ++i ){
            one += f[i]%2 ; 
        }
        
        if( one <= 1 ){
            System.out.println( "First" ) ; 
        }else if( one % 2 == 1 ){
            System.out.println( "First" ) ; 
        }else {
            System.out.println( "Second" ) ; 
        }
        
        
    }
}
