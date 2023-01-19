package 텔레포트;

import java.util.*;
import java.io.*;

class City{
	int s, x, y;
	
	public City(int s, int x, int y) {
		this.s = s;
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static int N, T, M;
	static City[] cities;
	static int[][] dist;
	static int INF = 2001;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token = br.readLine().split(" ");
		N = Integer.parseInt(token[0]);
		T = Integer.parseInt(token[1]);
		cities = new City[N + 1];
		dist = new int[N + 1][N + 1];
		for(int i = 1; i <= N; i++) {
			token = br.readLine().split(" ");
			int s = Integer.parseInt(token[0]);
			int x = Integer.parseInt(token[1]);
			int y = Integer.parseInt(token[2]);
			cities[i] = new City(s, x, y);
			Arrays.fill(dist[i], INF);
			dist[i][i] = 0;
		}
		M = Integer.parseInt(br.readLine());
		
		for(int from = 1; from <= N; from++)
			for(int to = 1; to <= N; to++) {
				dist[from][to] = Math.abs(cities[from].x - cities[to].x) + Math.abs(cities[from].y - cities[to].y);
				if(cities[from].s == 1 && cities[to].s == 1)
					dist[from][to] = Math.min(dist[from][to], T);
			}
		
		for(int mid = 1; mid <= N; mid++)
			for(int from = 1; from <= N; from++)
				for(int to = 1; to <= N; to++) {
					dist[from][to] = Math.min(dist[from][to], dist[from][mid] + dist[mid][to]);
				}
		
		
		while(M-- > 0) {
			token = br.readLine().split(" ");
			int A = Integer.parseInt(token[0]);
			int B = Integer.parseInt(token[1]);
			System.out.println(dist[A][B]);
		}
	}
}
