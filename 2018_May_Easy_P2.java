// code_report Solution
// https://youtu.be/Be2rZ647SzM

import java.util.*;
import java.io.*;

public class Main {

     public static void main (String []args) 
     {
        Scanner scan = new Scanner (System.in);
        int n = scan.nextInt ();
        double[] v = new double[2*n];
        for (int i = 0; i < n; i++) {
            int a  = scan.nextInt ();
            int b  = scan.nextInt ();
            v[i]   = a;
            v[n+i] = b + 0.5;
        }
        
        Arrays.sort (v);
        
        int x = 0, y = 0, sum = 0; // x = min_candies, y = max_students
        
        for (int i = 0; i < 2*n; ++i) {
            sum += v[i] % 1.0 == 0 ? 1 : -1;
            if (sum > y) {
                y = sum;
                x = (int) v[i];
            }
        }
        
        System.out.println (Integer.toString (x) + " " + Integer.toString (y));
     }
}
