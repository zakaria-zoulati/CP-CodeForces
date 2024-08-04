

import java.util.Scanner;
import java.util.Arrays ; 
public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int n = sc.nextInt();
            int[] arr = new int[n] ; 
            int rs = 0 ; 
            for(int i=0 ; i<n ; i++){
                arr[i] = sc.nextInt() ; 
            }
            Arrays.sort(arr) ; 
            if( arr[n-1] % 2 == 1 ){
                for(int i=0 ; i<n-1 ;i++){
                    if( ( arr[i] & 1 ) == 0   ){
                        rs++ ; 
                    }
                }
            }else {
               int max_index = 0  ;
               int pairs = 0 ; 
               int impairs = 0 ; 
               long inter = 0 ; 
               for(int i=0 ; i<n-1; i++){
                   if( arr[i] % 2 ==1 ){
                       max_index = i  ; 
                       inter = arr[i] ;
                       impairs++ ;
                   }else {
                       pairs++ ;
                   }
               }
               if( impairs != 0  ){
                   for(int i = max_index ; i>=0  ; i--){
                        if( arr[i] % 2 == 0 ){
                            inter += arr[i];  
                            pairs-- ; 
                            rs++ ; 
                        }
                   }
                   for(int i= max_index+1 ; i<n-1 && pairs!=0 ;i++ ){
                       if( arr[i] % 2 == 0  &&  arr[i] < inter ){
                           inter += arr[i] ; 
                           pairs-- ; 
                           rs++ ;
                       }
                   }
                   rs += pairs + ( inter > arr[n-1] ? 1 : 2) ; 
                   
               }
            }
            System.out.println(rs) ; 
        }
}
}
