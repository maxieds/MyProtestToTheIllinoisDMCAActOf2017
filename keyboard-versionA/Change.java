// **********************************************
// *                                            *
// *  Change.java                               *
// *                                            *
// *  Program to calculate total monetary value * 
// *   of some change, given the number of each *
// *   kind of coin.                            * 
// *                                            *
// *  Written February 2003 by Jason Zych       *
// *                                            *
// **********************************************

public class Change
{
   public static void main(String[] args)
   {
      int numQuarters, numDimes, numNickels, numPennies; 
      int totalCoins, totalCents, cents, dollars;

      // greeting
      System.out.println("Welcome to the change calculator!");

      // prompts and input
      System.out.print("Enter the number of quarters: ");
      numQuarters = Keyboard.readInt();
      System.out.print("Enter the number of dimes: ");
      numDimes = Keyboard.readInt();
      System.out.print("Enter the number of nickels: ");
      numNickels = Keyboard.readInt();
      System.out.print("Enter the number of pennies: ");
      numPennies = Keyboard.readInt();

      // calculation of relevant values
      totalCoins = numQuarters + numDimes + numNickels + numPennies;
      totalCents = 25*numQuarters + 10*numDimes + 5*numNickels + numPennies;
      dollars = totalCents / 100;
      cents = totalCents % 100;
      totalCoins = numQuarters + numDimes + numNickels + numPennies;

 
      // screen output 
      System.out.println("There were " + totalCoins + " coins in all.");
      System.out.println("Their value is " + dollars + " dollars and "
                                               + cents + " cents.");
 
   }
}


