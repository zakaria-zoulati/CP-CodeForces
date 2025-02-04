import java.util.* ; 

public class D {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int  m = sc.nextInt() ; 
            Map<Integer , Integer> map = new HashMap<>() ; 
            for( int i=0 ; i<n ; ++i ){
                int in = sc.nextInt() ;  
                map.put( in , map.getOrDefault(in,0) + 1 ) ; 
            }
            int[] tar = new int[m] ;
            for( int i=0 ; i<m ; ++i ){
                tar[i] = sc.nextInt() ; 
            }
            String rs = "YES" ; 
            for( int i=0 ; i<m ; ++i ){
                if( !possible( map , tar[i] )){
                    rs = "NO" ; 
                    break ; 
                }
            }
            for( int i : map.values() ){
                if( i > 0 ){
                    rs = "NO" ; 
                    break ; 
                }
            }
            System.out.println(rs) ; 
        }
    }
    public static boolean possible( Map<Integer , Integer> map , int tar ){
        if( tar <= 0 ){
            return false ; 
        }
        int curr = map.getOrDefault(tar,0) ;
        if( curr > 0 ){
            map.put( tar , curr - 1 ) ; 
            return true ;
        }
        if( tar % 2 == 0 ){
            return possible( map , tar/2 ) && possible( map , tar/2 ) ; 
        }else {
            return possible( map , tar/2 ) && possible( map , (tar/2) +1 ) ; 
        }
    }
}