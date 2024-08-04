import java.util.Scanner ; ; 
public class A {
    public static void  main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            int all = 0 ; 
            int q = n ; 
            while(q>0){
                q-- ; 
                all ^= sc.nextInt() ; 
            }
            if( all == 0  ){
                System.out.println( 0 ) ; 
            }else if( n % 2 == 0 ){
                System.out.println(-1) ; 
            }else {
                System.out.println( all ^ 0  ) ; 
            }
             
        }
    }
}