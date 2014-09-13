import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.InputStream;
import java.math.*;
import java.util.*;



public class Main {

    public static void main(String args[]) throws IOException{
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //begin
        //Scanner in = new Scanner(System.in);
        Task solver = new Task();
        solver.solve(in,out);
        //end
        out.close();

    }
}

class Task{


    public void solve(InputReader in, PrintWriter out){
        int ncases, q, n, st, y;
        ncases = in.nextInt();
        for(int nc=1; nc<=ncases; nc++){
            n = in.nextInt();
            q = (1 + (n<<1))/3;
            out.printf("%d %d %d\n",nc,n,q);
            st = n - q + 1;
            y = 1;
            if(n<4){
                if(n<3) out.println("[1,1]");
                else out.println("[1,1] [3,2]");
            }else{
                for(int i=0; i<q; ++i){
                    out.printf("[%d,%d]",st++,y);
                    if(i%8==7) out.println();
                    else out.print(" ");
                    y += 2;
                    if(y>st) y = 2;
                }
                if(q%8>0) out.println();
            }
            if(nc<ncases) out.println();
        }

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

