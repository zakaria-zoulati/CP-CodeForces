import java.util.Scanner;

public class FindStringIndices { 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt(); 
    for (int c = 1; c <= t; c++) {
      int n = sc.nextInt();
      int m = sc.nextInt(); 
      int top = 0; 
      int bottom = 0;
      int column = 0;
      sc.nextLine();
      String[] arr = new String[n];
      for (int i = 0; i < n; i++) {
        arr[i] = sc.nextLine();
      }
      String reference = ".".repeat(m); 
      for (int i = 0; i < n; i++) {
        if (!arr[i].equals(reference)) {
          top = i + 1; 
          column = arr[i].indexOf('#') + 1; 
          break;
        }
      }
      for (int i = n - 1; i >= 0; i--) {
        if (!arr[i].equals(reference)) {
          bottom = i + 1;
          break;
        }
      }
        System.out.println(((top + bottom) / 2) + " " + column);
    }
  }
}
