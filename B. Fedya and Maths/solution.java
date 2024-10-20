import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int n = s.length() ; 
        int rs = 0 ; 
        // caclculate The n % 4
        int curr = 0 ; 
        for( int i= 0 ; i<n ; ++i ){
            curr = (  curr*10 +( s.charAt(i)  - '0') )%4 ; 
        }
        
        for(int i=1 ; i<=4 ; ++i){
            rs = ( rs + (int) Math.pow( i , curr ) ) % 5 ; 
        }
        
        System.out.println(rs)  ; 
        
    }
}
