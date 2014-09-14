import java.util.Scanner;
class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n, s, t, num, den;
        while(in.hasNext()){
            n = in.nextInt();
            s = 1;
            t = 1;
            while(t<n){
                t += (++s);
            }
            if(s%2==1){
                num = (t-n) + 1;
                den = s - (t-n);
            }
            else{
                num = s - (t-n);
                den = (t-n) +1;
            }
            System.out.printf("TERM %d IS %d/%d\n",n,num,den);
        }
    }
}
