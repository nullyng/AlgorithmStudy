package 회장뽑기;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
	static int N;
	static int[][] map;
	static int[] value;
	static int INF = 51;
	static int resultScore = INF, resultCount = 0;
	static List<Integer> resultCandidate = new ArrayList<>();
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		int A = 0, B = 0;
		map = new int[N + 1][N + 1];
		value = new int[N + 1];
		for(int i = 1; i <= N; i++)
			Arrays.fill(map[i], INF);
		while(true) {
			String[] token = br.readLine().split(" ");
			A = Integer.parseInt(token[0]);
			B = Integer.parseInt(token[1]);
			if(A == -1) break;
			map[A][B] = 1;
			map[B][A] = 1;
		}
		
		for(int mid = 1; mid <= N; mid++)
			for(int from = 1; from <= N; from++)
				for(int to = 1; to <= N; to++) {
					map[from][to] = Math.min(map[from][to], map[from][mid] + map[mid][to]);
				}
		
		
		for(int i = 1; i <= N; i++) {
			int score = 0;
			for(int j = 1; j <= N; j++) {
				if(i == j) continue;
				score = Math.max(score, map[i][j]);
			}
			value[i] = score;
			resultScore = Math.min(resultScore, score);
		}
		
		for(int i = 1; i <= N; i++) {
			if(value[i] == resultScore) {
				resultCount++;
				resultCandidate.add(i);
			}
		}
		
		System.out.println(resultScore + " " + resultCount);
		for(int num : resultCandidate)
			System.out.print(num + " ");
	}
}
