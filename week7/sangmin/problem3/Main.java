package 주간미팅;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Node implements Comparable<Node>{
	int to, value;
	
	public Node(int to, int value) {
		this.to = to;
		this.value = value;
	}
	
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.to, o.to);
	}
}

public class Main {
	static int N, V, E, A, B;
	static int[] team;
	static int result = 0;
	static int INF = 10000 * 100 + 1;
	static List<List<Node>> graph = new ArrayList<>();
	public static void main(String[] args) throws Exception{
		init();
		dijkstra(A);
		dijkstra(B);
		System.out.println(result);
	}
	
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token = br.readLine().split(" ");
		N = Integer.parseInt(token[0]);
		V = Integer.parseInt(token[1]);
		for(int i = 0; i <= V; i++)
			graph.add(new ArrayList<>());
		E = Integer.parseInt(token[2]);
		token = br.readLine().split(" ");
		A = Integer.parseInt(token[0]);
		B = Integer.parseInt(token[1]);
		
		team = new int[N];
		token = br.readLine().split(" ");
		for(int i = 0; i < N; i++)
			team[i] = Integer.parseInt(token[i]);
		
		for(int i = 0; i < E; i++) {
			token = br.readLine().split(" ");
			int a = Integer.parseInt(token[0]);
			int b = Integer.parseInt(token[1]);
			int l = Integer.parseInt(token[2]);
			
			graph.get(a).add(new Node(b, l));
			graph.get(b).add(new Node(a, l));
		}
	}
	
	static void dijkstra(int start) {
		
		int[] dist = new int[V + 1];
		Arrays.fill(dist, INF);
		dist[start] = 0;
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0));
		
		while(!pq.isEmpty()) {
			Node curNode = pq.poll();
			if(curNode.value > dist[curNode.to]) continue;
			
			for(Node nextNode : graph.get(curNode.to)) {
				if(dist[nextNode.to] > nextNode.value + dist[curNode.to]) {
					dist[nextNode.to] = nextNode.value + dist[curNode.to];
					pq.add(nextNode);
				}
			}
		}
		
		for(int i = 0; i < N; i++) {
			int target = team[i];
			if(dist[target] == INF) result--;
			else result += dist[target];
		}
		
	}
}

/*
2 5 10
3 5
2 4
3 2 91
1 3 44
5 3 93
1 4 1
4 5 53
4 2 23
5 1 60
2 1 63
3 4 38
5 2 17

156
*/