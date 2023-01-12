package 타임머신;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Node{
	int num, value;
	
	public Node(int num, int value) {
		this.num = num;
		this.value = value;
	}
}

public class Main {
	
	static int N, M;
	static List<List<Node>> graph = new ArrayList<>();
	static long INF = 10000 * 6000 + 1;
	static long[] dist;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token = br.readLine().split(" ");
		N = Integer.parseInt(token[0]);
		dist = new long[N + 1];
		Arrays.fill(dist, INF);
		dist[1] = 0;
		
		for(int i = 0; i <= N; i++)
			graph.add(new ArrayList<>());
		
		M = Integer.parseInt(token[1]);
		for(int i = 0; i < M; i++) {
			token = br.readLine().split(" ");
			int A = Integer.parseInt(token[0]);
			int B = Integer.parseInt(token[1]);
			int C = Integer.parseInt(token[2]);
			graph.get(A).add(new Node(B, C));
		}
		boolean isCycle = false;
		for(int i = 0; i <= N; i++) {
			isCycle = false;
			for(int from = 1; from <= N; from++) {
				for(Node nextNode : graph.get(from)) {
					if(dist[from] + nextNode.value < dist[nextNode.num]) {
						if(dist[from] == INF) continue;
						dist[nextNode.num] = dist[from] + nextNode.value;
						isCycle = true;
					}
				}
			}
		}
		if(isCycle)
			System.out.println(-1);
		else {
			for(int i = 2; i <= N; i++) {
				System.out.println(dist[i] == INF ? -1 : dist[i]);
			}
		}
	}
}
/*
3 4
1 2 4
1 3 3
2 3 -1
3 1 -2


*/