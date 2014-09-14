import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.util.Scanner;

public class Main {
        public static void main(String[] args){
            int n, count;
            int[] arr = new int[1010];
            Scanner in = new Scanner(System.in);
            while(in.hasNext()){
                n = in.nextInt();
                for(int i=0; i<n; i++){
                    arr[i] = in.nextInt();
                }
                count = 0;
                for(int i=0; i<n; i++){
                    for(int j=i+1; j<n; j++){
                        if(arr[j]<arr[i])
                            count++;
                    }
                }
                System.out.printf("Minimum exchange operations : %d\n",count);
            }

        }
}

