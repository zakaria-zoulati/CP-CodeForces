import java.util.PriorityQueue ;
import java.util.Scanner ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int rs = 0 ; 
            PriorityQueue<Integer> pq = new PriorityQueue<>(
                (a,b) -> b - a 
            );
            int n = sc.nextInt() ; 
            int k = sc.nextInt() ; 
            int[] arr = new int[k+1] ; 
            for( int i=0 ; i<k ; ++i ){
                int b = sc.nextInt() ; 
                int c = sc.nextInt() ; 
                arr[b] += c ; 
            }
            for( int i=1 ; i<=k ; ++i ){
                if( arr[i] != 0 ){
                    pq.add( arr[i] ) ; 
                }
            }
            while( n-- > 0 && !pq.isEmpty() ){
                rs += pq.poll() ; 
            }
            System.out.println(rs) ;   
        }
    }
}