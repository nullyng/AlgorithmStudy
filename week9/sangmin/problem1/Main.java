package 생태학;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Node{
	Map<Character, Node> child = new HashMap<>(); 
	boolean isEnd;
	int count;

}

public class Main {
	
	static Node root = new Node();
	static int total = 0;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = null;
		while(true) {
			line = br.readLine();
			if(line == null || line.length() == 0) break;
			total++;
			insert(line);
		}
		getCount(0, new char[32], root);
	}
	
	static void insert(String word) {
		Node curNode = root;
		for(int idx = 0; idx < word.length(); idx++) {
			char ch = word.charAt(idx);
			
			if(!curNode.child.containsKey(ch))
				curNode.child.put(ch, new Node());
			curNode = curNode.child.get(ch);
		}
		curNode.count++;
		curNode.isEnd = true;
	}
	
	static void getCount(int depth, char[] word, Node curNode) {
		if(curNode.isEnd == true) {
			for(int idx = 0; idx < depth; idx++) {
				System.out.print(word[idx]);
			}
			System.out.println(" " + String.format("%.4f", (double) curNode.count / total * 100));
		}
		
		List<Character> key = new ArrayList<>(curNode.child.keySet());
		
		Collections.sort(key);
		
		for(char ch : key) {
			word[depth] = ch;
			getCount(depth + 1, word, curNode.child.get(ch));
		}
	}
}

/*
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAB
A%
*/
