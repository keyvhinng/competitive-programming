import java.util.Scanner;
class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        long ans, a, b;
        while(in.hasNext()){
            a = in.nextInt();
            b = in.nextInt();
            ans = a ^ b;
            System.out.println(ans);
        }
    }

}
