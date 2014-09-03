import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.util.*;
import java.util.concurrent.ExecutionException;

public class Main {



    public static void main(String args[]) throws IOException{
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //begin
        int i, n;
        BigInteger fib[] = new BigInteger[4801];
        fib[1] = BigInteger.valueOf(1);
        fib[2] = BigInteger.valueOf(1);
        for(i=3; i<=4800; i++) fib[i] = fib[i-1].add(fib[i-2]);
        while(true){
            try{
                n = in.nextInt();
            }catch(Exception e) {
                break;
            }
            out.println(fib[n].toString());
        }
        //end
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

