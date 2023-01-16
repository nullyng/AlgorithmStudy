package 여행가자;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N, M;
    static int[][] map;
    static int[] parent;
    static boolean canVisit = true;
    public static void main(String[] args) throws Exception {
        init();
        System.out.println(canVisit ? "YES" : "NO");
    }

    static void init() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        parent = new int[N + 1];
        for(int i = 0; i <= N; i++)
            parent[i] = i;

        map = new int[N + 1][N + 1];
        for(int i = 1; i <= N; i++){
            String[] token = br.readLine().split(" ");
            for(int j = 1; j <= N; j++){
                map[i][j] = Integer.parseInt(token[j - 1]);
            }
        }

        makeUnion();

        String[] token = br.readLine().split(" ");
        for(int j = 0; j < token.length - 1; j++){
            if(findParent(Integer.parseInt(token[j])) != findParent(Integer.parseInt(token[j + 1])))
                canVisit = false;
        }
    }

    static void makeUnion(){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(map[i][j] == 1) {
                    int leftParent = findParent(i);
                    int rightParent = findParent(j);
                    if(leftParent != rightParent)
                        parent[leftParent] = rightParent;
                }
            }
        }
    }

    static int findParent(int num){
        if(parent[num] == num)
            return num;
        return parent[num] = findParent(parent[num]);
    }
}