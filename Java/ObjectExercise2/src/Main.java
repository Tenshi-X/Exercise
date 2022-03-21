import java.util.Scanner;

public class Main {
    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        Animal animal;
        System.out.println("Choose 1 \n (Dog = 1 ) / (Cat = 2 )");
        int choose = scanner.nextInt();

        if(choose == 1){
            animal = new Dog();
            animal.Speak();
        }
        else if(choose == 2){
            animal = new Cat();
            animal.Speak();
        }
        else{
            animal = new Animal();
            animal.Speak();
            System.out.println("Your input is wrong");
        }
    }
}
