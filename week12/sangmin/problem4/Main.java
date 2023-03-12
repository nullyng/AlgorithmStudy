package algo.week12.수묶기;

import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static int[] ary;

    public static void main(String[] args) throws Exception{
        int result = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        ary = new int[N];
        for(int i = 0; i < N; i++)
            ary[i] = Integer.parseInt(br.readLine());
        Arrays.sort(ary);
        int left = 0;
        int right = N - 1;

        for(; left < right; left += 2){
            if(ary[left] < 1 && ary[left + 1] < 1)
                result += ary[left] * ary[left + 1];
            else
                break;
        }
        for(; right > 0; right -= 2){
            if(ary[right] > 1 && ary[right - 1] > 1)
                result += ary[right] * ary[right - 1];
            else
                break;
        }
        for(;left <= right; left++)
            result += ary[left];
        System.out.println(result);
    }
}

/*
17
-1
-2
-3
-4
-5
0
0
0
0
1
1
1
1
2
3
4
5

3
1
2
3

3
-1
2
3

3
-1
-2
3

 */