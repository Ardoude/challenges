/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 22/03/2018 22:26:18
Ordem de Complexidade:
*******************************************************************************/

import java.io.IOException;
import java.util.Scanner;

public class j2721 {
    public static void main(String[] args) throws IOException {
      int soma=0,r;

      Scanner in= new Scanner(System.in);
      
      for (int x=0;x<=8;x++){
          soma+=in.nextInt();
      }

      r=soma%9;
        switch(r){
            case 1:
                System.out.println("Dasher");  
                break;
            case 2:
                System.out.println("Dancer");
                break;
            case 3:
                System.out.println("Prancer");
                break;
            case 4:
                System.out.println("Vixen");
                break;
            case 5:
                System.out.println("Comet");
                break;
            case 6:
                System.out.println ("Cupid");
                break;
            case 7:
                System.out.println("Donner");
                break;
            case 8:
                System.out.println("Blitzen");
                break;
            case 0:
                System.out.println ("Rudolph");
                break;
        }
    }   
}