import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int num, n, ones, k;
        while(in.hasNext()){
            n = in.nextInt();
            ones = 1;
            num = 1;
            k = 1;
            while(k!=0){
                if(num<n){
                    num *= 10;
                    num += 1;
                    ones++;
                }
                k = num % n;
                num = k;
            }
            System.out.println(ones);
        }
    }

}
