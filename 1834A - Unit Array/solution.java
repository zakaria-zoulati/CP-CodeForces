import java.util.Scanner;
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int n = sc.nextInt() ; 
            int pos = 0 ; 
            int neg = 0 ;
            for(int i=0 ; i<n ;i++){
                if( sc.nextInt() >0 ) pos++ ; 
                else neg++ ; 
            }
            int rs = 0 ; 
            int inter = neg ; 
            int inter2 = pos ; 
            while( inter2 < inter  ){
                rs++ ;
                inter-- ;
                inter2++ ; 
            }
            if( inter % 2 != 0  ){
                rs++ ; 
            }
            System.out.println( rs ) ; 
        }
    }
}
