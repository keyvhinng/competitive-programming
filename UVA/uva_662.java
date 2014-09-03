import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

public class Main {

    static int n, k;
    static int[] arr;
    static int[][] depot, dp, dpcost, p;

    public static int getcost(int a,int b){
        if(dpcost[a][b]!=-1) return dpcost[a][b];
        int ans = 1000000;
        for(int i=a; i<=b; i++) {
            int curr = 0;
            for (int j = a; j <= b; j++) {
                curr += Math.abs(arr[j] - arr[i]);
            }
            if(curr<ans){
                ans = curr;
                depot[a][b] = i;
            }
        }
        return dpcost[a][b]=ans;
    }

    public static int run(int a, int i){
        if(a==n-1 || i==k-1) return dp[a][i] = getcost(a,n-1);
        if(dp[a][i]!=-1) return dp[a][i];
        int ans = 1000000;
        for(int b=a; b<n; b++){
            if(ans > getcost(a,b)+run(b+1,i+1)) {
                ans = getcost(a, b) + dp[b+1][i+1];
                p[a][i] = b+1;
            }
        }
        return dp[a][i] = ans;
    }

    public static void main(String args[]) throws IOException{
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        //begin
        int ans, nc = 1, loc;
        while(true){
            n = in.nextInt();
            k = in.nextInt();
            if(n==0 && k==0) break;
            p = new int[250][250];
            depot = new int[250][250];
            dp = new int[250][250];
            dpcost = new int[250][250];
            for(int i=0; i<250; i++) {
                for(int j=0; j<250; j++) {
                    dp[i][j] = -1;
                    dpcost[i][j] = -1;
                    p[i][j] =  -1;
                }
            }
            arr = new int[n];
            for(int i=0; i<n; i++){
                arr[i]=in.nextInt();
            }
            out.printf("Chain %d\n",nc++);
            ans = run(0,0);
            int a = 0;
            int nd = 1;
            int stp = 0;
            while(a!=-1){
                out.printf("Depot %d at restaurant ",nd++);
                if(stp==k-1) {
                    if (a == n - 1) loc = a;
                    else loc = depot[a][n-1];
                    out.printf("%d serves ",loc+1);   //check

                }else{
                    out.printf("%d serves ",depot[a][p[a][stp]-1]+1);   //check

                }

                if(p[a][stp]!=-1){
                    if(a+1!=p[a][stp])
                        out.printf("restaurants %d to %d\n",a+1,p[a][stp]);
                    else
                        out.printf("restaurant %d\n",p[a][stp]);
                }else{
                    if(a==n-1)
                        out.printf("restaurant %d\n",a+1);
                    else
                        out.printf("restaurants %d to %d\n",a+1,n);
                }
                a = p[a][stp];
                stp++;
            }
            out.printf("Total distance sum = %d\n",ans);
            out.printf("\n");
        }
        //close
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
        return tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.parseInt(next());
    }

}

