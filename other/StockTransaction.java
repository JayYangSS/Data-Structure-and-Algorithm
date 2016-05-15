package com.Alibaba;

import java.util.ArrayList;
import java.util.List;

public class StockTransaction {
    
    //you were only permitted to complete at most one transaction，get the max profit
    public int maxProfit(int[] prices) {
        int size=prices.length;
        if(size==0)return 0;
        int currentPrice=prices[0];
        int res=0;
        
        for(int i=0;i<size;i++){
            if(res<prices[i]-currentPrice){
                res=prices[i]-currentPrice;
            }
            if(currentPrice>prices[i]){
                currentPrice=prices[i];
            }
        }
        return res;
    }
    
    //Alibaba interview, get the best buy and Sell Point to get maxProfit
    public List<Integer> bestBuySellPoint(int[] prices) {
        int size=prices.length;
        if(size==0)return null;
        int currentPrice=prices[0];
        int buyPoint=0,sellPoint=0;
        int tmpBuy=0,tmpSell=0;
        int res=0;
        
        for(int i=0;i<size;i++){
            if(res<prices[i]-currentPrice){
                res=prices[i]-currentPrice;
                tmpSell=i;  
            }
            if(currentPrice>prices[i]){
                //save the best strategy
                buyPoint=tmpBuy;
                sellPoint=tmpSell;
                //set new strategy
                currentPrice=prices[i];
                tmpBuy=i;
                tmpSell=i;
            }
            if(tmpBuy!=tmpSell){
                buyPoint=tmpBuy;
                sellPoint=tmpSell;
            }
        }
       
        List<Integer> result=new ArrayList<Integer>();
        result.add(buyPoint);
        result.add(sellPoint);
        return result;
    }
    
    public static void main(String []args){
        StockTransaction stockTransaction=new StockTransaction();
        int []stockPrice={1,3,5,2,7};
        List<Integer> result=stockTransaction.bestBuySellPoint(stockPrice);
        System.out.println("buy point:"result.get(0)+"  sell point:"+result.get(1));
    }
    
}
