import java.util.Scanner;
 
public class A {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[] arr = new int[6] ; 
        for(int i=0 ; i<6 ; ++i){
            arr[i] = sc.nextInt() ; 
        }

        int rs = 0 ; 
        int sum = 0 ; 
        for(int i=0 ; i<3 ; ++i){
            sum += arr[i] ; 
        }
        rs += sum*sum ; 
        for( int i=0 ; i<6 ; i+=2 ){
            rs -= arr[i]*arr[i] ; 
        }
        System.out.println(rs) ; 
    }
}