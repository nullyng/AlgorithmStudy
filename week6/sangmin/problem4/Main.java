package 집합의표현;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int[] parent;
    static int n, m;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] token = br.readLine().split(" ");
        n = Integer.parseInt(token[0]);
        m = Integer.parseInt(token[1]);
        
        parent = new int[n + 1];
        for(int i = 0 ; i <= n; i++) {
        	parent[i] = i;
        }
        
        while(m-- > 0) {
        	token = br.readLine().split(" ");
    		int left = Integer.parseInt(token[1]);
    		int right = Integer.parseInt(token[2]);
        	if(token[0].equals("1")) {
        		System.out.println(findParent(left) == findParent(right) ? "YES" : "NO");
        	}else {
        		parent[findParent(left)] = findParent(right);
        	}
        }
    }
    
   
    static int findParent(int num){
        if(parent[num] == num)
            return num;
        return parent[num] = findParent(parent[num]);
    }
}