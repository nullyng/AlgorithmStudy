package 강의실배정.누적합;

import java.util.*;
import java.io.*;

public class Main {
	static int N;
	static Map<Integer, Integer> map = new TreeMap<>();
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		while(N-- > 0) {
			String[] token = br.readLine().split(" ");
			int key = Integer.parseInt(token[0]);
			map.put(key, map.getOrDefault(key, 0) + 1);
			key = Integer.parseInt(token[1]);
			map.put(key, map.getOrDefault(key, 0) - 1);
		}
		int sum = 0;
		int max = Integer.MIN_VALUE;
		for(int key : map.keySet()) {
			sum += map.get(key);
			max = Math.max(sum, max);
		}
		System.out.println(max);
	}
}

/*
8
1 8
9 16
3 7
8 10
10 14
5 6
6 11
11 12
3

5
1 7
2 3
3 4
4 8
7 10
2

3
999999999 1000000000
999999998 999999999 
1 999999998

*/