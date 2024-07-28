import java.util.Scanner ; 
public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in)  ; 
        int t = sc.nextInt() ; 
        for(int c=0 ; c<t ; c++){
            int q = sc.nextInt() ; 
            int[] arr = new int[q] ; 
            for(int i=0 ; i<q ; i++){
                arr[i] = sc.nextInt() ;
            }
            if(q == 1){
                System.out.println("1") ; 
                continue ; 
            }
            StringBuilder rs = new StringBuilder("1") ; 
            int first = arr[0] ; 
            int latest = arr[0] ; 
            boolean isSorted = true ; 
            for(int i=1 ; i<q ; i++){
                if( isSorted ){
                     if( arr[i] >= latest ){
                        rs.append("1") ; 
                        latest = arr[i] ; 
                    }
                else {
                    if( first >= arr[i] ){
                        rs.append("1") ; 
                        latest = arr[i]  ;
                        isSorted = false ; 
                    }
                    else {
                        rs.append("0") ; 
                    }
                }
                }else {
                    if( arr[i] >= latest && first >= arr[i] ){
                        rs.append("1") ; 
                        latest = arr[i] ; 
                    }else {
                        rs.append("0") ; 
                    }
                }
            }
            
            System.out.println(rs) ; 
        }
    }

}