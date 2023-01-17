package 호석이두마리치킨;

import java.util.*;
import java.io.*;

public class Main {
	static int N, M;
	static int[][] dist;
	static int INF = 101;
	static int[] result = new int[2];
	static int total = Integer.MAX_VALUE;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token = br.readLine().split(" ");
		N = Integer.parseInt(token[0]);
		M = Integer.parseInt(token[1]);
		dist = new int[N + 1][N + 1];
		for(int i = 0; i < dist.length; i++) {
			Arrays.fill(dist[i], INF);
			dist[i][i] = 0;
		}
		while(M-- > 0) {
			token = br.readLine().split(" ");
			int A = Integer.parseInt(token[0]);
			int B = Integer.parseInt(token[1]);
			dist[A][B] = 1;
			dist[B][A] = 1;
		}
		
		for(int mid = 1; mid <= N; mid++) {
			for(int from = 1; from <= N; from++) {
				for(int end = 1; end <= N; end++) {
					dist[from][end] = Math.min(dist[from][end], dist[from][mid] + dist[mid][end]);
				}
			}
		}
		findNumber(0, new boolean[N + 1], new int[2]);
		System.out.println(result[0] + " " + result[1] + " " + 2 * total);
	}
	
	public static void findNumber(int depth, boolean[] isVisit, int[] selected) {
		if(depth == 2) {
			int sum = 0;
			
			for(int i = 1; i <= N; i++) {
				sum += Math.min(dist[selected[0]][i], dist[selected[1]][i]);
			}
			
			if(sum < total) {
				result[0] = selected[0];
				result[1] = selected[1];
				total = sum;
			}
			return;
		}
		for(int i = 1; i <= N; i++) {
			if(isVisit[i]) 
				continue;
			isVisit[i] = true;
			selected[depth] = i;
			findNumber(depth + 1, isVisit, selected);
			isVisit[i] = false;
		}
	}
}
