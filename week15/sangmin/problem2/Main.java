package algo.week15.직사각형으로나누기;

import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] map;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] token = br.readLine().split(" ");
        N = Integer.parseInt(token[0]);
        M = Integer.parseInt(token[1]);
        map = new int[N][M];

        for(int i = 0; i < N; i++){
            String line = br.readLine();
            for(int j = 0; j < M; j++)
                map[i][j] = line.charAt(j) - '0';
        }

        long result = 0;
        for(int i = 0; i < N; i++)
            result = Math.max(result, divRow(i));
        for(int i = 0; i < M; i++)
            result = Math.max(result, divCol(i));

        int[][] copyMap = new int[N][M];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                copyMap[i][j] = map[N - 1 - i][M - 1 - j];

        for(int i = 0; i < N; i++)
            map[i] = Arrays.copyOf(copyMap[i], copyMap[i].length);

        for(int i = 0; i < N; i++)
            result = Math.max(result, divRow(i));
        for(int i = 0; i < M; i++)
            result = Math.max(result, divCol(i));
        System.out.println(result);
    }

    static long divRow(int length){
        long result = 0;
        long sum = calcSquareSize(0, 0, M, length);

        for(int x = 0; x < M; x++){
            long a = calcSquareSize(0, length, x, N);
            long b = calcSquareSize(x, length, M, N);
            result = Math.max(result, sum * a * b);
        }

        for(int y = 0; y + length < N; y++){
            long a = calcSquareSize(0, length, M, length + y);
            long b = calcSquareSize(0, length + y, M, N);
            result = Math.max(result, sum * a * b);
        }

        return result;
    }

    static long divCol(int length){
        long result = 0;
        long sum = calcSquareSize(0, 0, length, N);

        for(int y = 0; y < N; y++){
            long a = calcSquareSize(length, 0, M, y);
            long b = calcSquareSize(length, y, M, N);
            result = Math.max(result, sum * a * b);
        }

        for(int x = 0; x + length < M; x++){
            long a = calcSquareSize(length, 0, length + x, N);
            long b = calcSquareSize(length + x, 0, M, N);
            result = Math.max(result, sum * a * b);
        }

        return result;
    }


    static long calcSquareSize(int startX, int startY, int endX, int endY){
        int sum = 0;
        for(int y = startY; y < endY; y++)
            for(int x = startX; x < endX; x++) {
                sum += map[y][x];
            }
        return sum;
    }
}
