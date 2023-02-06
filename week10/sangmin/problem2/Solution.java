package algo.week10.택배배달과수거하기;

import java.util.*;

class Solution {

    Stack<Integer> deliveries_stack = new Stack<>();
    Stack<Integer> pickups_stack = new Stack<>();

    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;

        for(int idx = 0; idx < n; idx++){
            if(deliveries[idx] != 0)
                deliveries_stack.push(idx);
            if(pickups[idx] != 0)
                pickups_stack.push(idx);
        }

        while(!deliveries_stack.isEmpty() || !pickups_stack.isEmpty()){
            int dist = 0;
            if(!deliveries_stack.isEmpty())
                dist = Math.max(dist, deliveries_stack.peek() + 1);
            if(!pickups_stack.isEmpty())
                dist = Math.max(dist, pickups_stack.peek() + 1);

            answer += dist;

            int deliveries_cap = 0;
            while(!deliveries_stack.isEmpty()){
                int cur_idx = deliveries_stack.pop();
                int cur_cap = deliveries[cur_idx];
                deliveries_cap += cur_cap;
                if(deliveries_cap == cap){
                    break;
                }else if(deliveries_cap > cap){
                    deliveries[cur_idx] = deliveries_cap - cap;
                    deliveries_stack.push(cur_idx);
                    break;
                }
            }

            int pickups_cap  = 0;
            while(!pickups_stack.isEmpty()){
                int cur_idx = pickups_stack.pop();
                int cur_cap = pickups[cur_idx];
                pickups_cap += cur_cap;
                if(pickups_cap == cap){
                    break;
                }else if(pickups_cap > cap){
                    pickups[cur_idx] = pickups_cap - cap;
                    pickups_stack.push(cur_idx);
                    break;
                }
            }
        }

        return answer * 2;
    }
}