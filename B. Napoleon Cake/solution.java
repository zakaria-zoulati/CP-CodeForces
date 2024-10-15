import java.util.Scanner ; 

public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        for( int c=0 ; c<t ; ++c ){
            int n = sc.nextInt() ; 
            int[] all = new int[n] ; 
            for(int i=0 ; i<n ; ++i){
                all[i] = sc.nextInt() ; 
            }
            int curr = 0 ; 
            for(int i=n-1 ; i>=0 ; --i){
                if( curr - 1 < all[i] ){
                    curr = all[i]  ;
                }else {
                    curr-- ; 
                }
                if( curr > 0 ){
                    all[i] = 1 ; 
                }
            }
            for(int i=0 ; i<n ; ++i){
                System.out.print( all[i] + " " ) ; 
            }
            System.out.println() ; 
        }
    }
}