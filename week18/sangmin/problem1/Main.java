package algo.week18.problem1;

import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] parents;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        parents = new int[N + 1];
        for(int i = 0; i <= N; i++)
            parents[i] = i;

        for(int i = 0; i < N - 2; i++){
            String[] token = br.readLine().split(" ");
            int a = Integer.parseInt(token[0]);
            int b = Integer.parseInt(token[1]);
            int aParent = findParents(a);
            int bParent = findParents(b);
            if(aParent != bParent)
                parents[aParent] = bParent;
        }

        for(int i = 1; i <= N; i++)
            findParents(i);
        int a = findParents(1);
        for(int i = 2; i <= N; i++)
            if(a != parents[i]){
                System.out.println(a + " " + parents[i]);
                return;
            }

    }

    static int findParents(int num){
        if(parents[num] == num)
            return num;
        return parents[num] = findParents(parents[num]);
    }
}

/*
8
1 2
3 4
3 5
7 8
6 7
5 2


 */