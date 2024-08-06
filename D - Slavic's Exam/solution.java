import java.util.Scanner  ;
import java.util.Arrays ;
public class Class1 {
    //    public static int  conv( boolean a ){
//        if(a) return 1 ;
//        return 0 ;
//    }
    public static void main( String[] args){
        Scanner sc = new Scanner(System.in) ;
        int t = sc.nextInt() ;
        sc.nextLine() ;
        for(int p=0 ; p<t ; p++){
            String s = sc.nextLine() ;
            String tar= sc.nextLine() ;
            int n = s.length() ;
            int m = tar.length() ;
            StringBuilder rs = new StringBuilder() ;
            int current = 0 ;
            for(int i=0 ; i<n ; i++){
                if( s.charAt(i) != '?' ){
                    if( current < m && tar.charAt(current) == s.charAt(i) ){
                        current++ ;
                    }
                    rs.append( s.charAt(i) ) ;
                }else {
                    if( current < m ){
                        rs.append( tar.charAt(current) ) ;
                        current++ ;

                    }
                    else {
                        rs.append("a")  ;
                    }
                }
            }
            if( current == m  ){
                System.out.println("YES") ;
                System.out.println(rs) ;
            }else{
                System.out.println("NO") ;
            }

        }
    }
}
