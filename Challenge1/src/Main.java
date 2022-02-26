import java.util.Scanner;

public class Main {
    public static void main(String[] args){
    Patient patient1 = new Patient("Tom",25,new Eye(),new Stomach("PUD"),new Skin("Burned"),new Heart(65));
    Scanner inputUser = new Scanner(System.in);
    int choose;

        System.out.println("Name : " + patient1.name);
        System.out.println("Age : " + patient1.age);

        int i = 0;
        while(i == 0){
            System.out.println("Choose an Organ");
            System.out.println("1. Left eye");
            System.out.println("2. Right Eye");
            System.out.println("3. Heart");
            System.out.println("4. Stomach");
            System.out.println("5. Skin");
            System.out.println("6. Quit");
            System.out.print("Input = ");
            choose = inputUser.nextInt();
            if(choose == 1){
                patient1.eye.RightEye();
            }
            else if(choose == 2){
                patient1.eye.LeftEye();
            }
            else if(choose == 3){
                System.out.print("BPM : ");
                System.out.println(patient1.heart.bpm);
                System.out.print("Change BPM to : ");
                patient1.heart.bpm = inputUser.nextInt();
                System.out.println("BPM : " +  patient1.heart.bpm);
            }
            else if(choose == 4){
                System.out.println("Stomach Condition : " + patient1.stomach.condition("PUD"));
                patient1.stomach.digest();
            }
            else if(choose == 5){
                System.out.println("Skin Condition : " + patient1.skin.condition("Burned"));
            }
            else if(choose == 6){
                i++;
            }
            else{
                System.out.println("Input Doesn't Exist");
            }
        }
    }
}
