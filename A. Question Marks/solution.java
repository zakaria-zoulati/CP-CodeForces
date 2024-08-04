import java.util.Scanner;
import java.util.HashSet;
public class A {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int n = sc.nextInt();
            sc.nextLine() ; 
            String in = sc.nextLine() ; 
            int rs =0 ; 
            int a = 0 ;
            int b = 0 ; 
            int c= 0 ; 
            int d= 0 ;
            for(int i=0 ; i<4*n ; i++){
                if( in.charAt(i) == 'A' ){
                    a++ ; 
                }
                else if( in.charAt(i) == 'B' ){
                    b++ ; 
                }else if( in.charAt(i) == 'C' ){
                    c++ ; 
                }else if( in.charAt(i) == 'D' ){
                    d++ ; 
                }else {
                    
                }
            }
            rs  += Math.min( n ,a) ; 
            rs  += Math.min( n ,b) ; 
            rs  += Math.min( n ,c) ; 
            rs  += Math.min( n ,d) ; 
            System.out.println( rs ) ; 
    }
}
}

