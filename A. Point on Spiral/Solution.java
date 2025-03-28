import java.util.* ; 
public class Solution {
    public static void main( String[]  args ){
        Scanner sc = new Scanner( System.in ) ; 
        // int t = sc.nextInt() ; 
        int t = 1 ; 
        while( t-- > 0 ){
            int x = sc.nextInt() ; 
            int y = sc.nextInt() ; 
            int round = 1 ; 
            int curr_x = 0 ; 
            int curr_y = 0 ; 
            long dist = 0 ; 
            while( true ){
                // Go right
                if( curr_y == y && curr_x <= x &&  curr_x + round >= x ){
                    break ; 
                }else {
                    curr_x  += round ; 
                    dist++;  
                }
                // Go Up 
                if( curr_x == x && curr_y <= y && curr_y + round >= y ){
                    break; 
                }else {
                    curr_y += round ; 
                    dist++ ; 
                }
                round++ ; 
                // Go Left 
                if( curr_y == y && curr_x >= x && curr_x - round <= x  ){
                    break ; 
                }else {
                    dist++ ; 
                    curr_x -= round; 
                }
                // Go Down 
                if( curr_x == x && curr_y >= y && curr_y - round <= y ){
                    break ; 
                }else {
                    curr_y -= round; 
                    dist++ ; 
                }
                round++ ; 
            }
           System.out.println( dist ) ; 
        }
    }
}