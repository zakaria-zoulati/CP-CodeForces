import java.util.*;
import java.util.HashSet ;
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        for(int p=0 ; p<t ; ++p){
            int n = sc.nextInt() ; 
            HashSet<Integer> set = new HashSet<>() ;  
            sc.nextLine() ; 
            for(int i=0 ; i<n ; ++i){
                int count = 0 ;
                String a = sc.nextLine() ;
                for(Character c : a.toCharArray() ){
                    if( c == '1' ) count++ ;
                }
                if( count != 0  ) set.add(count) ; 
            }
            System.out.println( set.size() == 1 ? "SQUARE" : "TRIANGLE" ) ; 
        }
    }
}
