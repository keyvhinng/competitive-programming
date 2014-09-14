import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

class Main {
    public static void main(String[] args){
        //initialize in and out
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //start
        int d, bin, hx, ncases, m, b1, b2, r;
        ncases = in.nextInt();
        for(int i=0; i<ncases; i++){
            m = in.nextInt();
            b1 = 0;
            b2 = 0;
            bin = m;
            //decimal
            while(bin!=0){
                if(bin%2==1){
                    b1++;
                }
                bin /= 2;
            }
            //hexadecimal
            hx = m;
            while(hx!=0){
                d = hx % 10;
                while(d!=0){
                    if(d%2==1){
                        b2++;
                    }
                    d /= 2;
                }
                hx /= 10;
            }
            //print
            out.printf("%d %d\n",b1,b2);
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
            } catch (IOException e){
                throw  new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.parseInt(next());
    }
}