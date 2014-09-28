import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

public class Main {

    static int N, M;
    static int[][] AdjMat = new int[110][110];
    static int[] dfs_num = new int[110];
    static int flag, uCycle, vCycle;

    static void DFS(int u, int p){
        int val;
        dfs_num[u] = 0;          // GRAY
        for(int v=0; v<N; v++){
            if(AdjMat[u][v]==1){
                if(v!=p){
                    if(dfs_num[v]==0){
                        uCycle = u;
                        vCycle = v;
                        flag = 1;
                        break;
                    }
                    if(dfs_num[v]==-1){
                        DFS(v,u);
                    }
                }
            }
        }
        if(flag == 0)
            dfs_num[u] = 1;
    }

    public static void main(String[] args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //begin
        int u, v, visit;
        N = in.nextInt();
        M = in.nextInt();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                AdjMat[i][j] = 0;
            }
            dfs_num[i] = -1;
        }
        for(int i=0; i<M; i++){
            u = in.nextInt();
            v = in.nextInt();
            AdjMat[u-1][v-1] = 1;
            AdjMat[v-1][u-1] = 1;
        }
        flag = 0;
        DFS(0,0);
        if(flag==1){
            //out.println("there is a cycle");
            //out.println("between "+ uCycle + " " +  vCycle);
            AdjMat[uCycle][vCycle] = 0;
            AdjMat[vCycle][uCycle] = 0;
            for(int i=0; i<N; i++){
                dfs_num[i] = -1;
            }
            flag = 0;
            DFS(0,0);
            //check if everyone were visited
            visit = 1;
            for(int i=0; i<N; i++){
                if(dfs_num[i]!=1){
                    visit = 0;
                    break;
                }
            }
            if(visit==1){
                out.println("FHTAGN!");
            }
            else{
                out.print("NO");
            }
        }
        else
            out.print("NO");
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
        return Integer.parseInt(next());
    }
}