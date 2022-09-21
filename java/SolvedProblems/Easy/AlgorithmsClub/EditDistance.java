package SolvedProblems.Easy.AlgorithmsClub;
public class EditDistance {
    public int minDistance(String word1, String word2) {
        
        char[] w2 = word2.toCharArray();
        char[] w1 = word1.toCharArray();
       
        int[][] possible = new int[w2.length + 1][w1.length + 1];
        
        for (int i = 0; i < possible[0].length; i++){
            possible[0][i] = i;
        }
        
        for (int i = 1; i < possible.length; i++){
            possible[i][0] = i;
        }
        
        for(int i = 1; i <= w2.length; i++){
            for (int x = 1; x <= w1.length; x++){
                if (w2[i-1] == w1[x-1]){
                    possible[i][x] = possible[i-1][x-1];
                } else {
                    possible[i][x] = (int) Math.min(
                                Math.min(possible[i-1][x], possible[i-1][x-1]),
                                          possible[i][x-1]) 
                                          + 1;
                }   
            }
            
        }
        
        return possible[w2.length][w1.length];
    }
    
}