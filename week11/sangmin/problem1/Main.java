package algo.week11.별자리만들기;

import java.util.*;
import java.io.*;

class Star{
    double x, y;

    public Star(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

class Node implements Comparable<Node>{
    int A, B;
    double value;

    public Node(int A, int B, double value) {
        this.A = A;
        this.B = B;
        this.value = value;
    }

    @Override
    public int compareTo(Node o) {
        return Double.compare(this.value, o.value);
    }
}

public class Main {

    public static Star[] stars;
    public static int n;
    public static int[] parents;
    public static double result = 0;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n =  Integer.parseInt(br.readLine());
        stars = new Star[n];
        parents = new int[n];
        for(int i = 0; i < n; i++) {
            String[] token = br.readLine().split(" ");
            stars[i] = new Star(Double.parseDouble(token[0]), Double.parseDouble(token[1]));
            parents[i] = i;
        }

        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                pq.add(new Node(i, j, Math.sqrt( Math.pow(stars[i].x - stars[j].x, 2) + Math.pow(stars[i].y - stars[j].y, 2))));

        while(!pq.isEmpty()) {
            Node curNode = pq.poll();

            int aParent = findParent(curNode.A);
            int bParent = findParent(curNode.B);

            if(aParent != bParent) {
                parents[aParent] = parents[bParent];
                result += curNode.value;
            }
        }

        System.out.println(String.format("%.2f", result));

    }

    public static int findParent(int num) {
        if(parents[num] == num)
            return num;
        return parents[num] = findParent(parents[num]);
    }
}