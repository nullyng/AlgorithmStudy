package 게임닉네임;

import java.util.*;
import java.io.*;

class Node{
	Map<Character, Node> children = new HashMap<>();
	boolean isEnd;
	int count;
}

public class Main {
	
	static Node root = new Node();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		
		while(n-- > 0) {
			String line = br.readLine();
			Node curNode = root;
			StringBuilder sb = new StringBuilder();
			boolean print = false;
			for(int idx = 0; idx < line.length(); idx++) {
				char key = line.charAt(idx);
				sb.append(key);
				if(!curNode.children.containsKey(key)) {
					curNode.children.put(key, new Node());
					if(!print) {
						System.out.println(sb.toString());
						print = true;
					}
				}
				curNode = curNode.children.get(key);
			}
			
			if(curNode.isEnd) {
				if(!print)
					System.out.println(sb.toString() + (curNode.count + 1));
				curNode.count++;
			} else {
				if(!print)
					System.out.println(sb.toString());
				curNode.isEnd = true;
				curNode.count = 1;
			}
			
		}
	}
}
