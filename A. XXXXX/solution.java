import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        for( int c=0 ; c<t ; ++c ){
            int n = sc.nextInt() ; 
            int x = sc.nextInt() ; 
            int curr = -1 ; 
            int sum = 0 ; 
            int rs = 0 ; 
            for( int i=0 ; i<n ; ++i ){
                int item = sc.nextInt() ; 
                sum += item ; 
                if( sum % x != 0 ){
                    rs = i+1 ; 
                    if( curr == -1 ){
                        curr = i+1 ; 
                    }
                }
                else if( curr != -1 ){
                    rs = Math.max( rs , i+1 - curr )  ;
                }
            }
            
            if( curr == -1 ){
                System.out.println( -1 ) ; 
            }else {
                System.out.println( rs ) ; 
            }
            
        }
    }
}
