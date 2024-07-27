import java.util.Scanner;
import java.util.Arrays ; 
public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        for(int c=1 ; c<=t ; c++){
            int n = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            for(int i=0 ; i<n ; i++){
                arr[i] = sc.nextInt() ; 
            }
            Arrays.sort(arr) ;
            int current = 0 ; 
            int rs =  0  ; 
            boolean Alice = true ; 
            for(int i = 0; i<n ; i++){
                if(Alice ){
                    if( arr[i] == current ){
                        rs++ ; 
                    }else {
                        break ; 
                    }
                    while( i+1<n && arr[i+1] == current ){
                        i++ ; 
                        Alice = false ; 
                    }
                    current++ ; 
                }else{
                    if( arr[i] != current ){
                        break ; 
                    }
                    while( i+2<n && arr[i+2]==current  ){
                        i++; 
                    }
                }
                Alice = !Alice  ; 
            }
            System.out.println(rs)  ; 
        }
}
}
