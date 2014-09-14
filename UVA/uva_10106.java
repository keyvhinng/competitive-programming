import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        BigInteger a, b;
        String s;
        while(in.hasNext()){
            s = in.nextLine();
            a = new BigInteger(s);
            s = in.nextLine();
            b = new BigInteger(s);
            System.out.println(a.multiply(b));
        }
    }
}
