import java.io.InputStreamReader;
import java.io.IOException;
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
              int ncases, s, d, a, b;
              ncases = in.nextInt();
              for(int i=0; i<ncases; i++){
                s = in.nextInt();
                d = in.nextInt();
                a = (s+d)/2;
                if(a<d || ((s+d)%2==1)){
                    out.println("impossible");
                }
                else{
                    b = s - a;
                    out.println(a+" "+b);
                }
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
        while(tokenizer == null || !tokenizer.hasMoreTokens()){
            try{
                tokenizer = new StringTokenizer(reader.readLine());
            }catch (IOException e){
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public int nextInt(){
        return Integer.parseInt((next()));
    }
}
