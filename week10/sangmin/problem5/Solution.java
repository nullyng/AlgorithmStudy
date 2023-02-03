package algo.week10.표병합;

import java.util.*;

class Cell{
    int parent;
    String value;
    public Cell(int parent){
        this.parent = parent;
    }
}

class Solution {

    Cell[] cells = new Cell[50 * 50];
    List<String> list = new ArrayList<>();

    public int findParent(int idx, Cell[] cells){
        if(cells[idx].parent == idx)
            return idx;
        return cells[idx].parent = findParent(cells[idx].parent, cells);
    }

    public String[] solution(String[] commands) {
        for(int idx = 0; idx < cells.length; idx++)
            cells[idx] = new Cell(idx);

        for(String command : commands){
            String[] token = command.split(" ");
            if(token[0].equals("UPDATE")){
                if(token.length == 4){
                    int y = Integer.parseInt(token[1]);
                    int x = Integer.parseInt(token[2]);
                    String value = token[3];
                    int idx = getIdx(x, y);
                    int parentIdx = findParent(idx, cells);
                    cells[parentIdx].value = value;
                }else{
                    String targetValue = token[1];
                    String updateValue = token[2];
                    for(int idx = 0; idx < cells.length; idx++)
                        if(targetValue.equals(cells[idx].value))
                            cells[idx].value = updateValue;
                }
            }else if(token[0].equals("MERGE")){
                int r1 = Integer.parseInt(token[1]);
                int c1 = Integer.parseInt(token[2]);
                int r2 = Integer.parseInt(token[3]);
                int c2 = Integer.parseInt(token[4]);


                int idx1 = getIdx(c1, r1);
                int idx2 = getIdx(c2, r2);
                int parentIdx1 = findParent(idx1, cells);
                int parentIdx2 = findParent(idx2, cells);

                if(parentIdx1 == parentIdx2)
                    continue;

                if(cells[parentIdx1].value != null && cells[parentIdx2].value != null){
                    for(int idx = 0; idx < cells.length; idx++)
                        if(cells[idx].parent == parentIdx2)
                            cells[idx].parent = parentIdx1;

                    cells[parentIdx2].parent = parentIdx1;
                    cells[parentIdx2].value = null;
                }else if(cells[parentIdx1].value == null){
                    for(int idx = 0; idx < cells.length; idx++)
                        if(cells[idx].parent == parentIdx1)
                            cells[idx].parent = parentIdx2;

                    cells[parentIdx1].parent = parentIdx2;
                    cells[parentIdx1].value = null;
                }else if(cells[parentIdx2].value == null){
                    for(int idx = 0; idx < cells.length; idx++)
                        if(cells[idx].parent == parentIdx2)
                            cells[idx].parent = parentIdx1;

                    cells[parentIdx2].parent = parentIdx1;
                    cells[parentIdx2].value = null;
                }

            }else if(token[0].equals("UNMERGE")){
                int r = Integer.parseInt(token[1]);
                int c = Integer.parseInt(token[2]);
                int targetIdx = getIdx(c, r);
                int parentIdx = findParent(targetIdx, cells);
                String value = cells[parentIdx].value;

                for(int idx = 0; idx < cells.length; idx++)
                    if(cells[idx].parent == parentIdx){
                        cells[idx].parent = idx;
                        cells[idx].value = null;
                    }

                cells[targetIdx].value = value;

            }else{
                int r = Integer.parseInt(token[1]);
                int c = Integer.parseInt(token[2]);
                int idx = getIdx(c, r);
                int parentIdx = findParent(idx, cells);
                list.add(cells[parentIdx].value == null ? "EMPTY" : cells[parentIdx].value);
            }
        }
        String[] answer = new String[list.size()];
        for(int idx = 0; idx < list.size(); idx++)
            answer[idx] = list.get(idx);
        return answer;
    }

    int getX(int idx){
        return idx % 50 + 1;
    }

    int getY(int idx){
        return idx / 50 + 1;
    }

    int getIdx(int x, int y){
        return (y - 1) * 50 + (x - 1);
    }
}