import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

public class Main {
    public static void main(String[] args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //begin
        int n, k;
        BigInteger[] arr = new BigInteger[2000];
        String s;
        n = in.nextInt();
        k = in.nextInt();
        arr[1] = BigInteger.valueOf(k-1);
        arr[2] = BigInteger.valueOf((k-1)*k);
        for(int i=3; i<=n; i++)
            arr[i] = (BigInteger.valueOf(k-1)).multiply(arr[i-1].add(arr[i-2]));
        out.print(arr[n]);
        //close reader
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
        return  tokenizer.nextToken();
    }
    public int nextInt(){
        return  Integer.parseInt(next());
    }

}