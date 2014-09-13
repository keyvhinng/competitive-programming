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
        in.close();
        out.close();

    }
}

class Task{
    int n;
    int m;

    List<Edge>[] edges;
    boolean[] visited;
    boolean[] processed;
    int[] enter;
    int[] retenter;
    int time;

    int colors;
    boolean cactus;

    
    public class Edge{
        int s;
        int d;
        int c;

        public Edge(int s, int d){
            this.s = s;
            this.d = d;
            c = 0;
        }
    }
    

    public class Pair{
        int v;
        int c;

        public Pair(int v, int c){
            this.v = v;
            this.c = c;
        }

        public boolean equals(Object o){
            final Pair pair = (Pair)o;

            if(c != pair.c) return false;
            if(v != pair.v) return false;

            return true;
        }

        public int hashCode(){
            int result;
            result = v;
            result = 29 * result + c;
            return result;
        }
    }



    public void dfs(int i) {
        visited[i] = true;
        enter[i] = time++;
        retenter[i] = enter[i];

        for (Edge e : edges[i]) {
            if (!visited[e.d]) {
                dfs(e.d);
                if (retenter[e.d] < retenter[i]) {
                    retenter[i] = retenter[e.d];
                }
            } else {
                if (enter[e.d] < retenter[i]) {
                    retenter[i] = enter[e.d];
                }
            }
        }
    }


    public void color(int i, int c) {
        visited[i] = true;
        for (Edge e : edges[i]) {
            if (!visited[e.d]) {
                if (retenter[e.d] < enter[i]) {
                    color(e.d, c);
                } else {
                    ++colors;
                    color(e.d, colors);
                }
            } else if (!processed[e.d]) {
                e.c = c;
            }
        }
        processed[i] = true;
    }


    public void solve(Scanner in, PrintWriter out){
        boolean flag = true;
        while(in.hasNext()){
            n = in.nextInt();
            m = in.nextInt();

            edges = new List[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new ArrayList<Edge>();
            }

            int ec = 0;
            for(int i=0; i<m; i++){
                int k = in.nextInt();
                int a = in.nextInt();
                for (int j = 1; j < k; j++) {
                int b = in.nextInt();
                edges[a - 1].add(new Edge(a - 1, b - 1));
                edges[b - 1].add(new Edge(b - 1, a - 1));
                ec++;
                a = b;
                }
            }

            visited = new boolean[n];
            enter = new int[n];
            retenter = new int[n];
            time = 0;

            dfs(0);

            cactus = true;
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    cactus = false;
                }
            }

            BigInteger ans = BigInteger.ZERO;
            if(cactus){
                Arrays.fill(visited, false);
                processed = new boolean[n];

                colors = 0;
                color(0,0);

                Map<Pair,Integer> pairs = new HashMap<Pair, Integer>();
                int[] nec = new int[colors];
                Pair pp;
                int c;
                for(int i=0; i<n; i++){
                    for(Edge e: edges[i]){
                        if(e.c > 0) {
                            nec[e.c - 1]++;
                            pp = new Pair(e.s, e.c);
                            if (pairs.containsKey(pp)) {
                                c = pairs.get(pp);
                            } else {
                                c = 0;
                            }
                            if (c >= 2) {
                                cactus = false;
                            }
                            pairs.put(pp, c + 1);

                            pp = new Pair(e.d, e.c);
                            if (pairs.containsKey(pp)) {
                                c = pairs.get(pp);
                            } else {
                                c = 0;
                            }
                            if (c >= 2) {
                                cactus = false;
                            }
                            pairs.put(pp, c + 1);
                        }
                    }
                }

                if(cactus) {
                    ans = BigInteger.ONE;
                    for (int i = 0; i < colors; i++) {
                        if (nec[i] > 1) {
                            ans = ans.multiply(BigInteger.valueOf(nec[i] + 1));
                        }
                    }
                }
            }
            if(flag) flag=false;
            else out.println();
            out.println(ans);
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

