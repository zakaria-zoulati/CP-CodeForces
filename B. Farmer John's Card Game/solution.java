import java.util.* ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int m = sc.nextInt() ; 
            int total = n*m ; 
            int[] p = new int[n] ; 
            boolean valid = true ; 
            for(int i=0 ; i<n ; ++i){
                int first = sc.nextInt()%n ; 
                for(int j=1 ;j<m ; ++j){
                    if( sc.nextInt()%n != first ){
                        valid = false ; 
                    }
                }
                if( valid ){
                    p[first] = i+1 ; 
                }
            }
            if( valid ){
                for( int i=0 ; i<n ; ++i ){
                    System.out.print( p[i] + " " ) ; 
                }
                System.out.println(" ") ; 
            }else {
                System.out.println(-1) ; 
            }
            
        }
    }
    
}