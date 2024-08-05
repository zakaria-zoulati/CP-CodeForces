import java.util.Scanner;
import java.util.Stack ; 
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int n = sc.nextInt() ; 
            sc.nextLine() ;
            String in = sc.nextLine() ; 
            int cost = 0  ; 
            Stack<Integer> left = new Stack<>() ;
            for(int i=0 ;i<n ;i++){
                if( in.charAt(i) == '_' ){
                    if( left.size() >0 ){
                        cost += i - left.pop() ;
                    }else{
                        left.add(i) ; 
                    }
                }else if( in.charAt(i) == '(' ){
                    left.add(i) ; 
                }else {
                    cost += i - left.pop() ;
                }
            }
            System.out.println(cost) ; 
        }
        
}
}