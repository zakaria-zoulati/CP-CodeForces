import java.util.*; 
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int a = sc.nextInt() ; // The number of boys 
            int b = sc.nextInt() ; // The number of girls 
            int k = sc.nextInt() ; // The number of couples ready to dance together
            
            
            // The adjancy List for Both 
            ArrayList<Integer>[] listA = new ArrayList[a] ; 
            for( int i=0 ; i<a ; ++i ){
                listA[i] = new ArrayList<>() ; 
            }
            ArrayList<Integer>[] listB = new ArrayList[b] ; 
            for( int i=0 ; i<b ; ++i ){
                listB[i] = new ArrayList<>() ; 
            }
            
            int[][] pairs = new int[k][2] ; 
            for( int i=0 ; i<k ; ++i ){
                pairs[i][0] = sc.nextInt() ; 
            }
            for( int i=0 ; i<k ; ++i ){
                pairs[i][1] = sc.nextInt() ; 
            }
            
            
            for( int i=0 ; i<k ; ++i ){
                int x = pairs[i][0] ; 
                int y = pairs[i][1] ;  
                listA[x-1].add( y-1 ) ;
                listB[y-1].add( x-1 ) ; 
            }
            
            
            long rs = 0 ; 
            for( int i=0 ; i<a ; ++i ){
                if( listA[i].size() == 0 ) continue ; 
                for( int j : listA[i] ){
                    rs += k - ( listA[i].size() + listB[j].size() -1 ) ; 
                }
            }
            rs >>= 1 ; 
            System.out.println(rs) ; 
        }
    }
}
