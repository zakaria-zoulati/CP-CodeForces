import java.util.* ; 

public class Soluti {
    public static void dfs( int n , int digits , long curr , int di , int diff , long[] rs ){
        if( di == digits ){
            if( curr >= n && diff == 0 ){
                rs[0] = Math.min( rs[0] , curr ) ; 
            }
            return ; 
        }
        dfs( n , digits , curr*10 + 4 , di+1 , diff + 1 , rs ) ; 
        dfs( n , digits , curr*10 + 7 , di+1 , diff - 1 , rs ) ; 
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ;
        int clone = n ; 
        int digits = 0 ; 
        while( clone > 0 ){
            clone /= 10 ; 
            digits++ ; 
        }
        if( digits % 2 == 1 ){
            long rs = 0L; 
            int half = (digits / 2) + 1 ; 
            for( int i=0; i<half ; ++i ){
                rs = rs*10 + 4 ; 
            }
            for( int i=half ; i<=digits ; ++i ){
                rs = rs*10 + 7 ; 
            }
            System.out.println( rs ) ; 
        }else {
            long[] res = new long[]{ Long.MAX_VALUE } ; 
            dfs( n , digits , 0L , 0 , 0 ,  res ) ; 
            if( res[0] != Long.MAX_VALUE ){
                System.out.println( res[0] ) ;
                return ; 
            } 
            long rs = 0L; 
            int half = ((digits + 2) / 2)  ; 
            for( int i=0; i<half ; ++i ){
                rs = rs*10 + 4 ; 
            }
            for( int i=half ; i<digits+2 ; ++i ){
                rs = rs*10 + 7 ; 
            }
            System.out.println( rs ) ; 
        }
    }
}