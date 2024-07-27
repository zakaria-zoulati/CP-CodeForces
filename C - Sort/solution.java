import java.util.*;

public class C_Sort {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int p = 0; p < t; p++) {
            int n = sc.nextInt();
            int q = sc.nextInt();
            String s1 = sc.next();
            String s2 = sc.next();

            int[][] freq1 = new int[n + 1][26];
            int[][] freq2 = new int[n + 1][26];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 26; j++) {
                    freq1[i + 1][j] = freq1[i][j];
                    freq2[i + 1][j] = freq2[i][j];
                }
                freq1[i + 1][s1.charAt(i) - 'a']++;
                freq2[i + 1][s2.charAt(i) - 'a']++;
            }

            for (int i = 0; i < q; i++) {
                int l = sc.nextInt();
                int r = sc.nextInt();
                l--;

                int ans = 0;
                for (int j = 0; j < 26; j++) {
                    int count1 = freq1[r][j] - freq1[l][j];
                    int count2 = freq2[r][j] - freq2[l][j];
                    ans += Math.abs(count1 - count2);
                }
                System.out.println(ans / 2);
            }
        }
    }
}
