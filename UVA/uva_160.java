import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args){
        InputStream inputStream = System.in;
        //OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        //PrintWriter out = new PrintWriter(outputStream);
        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        boolean[] isP = new boolean[101];
        int[] factors = new int[101];


        int n, r, ans, tam;
        n = in.nextInt();
        tam = primes.length;
        while(n!=0){
            System.out.printf("%3d! =",n);
            factors = new int[101];
            r = 0;
            while(r<primes.length && primes[r]<=n){
                factors[primes[r]] += count(n,primes[r]);
                r++;
            }
            r = 0;
            while( r<primes.length && primes[r]<=n){
                if(factors[primes[r]]!=0){
                    if(r==15){
                        System.out.printf("\n      ");
                    }
                    System.out.printf("%3d", factors[primes[r]]);
                }
                r++;
            }
            System.out.println("");
            n = in.nextInt();
        }
        //out.close();

    }


    static int count(int N, int x) {
        int count = 0;
        for (int i = x; i <= N; i *= x)
            count += N / i;
        return count;
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
            } catch(IOException e){
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.parseInt(next());
    }
}
