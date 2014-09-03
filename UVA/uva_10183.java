import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.util.*;

public class Main {



    public static void main(String args[]) throws IOException{
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        Scanner sc = new Scanner(System.in);
        //begin
        BigInteger ba, bb;
        int i, a, b, s, e;
        BigInteger[] fib = new BigInteger[500];
        fib[1] = BigInteger.ONE;
        fib[2] = BigInteger.valueOf(2);
        for(i=3; i<500; i++) fib[i] = fib[i-1].add(fib[i-2]);
        while(true){
            ba = sc.nextBigInteger();
            bb = sc.nextBigInteger();
            if((ba.compareTo(BigInteger.valueOf(0)) == 0) && (bb.compareTo(BigInteger.valueOf(0))==0)) break;
            s = 1; e = 1;
            while(fib[s].compareTo(ba) < 0) s++;
            while(fib[e].compareTo(bb) < 0) e++;
            if(fib[e].compareTo(bb) > 0) e--;
            out.println(e - s + 1);
        }
        //close
        out.close();

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
        while(tokenizer == null || !tokenizer.hasMoreTokens()){
            try{
                tokenizer = new StringTokenizer(reader.readLine());
            }catch(IOException e){
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.parseInt(next());
    }

}

