import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.math.*;

public class Main {
    public static void main(String[] args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int n;

        //make Eratosthenes' Sieve
        boolean[] sieve = new boolean[1000010];
        for(int i=1; i<1000010; i++){
            sieve[i] = true;
        }
        for(int i=2; i*i<1000010; i++){
            if(sieve[i]){
                for(int j=i; i*j<1000010; j++){
                    sieve[i*j] = false;
                }
            }
        }
        n = in.nextInt();
        while(n!=0){
            for(int i=2; i<n; i++){
                if(sieve[i]&&sieve[n-i]){
                    out.printf("%d = %d + %d\n",n,i,n-i);
                    break;
                }
            }

            n = in.nextInt();
        }
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