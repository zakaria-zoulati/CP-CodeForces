import java.util.Scanner ; 
import java.util.HashSet ; 
public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        for(int p=0 ; p<t ; ++p){
            int n = sc.nextInt() ; 
            int rs = 0 ; 
            long curr = 0L ; 
            HashSet<Long> set = new HashSet<>() ; 
            for(int i=0 ; i<n ; ++i){
                curr += sc.nextLong() ; 
                if( curr == 0L || set.contains( curr ) ){
                    ++rs ;
                    set = new HashSet<>() ; 
                    curr = 0L ; 
                }else {
                    set.add(curr) ;
                }
            }
            System.out.println(rs) ;
        }
    }
}
