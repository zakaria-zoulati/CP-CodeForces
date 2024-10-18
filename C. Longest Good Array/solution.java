import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        for (int p = 0; p < q; ++p ) {
           int l = sc.nextInt() ; 
           int r = sc.nextInt() ; 
           int rs = 1 ; 
           int i=1 ; 
           while( l + i <= r ){
               rs++ ; 
               l += i ; 
               ++i ; 
           }
           System.out.println(rs) ; 
        }
    }
}
