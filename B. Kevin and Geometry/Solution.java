import java.util.* ; 
public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        // To simplify Just check for the pattern * X X * _or_ XX** _or_ **XX 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            for( int i=0 ; i<n ; ++i ){
                arr[i] = sc.nextInt() ; 
            }
            Arrays.sort( arr ) ; 
            // Do a simple precompute 
            int[] right = new int[n] ; 
            int curr = arr[n-1] - arr[n-2] ;
            right[n-2] = n-2 ; 
            for( int i=n-3 ; i>=0 ; --i ){
                if( arr[i+1] - arr[i] < curr ){
                    curr = arr[i+1] - arr[i] ; 
                    right[i] = i ; 
                }else {
                    right[i] = right[i+1] ; 
                }
            }
            
            boolean flag = true ; 
            for( int i=0 ; i+1<n ; ++i ){
                if( arr[i] == arr[i+1] ){
                    // The First Pattern is * * X X
                    if( i>=2 ){
                        System.out.println( arr[i-1] + " " + arr[i-2] + " " + arr[i] + " " + arr[i+1]  ) ;
                        flag = false ; 
                        break ; 
                    }
                    // The second Pattern is X X * *
                    if( i+3<n ){
                        int idx = right[i+2] ; 
                        int prev = arr[i] + arr[i+1] + arr[idx] ; 
                        if( prev > arr[idx+1] ){
                            System.out.println( arr[i] + " " + arr[i+1] + " " + arr[idx] +" " + arr[idx+1] ) ; 
                            flag = false ; 
                            break ; 
                        }
                    }
                    // The Thirs Patttern is * X X *  
                    if( i>0 && i+2<n ){
                        int prev = arr[i-1] + arr[i] + arr[i+1] ; 
                        if( prev > arr[i+2] ){
                            System.out.println( arr[i-1] + " " + arr[i] + " " + arr[i+1] + " " + arr[i+2] ) ; 
                            flag = false ; 
                            break ; 
                        }
                    }
                    
                }
            }
            
            if( flag ){
                System.out.println(-1) ;    
            }
            
        }
    }   
}