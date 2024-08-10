import java.util.Scanner ;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ;
        for(int p=0; p<t ; ++p){
            int x =  sc.nextInt();
            int y =  sc.nextInt();
            int k =  sc.nextInt();
            if( k%2==1){
                System.out.println( x + " "+ y );
                k--  ;
                int up = 1 ;
                while( k>0 ){
                    System.out.println( (x-up)   + " "+ ( y-up )  );
                    System.out.println( (x+up)   + " "+ ( y+up )  );
                    k -= 2;
                    up++ ;
                }
            }else {
                int up = 1 ;
                while(k>0){
                    System.out.println( (x-up)   + " "+ ( y-up )  );
                    System.out.println( (x+up)   + " "+ ( y+up )  );
                    k -= 2;
                    up++ ;
                }
            }
        }

    }
}