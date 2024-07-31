import java.util.Scanner;
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int n = sc.nextInt() ; 
            int m = sc.nextInt() ; 
            if( m>n ){
                System.out.println("NO") ; 
            }else {
                if( (n-m) % 2 == 0  ){
                    System.out.println("YES") ; 
                }else {
                    System.out.println("NO") ; 
                }
            }
        }
    }
}
