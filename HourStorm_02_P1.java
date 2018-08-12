// code_report Solution
// https://youtu.be/LV6DTbLBL8M

import java.util.*;
import java.io.*;

public class Main {

     public static void main (String []args){
        
        Scanner sc = new Scanner (System.in);
        int x = sc.nextInt ();
        int y = sc.nextInt ();
        int s = sc.nextInt ();
        int t = sc.nextInt ();
        int c = 0;
        
        for (int i = 0, j = t; i <= t; ++i, --j) {
           if (j >= y && j <= y + s) {
               c += Math.min (Math.max (0, i - x + 1), s + 1);
           }
        }
    
        System.out.println (c);
        
     }
}
