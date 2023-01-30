import java.util.*;

class Solution {
    
    Map<String, Integer> map = new HashMap<>();
    List<Integer> result = new ArrayList<>();
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        String[] token = today.split("\\.");
        int year = Integer.parseInt(token[0]);
        int month = Integer.parseInt(token[1]);
        int day = Integer.parseInt(token[2]);
        
        int days = (year * 28 * 12) + (month * 28) + day;
        for(int i = 0; i < terms.length; i++){
            token = terms[i].split(" ");
            map.put(token[0], Integer.parseInt(token[1]));
        }
        
        for(int i = 0; i < privacies.length; i++){
            token = privacies[i].split(" ");
            int privacies_month = map.get(token[1]);
            
            token = token[0].split("\\.");
            year = Integer.parseInt(token[0]);
            month = Integer.parseInt(token[1]) + privacies_month;
            day = Integer.parseInt(token[2]);
            
            int privacies_days = (year * 28 * 12) + (month * 28) + day - 1;
            
            if(days > privacies_days)
                result.add(i + 1);
        }
        System.out.println(result.size());
        int[] answer = new int[result.size()];
        for(int i = 0; i < answer.length; i++)
            answer[i] = result.get(i);
    
        return answer;
    }
}