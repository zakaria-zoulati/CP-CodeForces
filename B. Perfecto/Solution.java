import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); 

        while (t-- > 0) {
            int n = sc.nextInt(); 

            String result = helper(n);
            System.out.println(result);
        }
        sc.close();
    }

    public static String helper(int n) {
        int[] nums = {1, 8, 49, 288, 1681, 9800, 57121, 332928}; 
        List<String> result = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            result.add(String.valueOf(i));
        }

        for (int num : nums) {
            if (num == n) {
                return "-1";
            }
        }

        for (int num : nums) {
            if (num > n) {
                break;
            }
            if (num < n) {
                Collections.swap(result, num - 1, num); 
            }
        }

        return String.join(" ", result); 
    }
}
