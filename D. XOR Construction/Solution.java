import java.util.* ; 

public class Solution {
    static class Trie {
        Trie[] childs ; 
        boolean end ; 
        public Trie() {
            this.childs = new Trie[2] ; 
            this.end = false ; 
        }
        public void insert( int n ){
            Trie root = this ; 
            for( int i=20 ; i>=0 ; --i ){
                int b = ( n >> i ) & 1 ; 
                if( root.childs[b] == null ){
                    root.childs[b] = new Trie() ; 
                }
                root = root.childs[b] ; 
            }
            root.end = true ;
        }
        public boolean check( int num , int n ){
            int curr = 0 ; 
            Trie root = this ;
            for( int i=20 ; i>=0 ; --i ){
                int ibit = ( num >> i ) & 1 ; 
                if( root.childs[1-ibit] != null ){
                    curr = curr + ( (1-ibit ) << i ) ; 
                    root = root.childs[1-ibit] ; 
                }else {
                    curr = curr + ( ibit << i ) ;
                    root = root.childs[ibit] ; 
                }
                if( root.end && ( curr ^ num ) >= n ){
                    return false ;
                }
            }
            return true ; 
        }
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int[] a = new int[n-1] ; 
        for( int i=0 ; i<n-1 ; ++i ){
            a[i] = sc.nextInt() ;
        }
        Trie trie = new Trie() ; 
        int path = 0 ; 
        for( int i=n-2 ; i>=0 ; --i ){
            path ^= a[i] ; 
            trie.insert( path ) ;
        }
        for( int i=0 ; i<n ; ++i ){
            if( trie.check( i , n ) ){
                int[] b = new int[n] ; 
                b[n-1] = i ; 
                for( int j=n-2 ; j>=0 ; --j ){
                    b[j] = b[j+1] ^ a[j] ; 
                }
                for( int j=0 ; j<n ; ++j ){
                    System.out.print( b[j] + " " ) ; 
                }
                break ; 
            }
        }
        
    }
}