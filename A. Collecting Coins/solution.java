import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();

        for (int i = 0; i < q; ++i) {
            int a = sc.nextInt() ; 
            int b = sc.nextInt() ; 
            int c = sc.nextInt() ; 
            int n = sc.nextInt() ; 
            int all = a + b + c + n ; 
            if( all % 3 != 0  ){
                System.out.println("NO") ; 
            }else if( a > all/3 || b > all/3 || c > all/3 ) {
                System.out.println("NO") ; 
            }else {
                System.out.println("YES") ;
            }
        }
            
    }
}
