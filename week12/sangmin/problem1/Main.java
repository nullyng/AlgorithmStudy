package 과제;

import java.util.*;
import java.io.*;

public class Main {
	
	static boolean[] isVisit = new boolean[1001];
	static int N;
	static int[][] ary;
	static int result = 0;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		ary = new int[N][2];
		
		while(N-- > 0) {
			String[] token = br.readLine().split(" ");
			ary[N][0] = Integer.parseInt(token[0]);
			ary[N][1] = Integer.parseInt(token[1]);
		}
		
		Arrays.sort(ary, (o1, o2) -> Integer.compare(o2[1], o1[1]));
		
		for(int i = 0; i < ary.length; i++) {
			int time = ary[i][0];
			int value = ary[i][1];
			
			if(!isVisit[time]) {
				result += value;
				isVisit[time] = true;
			}
			else {
				while(isVisit[time]) {
					time--;
				}
				if(time != 0) {
					isVisit[time] = true;
					result += value;
				}
			}
		}
		System.out.println(result);
	}
}
