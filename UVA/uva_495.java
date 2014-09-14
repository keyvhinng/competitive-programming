import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Scanner;
import java.math.BigInteger;


class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        //start
        //compute fibonacci array
        int n;
        BigInteger[] fib = new BigInteger[5010];
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        for(int i=2; i<5010; i++){
            fib[i] = fib[i-1].add(fib[i-2]);
        }
        while(in.hasNext()){
            n = in.nextInt();
            out.println("The Fibonacci number for " + n + " is " + fib[n]);
        }
        out.close();;
    }
}
class InputReader{
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next(){
        while(tokenizer==null || !tokenizer.hasMoreTokens()){
            try{
                tokenizer = new StringTokenizer(reader.readLine());
            }catch (IOException e){
                throw  new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public  int nextInt(){
        return Integer.parseInt(next());
    }
}
