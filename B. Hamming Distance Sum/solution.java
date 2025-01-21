import java.util.* ; 

public class D {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        String b = sc.nextLine() ; 
        String a = sc.nextLine() ; 
        // Take the length of each 
        int n = a.length() ; 
        int m = b.length() ; 
        int[] pref = new int[n+1] ; 
        for(int i=0 ; i<n ; ++i){
            pref[i+1] = pref[i] ; 
            pref[i+1] += a.charAt(i) - '0' ; 
        }
        long rs = 0L ; 
        int inter = n -m +1 ; 
        for( int i=0 ; i<m ; ++i ){
            int ones = pref[ n - m + i + 1 ] - pref[i] ; 
            if( b.charAt(i) == '0' ){
               rs +=ones ; 
            }else{
               rs += inter - ones ; 
            }
        }
        System.out.println(rs) ; 
    }
    
}