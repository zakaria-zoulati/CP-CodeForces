import java.util.Scanner;
public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ; 
        String have = sc.nextLine() ; 
        String needed = sc.nextLine() ; 
        int n = have.length() ; 
        int m = needed.length() ; 
        int rs = 0 ; 
        int[] first = new int[26] ; 
        int[] second = new int[26] ; 
        for(int i=0 ; i<n ; ++i){
            first[ have.charAt(i) - 'a' ]++ ;
        }
        for(int i=0 ; i<m ; ++i){
            second[ needed.charAt(i) - 'a' ]++ ;
        }
        for( int i=0 ; i<26 ; ++i ){
            if( second[i] != 0 && first[i] == 0  ){
                System.out.println(-1) ; 
                return ; 
            }
            rs += Math.min( second[i] , first[i] ) ;
        }
        System.out.println(rs) ; 
        
    }
}
