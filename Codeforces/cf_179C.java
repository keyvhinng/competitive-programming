import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //variables
        long[] arr = new long[100001];
        long[] l = new long[100000];
        long[] r = new long[100000];
        long[] d = new long[100000];
        long[] arrT = new long[100001];
        long[] inc = new long[100001];
        long s, t, n, m, k;
        int x, y;
        //start
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        for(int i=0; i<n; i++){
            arr[i] = in.nextInt();
        }
        for(int i=0; i<m; i++){
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            d[i] = in.nextInt();
        }
        for(int i=0; i<k; i++){
            x = in.nextInt();
            y = in.nextInt();
            arrT[x-1]++;
            arrT[y]--;
        }
        t = 0;
        for(int i=0; i<m; i++){
            t += arrT[i];
            s = t*d[i];
            inc[(int)l[i]-1] += s;
            inc[(int)r[i]] -= s;
        }
        t = 0;
        for(int i=0; i<n; i++){
            t += inc[i];
            s = t + arr[i];
            if(i!=0){
                out.print(" ");
            }
            out.print(s);
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
            }catch(IOException e){
                throw  new RuntimeException(e);
            }
        }
        return  tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.parseInt(next());
    }
}
