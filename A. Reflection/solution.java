import java.util.Scanner;
 
public class A {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int l=sc.nextInt();
        int r=sc.nextInt();
        long x=1;
        while (x<=r) {
            x*=10;
        }
        x--;
        long mid=x/2;
        if(mid<=l){
            System.out.println(l*(x-l));
        }else if(mid>=r){
            System.out.println(r*(x-r));
        }else{
            System.out.println(mid*(x-mid));
        }
    }
}