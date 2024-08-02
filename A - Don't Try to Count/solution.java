import java.util.Scanner ; 
public class A {
    public static void  main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        loop:for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            int m = sc.nextInt() ; 
            sc.nextLine() ;
            String x = sc.nextLine().trim() ; 
            String s = sc.nextLine().trim() ;
            StringBuilder rs = new StringBuilder() ; 
            rs.append(x) ;
            boolean flag  = false ; 
            for(int i=0 ; rs.length() <= 50 ; i++){
                if( rs.toString().contains(s) ){
                    System.out.println(i); 
                    continue loop; 
                }
                rs.append(rs) ; 
            }
            System.out.println(-1) ; 
        }
}
}