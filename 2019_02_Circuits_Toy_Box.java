// code_report Solution
// Video Link: https://youtu.be/9eBNy3wKcKc
// Problem Link: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/toy-box-5044b3ed/

import java.util.Scanner;
import java.lang.Math;

class Main {
    public static void main(String args[] ) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m+1];
        while (n-- != 0) {
            int p = sc.nextInt();
            int b = sc.nextInt();
            a[b] = Math.max(p, a[b]);
        }
        int sum = 0;
        for (int e : a) sum += e;
        System.out.println(sum);
    }
}
