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
        return Integer.compare(this.value, o.value);
    }
}

class Solution {

    int INF = 50 * 10000 + 1;
    int[] dist;
    PriorityQueue<Node> pq = new PriorityQueue<>();
    List<List<Node>> graph = new ArrayList<>();

    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        dist = new int[N + 1];
        Arrays.fill(dist, INF);
        dist[1] = 0;
        for(int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for(int[] edge : road){
            graph.get(edge[0]).add(new Node(edge[1], edge[2]));
            graph.get(edge[1]).add(new Node(edge[0], edge[2]));
        }

        pq.add(new Node(1, 0));

        while (!pq.isEmpty()){
            Node curNode = pq.poll();
            if(dist[curNode.to] < curNode.value) continue;

            for(Node nextNode : graph.get(curNode.to)){

                if(dist[nextNode.to] > dist[curNode.to] + nextNode.value){
                    dist[nextNode.to] = dist[curNode.to] + nextNode.value;
                    pq.add(nextNode);
                }
            }
        }

        for(int i = 1; i <= N; i++){
            if(dist[i] <= K) answer++;
        }

        return answer;
    }
}
