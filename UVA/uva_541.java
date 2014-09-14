import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

class Main {
    static final int MAX = 100;
    public static void main(String[] args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //start
        int n, hi, vi, he, vo, ve, cont;
        int[][] m = new int[MAX][MAX];
        n = in.nextInt();
        while(n!=0){
            hi = 0;
            he = 0;
            vi = 0;
            ve = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    m[i][j] = in.nextInt();
                }
            }
            //compute rows
            for(int i=0; i<n; i++){
                cont = 0;
                for(int j=0; j<n; j++){
                    cont += m[i][j];
                }
                if(cont%2==0){
                    he++;
                }else{
                    hi = i;
                }
            }
            //compute columns
            for(int i=0; i<n; i++){
                cont = 0;
                for(int j=0; j<n; j++){
                    cont += m[j][i];
                }
                if(cont%2==0){
                    ve++;
                }else{
                    vi = i;
                }
            }
            hi++;
            vi++;
            //ask
            if((he==n)&&(ve==n)){
                out.printf("OK\n");
            }else if((he==n-1)&&(ve==n-1)){
                out.printf("Change bit (%d,%d)\n",hi,vi);
            }else{
                out.printf("Corrupt\n");
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
