import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner inputUser = new Scanner(System.in);

        System.out.println("Press Q to quit the game ");
        String quit = inputUser.next();
        if (quit.equals("q") || quit.equals("Q")){
            System.out.println("You Quit the game\n");
        }
        else {
            System.out.println("You still in the game");
        }
        String[] cars = {"Chevrolet","Corvette","BMW"};
        System.out.println(cars[2]);

        String name = "Tenshi";
        String result = name.replace('T','S');
        System.out.println(result);
    }
}
