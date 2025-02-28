    import java.util.*;

    public class Main {
        static int[][] winningPatterns = {
            {0,1,2} , {3,4,5} , {6,7,8} , 
            {0,3,6} , {1,4,7} , {2,5,8} , 
            {0,4,8} , {2,4,6}
        } ;

        public static boolean win( char[][] grid , char c ){
            for( int[] pattern : winningPatterns ){
                int count = 0 ; 
                for( int i : pattern ){
                    if( grid[ i/3 ][ i%3 ] == c ) count++ ; 
                }
                if( count == 3 ) return true ; 
            }
            return false ; 
        } 
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            // int t = sc.nextInt(); 
            int t = 1 ; 
            while (t-- > 0) {
                char[][] grid = new char[3][3] ; 
                for( int i=0 ; i<3 ; ++i ){
                    grid[i] = sc.nextLine().toCharArray() ; 
                }

                int crosses = 0 ; 
                int os = 0 ; 
                for( char[] r : grid ){
                    for( char c : r ){
                        if( c == 'X' ){
                            crosses++ ; 
                        }else if( c == '0' ) {
                            os++ ; 
                        }
                    }
                }
                
                if( os > crosses || Math.abs( crosses - os ) > 1 ){
                    System.out.println( "illegal" ) ; 
                    return  ; 
                }
                
                boolean winner_x = win( grid , 'X' ) ; 
                boolean winner_0 = win( grid , '0' ) ; 

                if( winner_x && winner_0 ){
                    System.out.println( "illegal" ) ;  
                }else if( winner_x ){
                    if( crosses == os ){
                        System.out.println( "illegal" ) ; 
                    }else {
                        System.out.println( "the first player won" ) ; 
                    }
                }else if( winner_0 ){
                    if( crosses != os ){
                        System.out.println( "illegal" ) ; 
                    }else {
                        System.out.println( "the second player won" ) ; 
                    }
                }else if( crosses + os == 9 ) {
                    System.out.println( "draw" ) ; 
                }else if( os == crosses ){
                    System.out.println( "first" ) ; 
                }else {
                    System.out.println( "second" ) ; 
                }

            }
        }
    }
