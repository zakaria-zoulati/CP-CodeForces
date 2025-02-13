import java.util.* ; 
public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int m = sc.nextInt() ;
        int rs = Integer.MAX_VALUE ; 
        boolean[] isSeen = new boolean[m] ; 
        Queue<int[]> q = new LinkedList<>() ; 
        q.add( new int[]{n,0} ) ;
        while( !q.isEmpty() ){
           int[] curr =  q.poll() ; 
           int node = curr[0] ; 
           if( node <= 0 ) continue ;
           int dist = curr[1] ; 
           if( node > m ){
               rs = Math.min( rs , dist + node - m ) ; 
           }else if( node == m ){
               rs = Math.min( rs , dist ) ; 
           }else if( !isSeen[node] ){
               isSeen[node] = true ; 
               q.add( new int[]{node-1 , dist+1} ) ; 
               q.add( new int[]{node << 1 , dist+1} ) ;
           }
        }
        System.out.println( rs ) ; 
    }
}