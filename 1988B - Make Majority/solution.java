import java.util.Scanner ; 
public class B {
    public static void  main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        ok:for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            sc.nextLine() ; 
            String in = sc.nextLine() ; 
            int ones = 0 ; 
            int zeros = 0 ;
            for(int i=0 ; i<n ; i++ ){
                if( in.charAt(i) == '0' ){
                    zeros++ ;
                    while(i+1<n && in.charAt(i+1) == '0' ){
                        i++ ; 
                    }
                }else {
                    ones++ ; 
                }
            }
            
            if( ones > zeros  ){
                System.out.println("YES") ;
            }else {
                System.out.println("NO") ;
            }
            
        }
    }
}