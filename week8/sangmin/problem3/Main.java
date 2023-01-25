package 서강그라운드;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static int n, m, r;
	static int[] items;
	static int[][] map;
	static int result = Integer.MIN_VALUE;
	static int INF = 1501;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token = br.readLine().split(" ");
		n = Integer.parseInt(token[0]);
		m = Integer.parseInt(token[1]);
		r = Integer.parseInt(token[2]);
		items = new int[n + 1];
		map = new int[n + 1][n + 1];
		token = br.readLine().split(" ");
		for(int i = 0; i <= n; i++) {
			Arrays.fill(map[i], INF);
			map[i][i] = 0;
		}
		for(int i = 0; i < token.length; i++)
			items[i + 1] = Integer.parseInt(token[i]);
		while(r-- > 0) {
			token = br.readLine().split(" ");
			int a = Integer.parseInt(token[0]);
			int b = Integer.parseInt(token[1]);
			int l = Integer.parseInt(token[2]);
			map[a][b] = l;
			map[b][a] = l;
		}
		
		for(int mid = 1; mid <= n; mid++)
			for(int from = 1; from <= n; from++)
				for(int to = 1; to <= n; to++) {
					map[from][to] = Math.min(map[from][to], map[from][mid] + map[mid][to]);
				}
		
		for(int i = 1; i <= n; i++) {
			int sum = 0;
			for(int j = 1; j <= n; j++) {
				if(map[i][j] <= m)
					sum += items[j];
			}
			result = Math.max(result, sum);
		}
		System.out.println(result);
	}
}
