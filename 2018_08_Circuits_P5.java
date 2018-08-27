// code_report Solution
// https://youtu.be/Ndc1EMq25R0

// NOTE: this solution is not complete
// TreeMap fish should not be used, because it will not cover the case where there are duplicate keys

import java.util.*;
import java.io.*;

public class Main{

     public static void main (String []args) {
        Scanner sc = new Scanner (System.in);
        
        int t = sc.nextInt ();
        while (t-- != 0) {
            int n = sc.nextInt ();
            
            TreeMap<Integer,Integer> fish = new TreeMap<> (); // e & s
            TreeMap<Integer,Integer> pond = new TreeMap<> (); // s & count
            
            for (int i = 0; i < n; ++i) {
                int s = sc.nextInt ();
                int e = sc.nextInt ();
                fish.put (e, s);
            }
            
            int c   = 0; // current fish in pond
            int ans = 0; // max fish in pond
            
            for (Map.Entry<Integer,Integer> e : fish.entrySet ()) {
                c++;
                int s = e.getValue ();
                int x = pond.containsKey (s) ? pond.get (s) : 0; // exists
                pond.put (s, x + 1);

                for (Iterator<Map.Entry<Integer,Integer>> f = pond.entrySet ().iterator (); f.hasNext (); ) {
                    Map.Entry<Integer,Integer> entry = f.next ();
                    if (entry.getKey () <= e.getKey ()) {
                        c -= entry.getValue ();
                        f.remove ();
                    }
                }
                ans = Math.max (ans, c);
            }
            
            System.out.println (ans);
        }
     }
}
