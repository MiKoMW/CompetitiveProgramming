import java.util.Scanner;

/**
 * Created by Mac on 2018/4/7.
 */
public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int ans = 0;

        int size = in.nextInt();

        String input = in.next();

        while(input.contains("xxx")){
            ans++;

            input = input.replaceFirst("xxx","xx");

        }

        System.out.println(ans);

    }

}
