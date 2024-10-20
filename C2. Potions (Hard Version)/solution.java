import java.util.Scanner;
import java.util.PriorityQueue ; 

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        int rs = 0 ; 
        long health = 0L ; 
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a,b) -> a - b 
        ); 
        for(int i=0 ; i<n ; ++i ){
            int a = sc.nextInt() ; 
            if( a < 0 ){
                pq.add(a) ; 
            }
            health += a ; 
            rs++ ; 
            while( health < 0L ){
                health -= pq.poll() ; 
                --rs ; 
            }
        }
        System.out.println(rs) ; 
    }
}
