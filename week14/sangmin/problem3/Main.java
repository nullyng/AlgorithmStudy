package 주사위;

import java.util.*;
import java.io.*;

class Dice{
	int A, B, C, D, E, F;
	int twoSideMin;
	int threeSideMin;
	int min;
	
	public Dice(int A, int B, int C, int D, int E, int F) {
		this.A = A;
		this.B = B;
		this.C = C;
		this.D = D;
		this.E = E;
		this.F = F;
		
		min = A;
		min = Math.min(B, min);
		min = Math.min(C, min);
		min = Math.min(D, min);
		min = Math.min(E, min);
		min = Math.min(F, min);
		
		twoSideMin = A + D;
		twoSideMin = Math.min(A + B, twoSideMin);
		twoSideMin = Math.min(A + E, twoSideMin);
		twoSideMin = Math.min(A + C, twoSideMin);
		
		twoSideMin = Math.min(B + D, twoSideMin);
		twoSideMin = Math.min(B + F, twoSideMin);
		twoSideMin = Math.min(B + C, twoSideMin);
		twoSideMin = Math.min(C + F, twoSideMin);
		twoSideMin = Math.min(C + E, twoSideMin);
		twoSideMin = Math.min(D + E, twoSideMin);
		twoSideMin = Math.min(D + F, twoSideMin);
		twoSideMin = Math.min(E + F, twoSideMin);
		
		threeSideMin = A + B + C;
		threeSideMin = Math.min(A + B + D, threeSideMin);
		threeSideMin = Math.min(A + D + E, threeSideMin);
		threeSideMin = Math.min(A + C + E, threeSideMin);
		threeSideMin = Math.min(D + E + F, threeSideMin);
		threeSideMin = Math.min(B + D + F, threeSideMin);
		threeSideMin = Math.min(C + B + F, threeSideMin);
		threeSideMin = Math.min(C + E + F, threeSideMin);
	}
}

public class Main {
	static long N;
	static Dice dice;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Long.parseLong(br.readLine());
		String[] token = br.readLine().split(" ");
		dice = new Dice(Integer.parseInt(token[0]), Integer.parseInt(token[1]), Integer.parseInt(token[2]), Integer.parseInt(token[3]), Integer.parseInt(token[4]), Integer.parseInt(token[5]));
		long result = 0L;
		
		if(N == 1) {
			System.out.println(dice.A + dice.B + dice.C + dice.D + dice.E + dice.F - Math.max(dice.A, Math.max(dice.B, Math.max(dice.C, Math.max(dice.D, Math.max(dice.E, dice.F))))));
			return;
		}
		
		result += (long) dice.threeSideMin * 4;
		result += (8 * N - 12) * (long) dice.twoSideMin;
		result += (5 * N * N - 16 * N + 12) * (long) dice.min;
		System.out.println(result);
	}
}
