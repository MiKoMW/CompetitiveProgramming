import java.util.*;

/**
 * Created by Mac on 2018/4/7.
 */
public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        String temp = in.next();

        if(!temp.contains("1")){
            System.out.println("no");
            return;
        }

        temp = temp.substring(temp.indexOf('1'));

        temp = temp.replaceAll("1","");

        if(temp.length() >= 6){
            System.out.println("yes");
        }else{
            System.out.println("no");
        }






    }

}
