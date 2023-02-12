package 다리만들기;

import java.util.*;
import java.io.*;

class Node{
    int x, y, seq;

    public Node(int x, int y, int seq) {
        this.x = x;
        this.y = y;
        this.seq = seq;
    }
}

public class Main {

    static int[][] map;
    static int N;
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};
    static List<Node> nodes = new ArrayList<>();
    static int result = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for(int i = 0; i < N; i++){
            String[] token = br.readLine().split(" ");
            for(int j = 0; j < N; j++)
                map[i][j] = Integer.parseInt(token[j]);
        }

        boolean[][] isVisit = new boolean[N][N];
        int seq = 1;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if (!isVisit[i][j] && map[i][j] != 0)
                    bfs(j, i, isVisit, seq++);

        for(int i = 0; i < nodes.size(); i++)
            for(int j = i + 1; j < nodes.size(); j++){
                if(nodes.get(i).seq != nodes.get(j).seq) {
                    result = Math.min(result, Math.abs(nodes.get(i).x - nodes.get(j).x) + Math.abs(nodes.get(i).y - nodes.get(j).y) - 1);
                }
            }

        System.out.println(result);
    }

    static void bfs(int startX, int startY, boolean[][] isVisit, int seq){
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(startX, startY, seq));
        isVisit[startY][startX] = true;

        while (!q.isEmpty()){
            Node curNode = q.poll();
            nodes.add(curNode);

            for(int dir = 0; dir < 4; dir++){
                int nextX = curNode.x + dx[dir];
                int nextY = curNode.y + dy[dir];
                if(0 <= nextX && nextX < N && 0 <= nextY && nextY < N && !isVisit[nextY][nextX] && map[nextY][nextX] != 0){
                    isVisit[nextY][nextX] = true;
                    map[nextY][nextX] = seq;
                    q.add(new Node(nextX, nextY, seq));
                }
            }
        }
    }
}