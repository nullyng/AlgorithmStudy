package algo.week6.problem1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int M, N;
    static int[][] party;
    static boolean[] truth;
    static int[] parent;
    public static void main(String[] args) throws Exception{
        init();

        // 파티를 돌면서 union 형성
        for(int i = 0; i < party.length; i++) {
            for(int j = 0; j < party[i].length - 1; j++) {
                union(party[i][j], party[i][j + 1]);
            }
        }

        for(int i = 0; i <= N; i++) {
            if(truth[i])
                isTruth(i);
        }

        for(int i = 0; i < party.length; i++) {
            for(int j = 0; j < party[i].length; j++) {
                int parent = findParent(party[i][j]);
                if(truth[parent]) {
                    M--;
                    break;
                }
            }
        }
        System.out.println(M);

    }

    static int findParent(int num) {
        if(num == parent[num])
            return num;
        return parent[num] = findParent(parent[num]);
    }

    static void union(int left, int right) {
        int leftParent = findParent(left);
        int rightParent = findParent(right);
        if(leftParent != rightParent) {
            parent[leftParent] = rightParent;
        }
    }

    static void isTruth(int num) {
        int numParent = findParent(num);
        truth[numParent] = true;
    }

    static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] token = br.readLine().split(" ");
        N = Integer.parseInt(token[0]);
        M = Integer.parseInt(token[1]);
        party = new int[M][];
        parent = new int[N + 1];
        for(int i = 0; i <= N; i++) {
            parent[i] = i;
        }

        token = br.readLine().split(" ");

        truth = new boolean[N + 1];
        int count = Integer.parseInt(token[0]);
        for(int i = 0; i < count; i++) {
            truth[Integer.parseInt(token[i + 1])] = true;
        }

        for(int i = 0; i < M; i++) {
            token = br.readLine().split(" ");
            party[i] = new int[Integer.parseInt(token[0])];
            for(int j = 0; j < party[i].length; j++) {
                party[i][j] = Integer.parseInt(token[j + 1]);
            }
            Arrays.sort(party[i]);
        }
    }
}