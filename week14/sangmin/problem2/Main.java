package 사분면;

import java.util.*;
import java.io.*;

public class Main {
	static int d;
	static long initX, initY, moveX, moveY;
	static String number;
	static String result;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token = br.readLine().split(" ");
		d = Integer.parseInt(token[0]);
		number = token[1];
		token = br.readLine().split(" ");
		moveX = Long.parseLong(token[0]);
		moveY = Long.parseLong(token[1]);
		
		long length = (long) Math.pow(2, d);
		calcInit(0, 0, 0, length);
		initX += moveX;
		initY += -1 * moveY;
		
		if(initX < 0 || initX >= length || initY < 0 || initY >= length) {
			System.out.println(-1);
			return;
		}
		calcResult(0, initX, initY, length, "");
		
		System.out.println(result);
	}
	
	public static void calcInit(int depth, long x, long y, long length) {
		if(depth == d) {
			initX = x;
			initY = y;
			return;
		}
		
		if(number.charAt(depth) == '1')
			x += length / 2;
		else if(number.charAt(depth) == '3')
			y += length / 2;
		else if(number.charAt(depth) == '4') {
			x += length / 2;
			y += length / 2;
		}
		calcInit(depth + 1, x, y, length /2);
	}
	
	public static void calcResult(int depth, long x, long y, long length, String num) {
		if(depth == d) {
			result = num;
			return;
		}
		
		if(x >= length / 2 && y >= length / 2) {
			calcResult(depth + 1, x - length / 2, y - length / 2, length / 2, num + "4");
		}else if(x >= length / 2) {
			calcResult(depth + 1, x - length / 2, y, length / 2, num + "1");
		}else if(y >= length / 2) {
			calcResult(depth + 1, x, y - length / 2, length / 2, num + "3");
		}else {
			calcResult(depth + 1, x, y, length / 2, num + "2");
		}
	}
}


/*
341이라는 건
3 사분면이기 때문에 최소
x = 0, y = 4 // 한 변의 길이 8

그 중 4 분면이기 때문에 최소
x = 2, y = 6 // 한 변의 길이 4

그 중 1 분면이기 때문에 최소
x = 3, y = 6 // 한 변의 길이 2


여기서 x = 2, y = -1 이동
x = 5, y = 5


x = 5, y = 5 // 한 변의 길이가 8에서 절반 초과이기 때문에 4 사분면
x = 1, y = 1 // 한 변의 길이가 4에서 둘 다 절반 이하 이기 때문에 2 사분면



4 사분면이면 x, y 둘 다 절반 길이를 빼주고
1 사분면이면 x 에 절반 길이를 빼줌
2 사분면이면 그대로
3 사분면이면 y 에 절반 길이 뺴줌

 */