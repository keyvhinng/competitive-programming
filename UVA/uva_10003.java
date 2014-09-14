import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

public class Main {

    static int[][] DP  = new int[1010][1010];
    static int[]   arr = new int[60];
    static int n;



    static int run(int i, int j){
        int flag;
        int min = 10000;
        int ans;
        flag = 0;
        if(DP[i][j]!=-1){
            return DP[i][j];
        }
        for(int r=0; r<n; r++){
            if((arr[r]-1>=i) && (arr[r]-1<j)){
                flag = 1;
                ans = run(i,arr[r]-1) + run(arr[r], j) + j - i + 1;
                if(ans < min){
                    min = ans;
                }
            }
        }

        if(flag==0){
            min = 0;
        }
        return DP[i][j] = min;
    }

    public static void main(String[] args){

        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        //begin
        int ans, l;
        l = in.nextInt();
        while(l!=0){

            for(int i=0; i<l; i++){
                for(int j=0; j<l; j++){
                    DP[i][j] = -1;
                }
            }
            n = in.nextInt();

            for(int i=0; i<n; i++){
                arr[i] = in.nextInt();
            }
            ans = run(0,l-1);
            out.println("The minimum cutting is " + ans + ".");
            l = in.nextInt();
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