import java.util.Scanner;
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; ++p) {
           int n = sc.nextInt() ; 
           int k = sc.nextInt() ; 
           int rs = n*k - (k-1) ;
           System.out.println(rs) ; 
        }
    }
}
