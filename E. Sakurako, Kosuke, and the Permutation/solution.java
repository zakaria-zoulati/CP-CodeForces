import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n] ; 
            for( int i=0 ; i<n ; ++i ){
                arr[i] = sc.nextInt() ; 
            }
            boolean[] isSeen = new boolean[n] ; 
            int rs = 0 ; 
            for(int i=0 ; i<n ; ++i){
                if( isSeen[i] || arr[i] == i+1 || i+1 == arr[ (arr[i] -1) ] ) continue ; 
                int c=1 ; 
                int next = arr[i] -1  ; 
                while( arr[next] != i+1 ){
                    isSeen[next] = true ; 
                    next = arr[ next ] - 1 ; 
                    ++c ; 
                }
                arr[i] = i+1 ; 
                arr[next] = next + 1 ; 
                rs += c/2 ; 
            }
            System.out.println(rs) ; 
        }
    }
}
