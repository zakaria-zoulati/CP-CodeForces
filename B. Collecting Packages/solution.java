import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        for (int p = 0; p < q; ++p ) {
           int n = sc.nextInt() ; 
           boolean[][] grid = new boolean[1001][1001] ; 
           for(int i=0 ; i<n ; ++i ){
               int x = sc.nextInt() ; 
               int y = sc.nextInt() ; 
               grid[x][y] = true ; 
           }
           int[] count = new int[1001] ; 
           for( int i=0 ; i<1001 ; ++i ){
               for(int j=0 ; j<1001 ; ++j){
                   if( grid[i][j] ){
                       count[i]++ ; 
                   }
               }
           }
           int collected = 0 ; 
           StringBuilder rs = new StringBuilder() ; 
           int i = 0 ; 
           int j = 0 ; 
           while( i<1001 && j<1001 && collected != n ){
               if( grid[i][j] ){
                  grid[i][j] = false ; 
                  collected++ ; 
                  count[i]-- ; 
               }else {
                   if( count[i] == 0 ){
                       rs.append("R") ; 
                       i++ ; 
                   }else {
                       rs.append("U") ; 
                       j++ ; 
                   }
               }
           }

           if( collected == n ){
               System.out.println("YES") ; 
               System.out.println( rs ) ; 
           }else {
               System.out.println("NO") ; 
           }
        }
    }
}
