import java.io.*;
class Main {
    public static void main(String[] args) throws NumberFormatException, IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s1, s2;
        int[][] DP = new int[1005][1005];
        while(true){
            s1 = in.readLine();
            if(s1 == null){
                break;
            }
            s2 = in.readLine();
            s1 = s1.trim();
            s2 = s2.trim();
            for(int i=0; i<=s1.length(); i++){
                DP[i][0] = 0;
            }
            for(int i=0; i<=s2.length(); i++){
                DP[0][i] = 0;
            }
            for(int i=1; i<=s1.length(); i++){
                for(int j=1; j<=s2.length(); j++){
                    if(s1.charAt(i-1)==s2.charAt(j-1)){
                        DP[i][j] = 1 + DP[i-1][j-1];
                    }else{
                        if(DP[i-1][j]>=DP[i][j-1]){
                            DP[i][j] = DP[i-1][j];
                        }else{
                            DP[i][j] = DP[i][j-1];
                        }
                    }
                }
            }
            System.out.println(DP[s1.length()][s2.length()]);
        }
    }
}
