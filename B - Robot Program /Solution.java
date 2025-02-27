import java.util.* ; 

public class Main { 
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        // int t = 1 ; 

        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int x = sc.nextInt() ; 
            long k = sc.nextLong() ; 

            sc.nextLine() ; 
            String s = sc.nextLine() ; 


            int shortest_cycle = -1 ; 
            int curr = 0 ; 
            for( int i=0 ; i<n ; ++i ){
                if( s.charAt(i) == 'L' ){
                    curr-- ; 
                }else {
                    curr++ ; 
                }
                if( curr == 0 ){
                    shortest_cycle = i+1 ; 
                    break ; 
                }
            }

            long rs = 0L ; 
            // int sum = 0 ; 
            for( int i=0 ; i<n ; ++i ){
                if( s.charAt(i) == 'L' ){
                    x-- ; 
                }else {
                    x++ ; 
                }

                if( x == 0 ){
                    int needed = i+1 ; 
                    if( needed <= k ){
                        rs++ ; 
                        if( shortest_cycle != -1 ){
                            k -= needed ; 
                            rs += k/shortest_cycle ; 
                        }   
                    }
                    break ; 
                }
            }


            System.out.println( rs ) ; 
        }
    }   
}

