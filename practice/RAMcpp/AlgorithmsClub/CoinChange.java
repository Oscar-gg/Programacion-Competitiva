package SolvedProblems.Easy.AlgorithmsClub;
import java.util.*;

public class CoinChange {
    public int coinChange(int[] coins, int amount) {
        int memo[] = new int[amount+1];
        
        Arrays.sort(coins);
        
        Arrays.fill(memo, Integer.MAX_VALUE-1);
        
        memo[0] = 0;
        
        for (int i = 1; i <= amount; i++){
            
            for (int x = 0; x < coins.length; x++){            
                if (i - coins[x] >= 0){
                    memo[i] = Math.min(memo[i], memo[i-coins[x]] + 1);
                } else {
                    break;
                }  
            }
        }
        
        return (memo[amount] < Integer.MAX_VALUE - 1) ? memo[amount]: -1;
        
    }
}