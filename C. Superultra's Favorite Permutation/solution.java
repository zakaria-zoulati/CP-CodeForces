import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt() ; 
            if( n < 5 ){
                System.out.println(-1) ; 
            }else {
                for( int i=n-(1 - n%2)  ; i>=1 ; i -= 2 ){
                    if( i == 5 ) continue ; 
                    System.out.print(i + " " ) ; 
                }
                System.out.print(5 + " " + 4 + " ") ; 
                for( int i=2 ; i<=n ; i += 2 ){
                    if( i == 4 ) continue ;  
                    System.out.print( i + " " ) ; 
                }
                System.out.println("") ; 
            }
        }
    }
}
