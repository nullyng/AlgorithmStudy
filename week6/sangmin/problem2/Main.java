package algo.week6.problem2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Edge implements Comparable<Edge>{
    int h1, h2, value;

    public Edge(int h1, int h2, int value) {
        this.h1 = h1;
        this.h2 = h2;
        this.value = value;
    }

    @Override
    public int compareTo(Edge o) {
        return Integer.compare(o.value, this.value);
    }
}

class Node{
    int to, value;

    public Node(int to, int value) {
        this.to = to;
        this.value = value;
    }
}

public class Main {
    static int N, M, s, e;
    static int[] dist;
    static int[] parent;
    static boolean[] isVisit;
    static List<List<Node>> graph = new ArrayList<>();
    static PriorityQueue<Edge> pq = new PriorityQueue<>();
    public static void main(String[] args) throws Exception{
        init();
        makeMST();
        bfs();
        System.out.println(dist[e] == 1000001 ? 0 : dist[e]);
    }

    static void bfs(){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        isVisit = new boolean[N + 1];

        while (!queue.isEmpty()){
            Integer from = queue.poll();
            isVisit[from] = true;

            for (Node nexNode : graph.get(from)){
                if(!isVisit[nexNode.to]){
                    dist[nexNode.to] = Math.min(dist[from], nexNode.value);
                    queue.add(nexNode.to);
                }
            }
        }
    }

    static int findParent(int num){
        if(parent[num] == num)
            return num;
        return parent[num] = findParent(parent[num]);
    }

    static void makeMST(){
        while (!pq.isEmpty()){
            Edge curEdge = pq.poll();
            int firstParent = findParent(curEdge.h1);
            int secondParent = findParent(curEdge.h2);
            if(firstParent != secondParent){
                parent[firstParent] = secondParent;
                graph.get(firstParent).add(new Node(secondParent, curEdge.value));
                graph.get(secondParent).add(new Node(firstParent, curEdge.value));
            }
        }
    }

    static void init() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] token = br.readLine().split(" ");
        N = Integer.parseInt(token[0]);
        M = Integer.parseInt(token[1]);

        parent = new int[N + 1];
        dist = new int[N + 1];
        for(int i = 0; i <= N; i++){
            dist[i] = 1000001;
            parent[i] = i;
            graph.add(new ArrayList<>());
        }

        token = br.readLine().split(" ");
        s = Integer.parseInt(token[0]);
        e = Integer.parseInt(token[1]);

        for(int i = 0; i < M; i++){
            token = br.readLine().split(" ");
            int h1 = Integer.parseInt(token[0]);
            int h2 = Integer.parseInt(token[1]);
            int value = Integer.parseInt(token[2]);
            pq.add(new Edge(h1, h2, value));
        }
    }
}

/*
7 9
1 5
1 2 2
1 7 4
2 3 5
3 7 5
4 6 1
6 7 4
5 6 3
5 7 1
3 5 2
 */