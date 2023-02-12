package backjoon.연구소3;

import java.util.*;
import java.io.*;

class Virus{
    int x, y, time;

    public Virus(int x, int y, int time) {
        this.x = x;
        this.y = y;
        this.time = time;
    }
}

public class Main {

    static int N, M;
    static int[][] map;
    static List<Virus> virusList = new ArrayList<>();
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};
    static int empty = 0;
    static int result = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] token = br.readLine().split(" ");
        N = Integer.parseInt(token[0]);
        M = Integer.parseInt(token[1]);
        map = new int[N][N];
        for(int i = 0; i < N; i++){
            token = br.readLine().split(" ");
            for(int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(token[j]);
                if(map[i][j] == 2)
                    virusList.add(new Virus(j, i, 0));
                if(map[i][j] == 0)
                    empty++;
            }
        }
        search(0, new ArrayList<>());
        System.out.println(result == Integer.MAX_VALUE ? -1 : result);
    }

    static void search(int depth, List<Virus> list){
        if(list.size() == M) {
            bfs(list);
            return;
        }

        for(int i = depth; i < virusList.size(); i++) {
            list.add(virusList.get(i));
            search(i + 1, list);
            list.remove(virusList.get(i));
        }
    }

    static void bfs(List<Virus> list){
        int count = 0;
        int max = 0;
        boolean[][] isVisit = new boolean[N][N];
        Queue<Virus> q = new LinkedList<>();
        for(Virus v : list){
            q.add(v);
            isVisit[v.y][v.x] = true;
        }

        while (!q.isEmpty()){
            Virus curVirus = q.poll();
            if(map[curVirus.y][curVirus.x] == 0) {
                max = Math.max(max, curVirus.time);
                count++;
            }
            for(int dir = 0; dir < 4; dir++){
                int nextX = curVirus.x + dx[dir];
                int nextY = curVirus.y + dy[dir];

                if(0 <= nextX && nextX < N && 0 <= nextY && nextY < N && !isVisit[nextY][nextX] && map[nextY][nextX] != 1){
                    isVisit[nextY][nextX] = true;
                    q.add(new Virus(nextX, nextY, curVirus.time + 1));
                }
            }
        }
        if(count == empty)
            result = Math.min(result, max);
    }
}

/*
5 1
0 2 2 2 2
0 1 2 2 2
0 1 2 2 2
0 1 2 2 2
0 1 2 2 1

4 4
1 1 1 1
1 2 2 1
1 2 2 1
1 1 1 1
 */