package 저울;

import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[][] dist;
    static int[] result;
    static final int INF = 100 * 100 + 1;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dist = new int[N + 1][N + 1];
        result = new int[N + 1];
        for(int i = 0; i <= N; i++)
            Arrays.fill(dist[i], INF);

        M = Integer.parseInt(br.readLine());

        while (M-- > 0){
            String[] token = br.readLine().split(" ");
            dist[Integer.parseInt(token[0])][Integer.parseInt(token[1])] = 1;
        }

        for(int mid = 1; mid <= N; mid++)
            for(int from = 1; from <= N; from++)
                for(int to = 1; to <= N; to++)
                    dist[from][to] = Math.min(dist[from][to], dist[from][mid] + dist[mid][to]);

        for(int i = 1; i <= N; i++) {
            int count = 0;
            for (int j = 1; j <= N; j++) {
                if(dist[i][j] != INF){
                    count++;
                    result[j]++;
                }
            }
            result[i] += count; // i보다 무게 작은 애들
        }

        for(int i = 1; i <= N; i++)
            System.out.println(N - result[i] - 1);
    }
}