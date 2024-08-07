import java.util.Scanner;
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int k = sc.nextInt() ; 
            int n = sc.nextInt() ; 
            int current = 1 ;
            int possible = n-k ; 
            int elements = 0 ; 
            for(int i=1 ; i<=n && elements != k ; i++){
                elements++ ;
                System.out.print(i+" ") ; 
                if( current <= possible ){
                    possible -= current ; 
                    i = i+ current ; 
                    current++ ;
                }
            }
            System.out.println() ; 
        }
}
}