package 약수의합;

import java.util.*;
import java.io.*;

public class Main {
	static int T;
	static long[] sums = new long[1000001];
	static long[] prefixSum = new long[1000001];
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		
		Arrays.fill(sums, 1);
		
		for(int i = 2; i < sums.length; i++)
			for(int j = 1; j * i < sums.length; j++)
				sums[i * j] += i;
		
		for(int i = 1; i < prefixSum.length; i++)
			prefixSum[i] = prefixSum[i - 1] + sums[i];
		StringBuilder sb = new StringBuilder();
		while(T-- > 0) {
			int number = Integer.parseInt(br.readLine());
			sb.append(prefixSum[number] + "\n");
		}
		System.out.println(sb.toString());
	}
}