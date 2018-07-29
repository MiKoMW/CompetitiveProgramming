import java.util.Scanner;
import java.util.TreeSet;

/**
 * Created by Mac on 2018/4/7.
 */
public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        long k = in.nextLong();

        TreeSet<Long> pro = new TreeSet<>();

        for(int con = 0; con < n; con++){
            pro.add(in.nextLong());
        }

        long maxDiff = k;

        long ans = 0;

        for(Long lg : pro){

            while(maxDiff * 2 < lg) {
                maxDiff *= 2;
                ans++;

            }

            if(lg > maxDiff){
                        maxDiff = lg;
            }
        }

        System.out.println(ans);




    }

}
