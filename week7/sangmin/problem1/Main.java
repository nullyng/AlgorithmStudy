package algo.week7.problem1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

class Node implements Comparable<Node>{
    int y, x, wall;

    public Node(int y, int x, int wall) {
        this.y = y;
        this.x = x;
        this.wall = wall;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.wall, o.wall);
    }
}

public class Main {

    static int[][] map;
    static boolean[][] isVisit;
    static int N, M;
    static int[] dx = {0, 0, -1 , 1};
    static int[] dy = {-1, 1, 0, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] token = br.readLine().split(" ");
        M = Integer.parseInt(token[0]);
        N = Integer.parseInt(token[1]);

        map = new int[N + 1][M + 1];
        isVisit = new boolean[N + 1][M + 1];

        for(int i = 1; i <= N; i++){
            String line = br.readLine();
            for(int j = 1; j <= M; j++){
                map[i][j] = line.charAt(j - 1) - '0';
            }
        }
        dijkstra();
    }

    public static void dijkstra(){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(1, 1, 0));
        isVisit[1][1] = true;

        while (!pq.isEmpty()){
            Node curNode = pq.poll();
            if(curNode.y == N && curNode.x == M){
                System.out.println(curNode.wall);
                return;
            }
            for(int dir = 0; dir < 4; dir++){
                int nextY = curNode.y + dy[dir];
                int nextX = curNode.x + dx[dir];
                if(0 < nextX && nextX <= M && 0 < nextY && nextY <= N && !isVisit[nextY][nextX]){
                    isVisit[nextY][nextX] = true;
                    if(map[nextY][nextX] == 1)
                        pq.add(new Node(nextY, nextX, curNode.wall + 1));
                    else
                        pq.add(new Node(nextY, nextX, curNode.wall));
                }
            }
        }
    }
}

/*

6 6
001111
010000
001111
110001
011010
100010

2
 */