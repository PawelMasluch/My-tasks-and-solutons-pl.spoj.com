// AC (Compiler: Java HotSpot 12)
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    private static final int MAX_N = 100;

    public static void main(String[] args) {

        /* Preprocessing */

        BigInteger [] ans = new BigInteger [MAX_N+1];

        ans[0] = BigInteger.valueOf(1);
        for(int i=1; i<=MAX_N; ++i) {
            ans[i] = ans[i - 1].multiply(BigInteger.valueOf(i));
        }


        // --------------------------


        /* Input data and printing answers */

        Scanner scanner = new Scanner(System.in);

        // Number of queries
        int t = scanner.nextInt();

        int n;
        for(int i=1; i<=t; ++i){
            n = scanner.nextInt();
            System.out.println( ans[n] );
        }


        // --------------------------
    }
}
