package 소문난칠공주;

import java.io.*;
import java.util.*;

public class Main {

    static String[] map = new String[5];
    static int result = 0;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 5; i++)
            map[i] = br.readLine();
        search(0, 0, 0, new int[7], 0);
        System.out.println(result);
    }

    static void search(int idx, int yCount, int sCount, int[] list, int depth){

        if(yCount >= 4) return;

        if(yCount + sCount == 7){


            // 인접 조건
            Queue<Integer> q = new LinkedList<>();
            q.add(list[0]);
            boolean[] isVisit = new boolean[7];
            isVisit[0] = true;
            while (!q.isEmpty()){
                int cur = q.poll();

                for(int i = 0; i < list.length; i++){
                    if(isAdjustIdx(cur, list[i]) && !isVisit[i]) {
                        isVisit[i] = true;
                        q.add(list[i]);
                    }
                }
            }

            for(boolean visit : isVisit)
                if(!visit)
                    return;
            if(sCount >= 4)
                result++;
            return;
        }

        for(int i = idx; i < 25; i++){
            list[depth] = i;
            if(map[getY(i)].charAt(getX(i)) == 'Y')
                search(i + 1, yCount + 1, sCount, list, depth + 1);
            else
                search(i + 1, yCount, sCount + 1, list, depth + 1);
        }
    }

    static boolean isAdjustIdx(int first, int second){
        int firstX = getX(first);
        int firstY = getY(first);
        int secondX = getX(second);
        int secondY = getY(second);
        if(Math.abs(firstX - secondX) + Math.abs(firstY - secondY) == 1) return true;
        return false;
    }

    static int getX(int idx){
        return idx % 5;
    }

    static int getY(int idx){
        return idx / 5;
    }
}