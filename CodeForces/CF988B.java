import java.util.*;

/**
 * Created by Mac on 2018/4/7.
 */
public class Main {
    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        int size = in.nextInt();

        List<String> list = new ArrayList<>();


        for(int con = 0; con < size; con++){
            list.add(in.next());
        }

        Collections.sort(list,new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    if(o1 == null || o2 == null){
                        return -1;
                    }
                    if(o1.length() > o2.length()){
                        return 1;
                    }
                    if(o1.length() < o2.length()){
                        return -1;
                    }
                    if(o1.compareTo(o2) > 0){
                        return 1;
                    }
                    if(o1.compareTo(o2) < 0){
                        return -1;
                    }
                    if(o1.compareTo(o2) == 0){
                        return 0;
                    }
                    return 0;
                }
            });
        String pre = "";
        boolean ans = true;
            for(String s:list){
                 ans = ans && s.contains(pre);
                 pre = s;
            }
            if(ans){
                System.out.println("YES");
                for(String st : list){
                    System.out.println(st);
                }
            }else{
                System.out.println("NO");
            }


        }


}
