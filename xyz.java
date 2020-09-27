import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
	public static void main (String[] args) {
	    Scanner S = new Scanner(System.in);
	    int n = S.nextInt();
	    Vector v = new Vector();
        int j = 0;
        for(int i = 1; i < Math.sqrt(n); i++){
            if(n % i == 0){
                if(i == n / i) v.add(i);
                else {
                    v.add(i);
                    v.add(n / i);
                }
            }
        }

        Collections.sort(v);

	    for(Object obj : v){
	        System.out.print(obj);
	        System.out.printf(" ", args);
	    }
	}
}
