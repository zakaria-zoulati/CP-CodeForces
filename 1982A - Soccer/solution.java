import java.util.Scanner ; 
public class A {
    public static void  main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        for(int c=0 ; c<t ; c++){
            int x1 = sc.nextInt() ; 
            int y1 = sc.nextInt() ; 
            int x2 = sc.nextInt() ; 
            int y2 = sc.nextInt() ; 
            if( y1 > x1 && y2 < x2  ){
                System.out.println("NO") ; 
                continue ; 
            }
            if( y1 < x1 && y2 > x2 ){
                System.out.println("NO") ; 
                continue ;
            }
            System.out.println("YES") ; 
        }
    }
}