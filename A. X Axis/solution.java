import java.util.Scanner;
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int a = sc.nextInt() ; 
            int b = sc.nextInt() ; 
            int c = sc.nextInt() ;
            int result = (int) 1e9 ; 
            for(int i=1 ; i<=10 ; i++){
                result = Math.min( result , Math.abs(a-i) + Math.abs(b-i)+ Math.abs(c-i) ) ; 
            }
            System.out.println(result) ; 
        }
    }
}