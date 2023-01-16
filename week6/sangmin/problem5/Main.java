package 친구비;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int N, M, k;
	static int[] value;
	static int[] parent;
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String[] token = br.readLine().split(" ");
    	N = Integer.parseInt(token[0]);
    	M = Integer.parseInt(token[1]);
    	k = Integer.parseInt(token[2]);
    	value = new int[N + 1];
    	parent = new int[N + 1];
    	token = br.readLine().split(" ");
    	
    	for(int i = 1; i <= N; i++) {
    		parent[i] = i;
    		value[i] = Integer.parseInt(token[i - 1]);
    	}
    	

    	
    	for(int i = 0; i < M; i++) {
    		token = br.readLine().split(" ");
    		int left = Integer.parseInt(token[0]);
    		int right = Integer.parseInt(token[1]);
    		setUnion(left, right);
    	}
    	
    	int total = 0;
    	for(int i = 1; i <= N; i++) {
    		if(parent[i] == i)
    			total += value[i];
    	}
    	
    	System.out.println(k < total ? "Oh no" : total);
    	
    }    
    
    static void setUnion(int left, int right) {
    	int leftParent = findParent(left);
    	int rightParent = findParent(right);
    	if(leftParent == rightParent) return;
    	
    	if(value[leftParent] > value[rightParent])
    		parent[leftParent] = rightParent;
    	else
    		parent[rightParent] = leftParent;
    }
    
    static int findParent(int num) {
    	if(parent[num] == num)
    		return num;
    	return parent[num] = findParent(parent[num]);
    }
}