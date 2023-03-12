package algo.week12.큰수만들기;

class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder();

        int length = number.length() - k;
        int curIdx = 0;

        for(int idx = 0; idx < length; idx++){
            int max = Integer.MIN_VALUE;
            for(int nextIdx = curIdx; nextIdx < number.length() - (length - idx - 1); nextIdx++){
                if(number.charAt(nextIdx) - '0' > max){
                    max = number.charAt(nextIdx) - '0';
                    curIdx = nextIdx + 1;
                }
            }
            sb.append(max);
        }

        return sb.toString();
    }
}