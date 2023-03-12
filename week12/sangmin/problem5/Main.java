package 단어수학;

import java.util.*;
import java.io.*;

public class Main {
	
	static int N;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int result = 0;
		N = Integer.parseInt(br.readLine());
		Integer[] ary = new Integer[26];
		Arrays.fill(ary, 0);
		while(N-- > 0) {
			String line = br.readLine();
			int digit = 1;
			for(int i = line.length() - 1; i >= 0; i--) {
				ary[line.charAt(i) - 'A'] += digit;
				digit *= 10;
			}
		}
		
		Arrays.sort(ary, Collections.reverseOrder());
		
		int number = 9;
		for(int num : ary) {
			result += num * number--;
		}
		System.out.println(result);
	}
}