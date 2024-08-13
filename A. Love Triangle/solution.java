import java.util.*;
public class Solution {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = sc.nextInt();
    }
    for (int i = 0; i < n; ++i) {
        int a = arr[i] -1 ; 
        if( a == i  ) continue ; 
        int b = arr[a] -1 ; 
        if( b == a ) continue ; 
        if (arr[b] == i+1) {
            System.out.println("YES");
            return;
        }
    }
    System.out.println("NO");
}
}
