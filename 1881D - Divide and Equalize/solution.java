import java.util.Scanner ; 
import java.util.HashMap ; 

public class D {
    
    public static void add_prime(HashMap<Integer,Integer> map , int n  ){
        int current = 2 ; 
        while( current*current <= n ){
            while( n%current == 0  ){
                map.put( current , map.getOrDefault( current , 0 )+1 ) ; 
                n /= current  ; 
            }
            current++ ; 
        }
        if (n > 1) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
    }
    
    public static void  main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while(t>0){
            t-- ; 
            int n  = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            HashMap<Integer,Integer> map = new HashMap<>() ; 
            for(int i=0 ; i<n ; i++){
                arr[i] = sc.nextInt() ; 
                add_prime(map, arr[i]) ; 
            }
            boolean flag = true ; 
            for(Integer i : map.keySet() ){
                if( map.get(i) % n != 0  ){
                    System.out.println("NO") ; 
                    flag = false ; 
                    break ; 
                }
            }
            if(flag){
                System.out.println("YES") ; 
            }
            
        }
    }
    
    
}