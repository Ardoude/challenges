/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 15/03/2018 17:34:01
Ordem de Complexidade:
*******************************************************************************/

import java.util.Scanner;

public class j2718 {
    public static int testaLamp(int n,String b){
        int seq=0,aux=0,aux2=b.length()-1;  
        int vet[] = new int [aux2+1];
        
        for(int i=0;i<=aux2;i++){
            vet[i]=b.charAt(i);
        }

        for(int i=0;i<=aux2;i++){            
            if(vet[i]==49){
                aux++;
            }
            else{
                if(aux>seq){
                    seq=aux;
                }
                aux=0;               
            }         
        }

        if(aux>seq)
           seq=aux;
        return seq;
    }
    
    public static void main(String[] args) {
        int n;
        long x;
        String b;

        Scanner in = new Scanner(System.in);

        n=in.nextInt();
        int[] ret = new int[n];

        for(int i=0;i<n;i++){
            x=in.nextLong();
            b=Long.toBinaryString(x);
            ret[i]=testaLamp(n,b);
        }

        for(int i=0;i<n;i++)
            System.out.println(ret[i]);
        }    
}