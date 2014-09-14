import java.util.Scanner;
public class Main {
    public static void main(String args[]){
        int[] arr = new int[10010];
        int m ,ne, j, k, aux;
        ne = 0;
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            arr[ne] = in.nextInt();
            //sort
            j = ne - 1;
            k = arr[ne];
            while(j>=0 && arr[j]>k ){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = k;
            if(ne%2==1){
                m = arr[ne/2] + arr[(ne/2)+1];
                m /= 2;
            }else{
                m = arr[ne/2];
            }
            ne++;
            System.out.println(m);
        }
    }
}
