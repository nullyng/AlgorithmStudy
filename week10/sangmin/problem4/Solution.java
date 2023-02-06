package algo.week10.표현가능한이진트리;

import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];
        int idx = 0;
        for(long number : numbers){
            String str = Long.toBinaryString(number);
            long num = (long) (Math.log(str.length()) / Math.log(2)) + 1;
            StringBuilder sb = new StringBuilder();
            while(sb.length() + str.length() < (long) Math.pow(2, num) - 1){
                sb.append('0');
            }
            sb.append(str);
            answer[idx++] = div(sb.toString()) ?  1 : 0;
        }
        return answer;
    }

    public boolean div(String str){
        if(str.length() == 1) return true;

        int mid = (str.length() - 1) / 2;

        String left = str.substring(0, mid);
        String right = str.substring(mid + 1, str.length());

        if(str.charAt(mid) == '0' && (left.charAt((left.length() - 1) / 2) == '1' || right.charAt((right.length() - 1) / 2) == '1')){
            return false;
        }

        return div(left) && div(right);
    }
}