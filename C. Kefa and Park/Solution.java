import java.util.*; 
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        int m = sc.nextInt() ; 
        
        // Check if The vertexes have cats 
        boolean[] isCat = new boolean[n] ; 
        for( int i=0 ; i<n ; ++i ){
            isCat[i] = sc.nextInt() == 1 ; 
        }
        
        ArrayList<Integer>[] vertices = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            vertices[i] = new ArrayList<>();
        }
        
        for( int i=0 ; i<n-1 ; ++i ){
            int x = sc.nextInt() ; 
            int y = sc.nextInt() ; 
            vertices[x-1].add( y-1 ) ; 
            vertices[y-1].add( x-1 ) ; 
        }
        
        int rs = 0 ; 
        
        // Do The BFS 
        boolean[] isSeen = new boolean[n] ; 
        Queue< int[] > q = new LinkedList<>() ; 
        q.add( new int[]{ 0 , isCat[0]?1:0 }) ; 
        while( !q.isEmpty() ){
            int[] curr = q.poll() ; 
            isSeen[ curr[0] ] = true ; 
            boolean isLeaf = true ; 
            for( int i : vertices[ curr[0] ] ){
                if( !isSeen[i] ){
                    isLeaf = false; 
                    if( isCat[i] ){
                         if( curr[1] < m ){
                            q.add( new int[]{ i , curr[1] + 1 } ) ; 
                         }
                    }else {
                        q.add( new int[]{ i , 0 } ) ; 
                    }
                }
            }
            if( isLeaf ){
                rs++  ;
            }
        }
        
        System.out.println( rs ) ; 
    }
}
