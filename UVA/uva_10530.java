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
        //begin
        int end, n, a, b, g;
        String s1, s2;
        while(true){
            n = in.nextInt();
            if(n==0) break;
            s1 = in.next();
            //out.println("s1 " + s1);
            s2 = in.next();
            //out.println("s2 " + s2);
            a = 0;
            b = 11;
            while(!s2.equals("on")){
                if(s2.equals("low")){
                    if(n>a) a = n;
                }
                else
                    if(n<b) b = n;

                n = in.nextInt();
                s1 = in.next();
                s2 = in.next();
            }
            //out.println("last " + n );
            if(n > a && n<b)
                out.println("Stan may be honest");
            else
                out.println("Stan is dishonest");
        }
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