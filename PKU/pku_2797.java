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
        //InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //begin
        Scanner in = new Scanner(System.in);
        Task solver = new Task();
        solver.solve(in,out);
        //end
        out.close();

    }
}

class Task{
    int wdd;
    int wed;
    int ntd;

    static final int[] cost = new int[]{3, 4, 5, 1};
    static final int[] pwdd = new int[]{1, 2, 3, 1};
    static final int[] pwed = new int[]{1, 2, 0, 0};
    static final int[] pntd = new int[]{1, 1, 2, 0};

    int[] opt;
    int best;

    public void solve(Scanner in, PrintWriter out){
        wdd = in.nextInt();
        wed = in.nextInt();
        ntd = in.nextInt();
        in.close();

        opt = new int[4];
        opt[0] = Math.max(wdd, Math.max(wed, ntd));
        best = opt[0] * cost[0];

        for (int i = 0; i <= 1000; i++) {
            int minj = (wed - i * pwed[0] + pwed[1] - 1) / pwed[1];
            if (minj < 0) {
                minj = 0;
            }
            for (int j = minj; cost[0] * i + cost[1] * j < best; j++) {
                int k = (ntd - i * pntd[0] - j * pntd[1] + pntd[2] - 1) / pntd[2];
                if (k < 0) {
                    k = 0;
                }
                int l = (wdd - i * pwdd[0] - j * pwdd[1] - k * pwdd[2] + pwdd[3] - 1) / pwdd[3];
                if (l < 0) {
                    l = 0;
                }

                if (i * cost[0] + j * cost[1] + k * cost[2] + l * cost[3] < best) {
                    best = i * cost[0] + j * cost[1] + k * cost[2] + l * cost[3];
                    opt[0] = i;
                    opt[1] = j;
                    opt[2] = k;
                    opt[3] = l;
                }
            }
        }

        out.println(opt[0] * cost[0] + " " + opt[3] * cost[3] + " " + opt[1] * cost[1] + " " + opt[2] * cost[2]);
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

