package 운동;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static int V, E;
	static int INF = 400 * 10000 + 1;
	static int dist[][];
	static int result = Integer.MAX_VALUE;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token = br.readLine().split(" ");
		V = Integer.parseInt(token[0]);
		dist = new int[V + 1][V + 1];
		for(int i = 0; i <= V; i++) {
			Arrays.fill(dist[i], INF);
		}
		E = Integer.parseInt(token[1]);
		while(E-- > 0) {
			token = br.readLine().split(" ");
			int a = Integer.parseInt(token[0]);
			int b = Integer.parseInt(token[1]);
			int c = Integer.parseInt(token[2]);
			dist[a][b] = c;
		}
		
		for(int mid = 1; mid <= V; mid++) {
			for(int from = 1; from <= V; from++) {
				for(int end = 1; end <= V; end++) {
					if(from == end) continue;
					dist[from][end] = Math.min(dist[from][end], dist[from][mid] + dist[mid][end]);
				}
			}
		}
		
		for(int i = 1; i <= V; i++) {
			for(int j = 1; j <= V; j++) {
				if(i == j) continue;
				if(dist[j][i] != INF && dist[i][j] != INF) {
					result = Math.min(result, dist[i][j] + dist[j][i]);
				}
			}
		}		
		System.out.println(result == Integer.MAX_VALUE ? -1 : result);
	}
}
