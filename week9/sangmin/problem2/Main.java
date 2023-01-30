package 전화번호목록;

import java.util.*;
import java.io.*;

class Node{
	boolean isEnd;
	Node[] children = new Node[10];
}

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0) {
			Node root = new Node();
			int n = Integer.parseInt(br.readLine());
			boolean flag = true;
			while(n-- > 0) {
				String line = br.readLine();
				Node curNode = root;
				for(int idx = 0; idx < line.length(); idx++) {
					if(curNode.isEnd) flag = false;
					int num = line.charAt(idx) - '0';
					if(curNode.children[num] == null)
						curNode.children[num] = new Node();
					curNode = curNode.children[num];
				}
				curNode.isEnd = true;
				for(int idx = 0; idx < 10; idx++)
					if(curNode.children[idx] != null)
						flag = false;
			}
			System.out.println(flag ? "YES" : "NO");
		}
	}
}
/*
3
3
911
97625999
91125426
5
113
12340
123440
12345
98346
2
1234
123
*/