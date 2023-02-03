package algo.week10.이모티콘할인행사;

import java.util.*;

class Solution {

    int subscriber = Integer.MIN_VALUE;
    int value = Integer.MIN_VALUE;
    int[] discount_rates = {10, 20, 30, 40};

    public int[] solution(int[][] users, int[] emoticons) {

        calDiscount(new int[emoticons.length], emoticons, users, 0);

        int[] answer = {subscriber, value};

        return answer;
    }

    void calDiscount(int[] discount, int[] emoticons, int[][] users, int depth){
        if(depth == emoticons.length){
            int emoticon_plus_count = 0;
            int total_sum = 0;

            for(int[] user : users){
                int sum = 0;
                for(int i = 0; i < discount.length; i++){
                    if(user[0] <= discount[i])
                        sum += ((100 - discount[i]) * emoticons[i] / 100);
                }
                if(sum >= user[1])
                    emoticon_plus_count++;
                else
                    total_sum += sum;
            }

            if(emoticon_plus_count > subscriber){
                subscriber = emoticon_plus_count;
                value = total_sum;
            }else if(emoticon_plus_count == subscriber){
                value = Math.max(value, total_sum);
            }
            return;
        }

        for(int rates = 0; rates < discount_rates.length; rates++){
            discount[depth] = discount_rates[rates];
            calDiscount(discount, emoticons, users, depth + 1);
        }
    }
}