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

    String ip[];

    public void solve(InputReader in, PrintWriter out){
        String s, sub, guess, bin;
        guess = ".";
        int ind, n, ini, num;
        n = in.nextInt();
        ip = new String[n];
        for(int i=0; i<n; i++){
            ip[i] = "";
            s = in.next();
            //out.println(s);
            ini = 0;
            for(int j=0; j<4; j++){
                ind = s.indexOf(".",ini);
                if(ind==-1) ind=s.length();
                sub = s.substring(ini,ind);
                num =Integer.parseInt(sub);
                bin = Integer.toBinaryString(num);
                while(bin.length()<8){
                    bin = "0" + bin;
                }
                //out.print(" num " + num + " : " + bin );
                ip[i] = ip[i] + bin;
                ini = ind+1;
            }
            //out.println(ip[i]);
        }


        char mask[] = new char[32];
        for(int i=0; i<32; i++)
            mask[i] = '0';
        for(int i=0; i<32; i++){
            boolean flag = true;
            char f = ip[0].charAt(i);
            for(int j=0; j<n; j++){
                if(ip[j].charAt(i) != f){
                    flag = false;
                    break;
                }
            }
            if(flag) mask[i] = '1';
            else break;
        }
        //out.println(mask);
        String nmask = "";
        for(int i=0; i<32; i++){
            nmask = nmask + mask[i];
        }
        int n1, n2, n3, n4;
        n1 = Integer.parseInt((nmask.substring(0,8)),2);
        n2 = Integer.parseInt((nmask.substring(8,16)),2);
        n3 = Integer.parseInt((nmask.substring(16,24)),2);
        n4 = Integer.parseInt((nmask.substring(24,32)),2);
        char first[] = new char[32];
        for(int i=0; i<32; i++){
            first[i] = '0';
        }

        for(int i=0; i<32; i++){
            if(mask[i]=='1') first[i] = ip[0].charAt(i);
        }

        String nfirst = "";
        for(int i=0; i<32; i++){
            nfirst = nfirst + first[i];
        }
        //first
        int m1, m2, m3, m4;
        m1 = Integer.parseInt((nfirst.substring(0,8)),2);
        m2 = Integer.parseInt((nfirst.substring(8,16)),2);
        m3 = Integer.parseInt((nfirst.substring(16,24)),2);
        m4 = Integer.parseInt((nfirst.substring(24,32)),2);
        out.println(m1+"."+m2+"."+m3+"."+m4);
        out.println(n1+"."+n2+"."+n3+"."+n4);

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

