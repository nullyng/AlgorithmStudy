package 강의실배정;

import java.util.*;
import java.io.*;

class Class implements Comparable<Class> {
	int startTime, endTime;
	
	Class(int startTime, int endTime){
		this.startTime = startTime;
		this.endTime = endTime;
	}
	
	@Override
	public int compareTo(Class o) {
		return Integer.compare(this.endTime, o.endTime);
	}
}

public class Main {
	static int N;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Class> pq = new PriorityQueue<>();
		N = Integer.parseInt(br.readLine());
		Class[] classes = new Class[N];
		while(N-- > 0) {
			String[] token = br.readLine().split(" ");
			classes[N] = new Class(Integer.parseInt(token[0]), Integer.parseInt(token[1]));
		}
		
		Arrays.sort(classes, (o1, o2) -> {
			if(Integer.compare(o1.startTime, o2.startTime) == 0)
				return Integer.compare(o1.endTime, o2.endTime);
			return Integer.compare(o1.startTime, o2.startTime);
		});
		
		for(int i = 0; i < classes.length; i++) {
			if(!pq.isEmpty()) {
				if(pq.peek().endTime <= classes[i].startTime)
					pq.poll();
			}
			pq.add(classes[i]);
		}
		
		System.out.println(pq.size());
	}
}

/*
8
1 8
9 16
3 7
8 10
10 14
5 6
6 11
11 12
3

5
1 7
2 3
3 4
4 8
7 10
2

3
999999999 1000000000
999999998 999999999 
1 999999998

*/