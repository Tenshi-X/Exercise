import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner inputUser = new Scanner(System.in);
        ArrayList<Contact> contacts = new ArrayList<>();
        ArrayList<Messages> messages = new ArrayList<>();
        int choose1, choose2, backMenu = 1, manyContact;
        String backmenu1 = " ";

        System.out.println("Hello There!!" + "\n");
        do{
            backMenu--;
        System.out.println("Menu");
        System.out.println("1. Manage Contacts");
        System.out.println("2. Messages");
        System.out.println("3. Quit");
        System.out.print("Input = ");
        choose1 = inputUser.nextInt();
        if(choose1 == 1){
            do{
            System.out.println("1. Show all contacts");
            System.out.println("2. Add a new contact");
            System.out.println("3. Search for a contact");
            System.out.println("4. Delete a contact");
            System.out.println("5. Go back to the previous menu");
            System.out.print("Input = ");
            choose2 = inputUser.nextInt();
            if(choose2 == 1){
                for(Contact c: contacts){
                    c.getDetails();
                }
                System.out.print("Back to previous menu?(y/Y) ");
                backmenu1 = inputUser.next();
                }
            else if(choose2 == 2){
            System.out.println("How many contacts do you want to input? ");
            System.out.print("Input = ");
            manyContact = inputUser.nextInt();
            for(int i = 0;i < manyContact;i++){
                System.out.print("Name = ");
                String name = inputUser.next();
                System.out.print("Number = ");
                int number = inputUser.nextInt();
                System.out.print("Email = ");
                String email  = inputUser.next();
                Contact contact = new Contact(name,number,email);
                contacts.add(contact);
            }
            System.out.print("Back to previous menu?(y/Y) ");
            backmenu1 = inputUser.next();
            }
            else if(choose2 == 3){
                System.out.print("Please enter the contact name = ");
                String name = inputUser.next();
                for(Contact c:contacts){
                    if(c.getName().equals(name)){
                        c.getDetails();
                    }
                    else{
                        System.out.println("This contact doesn't exist in your phone");
                    }
                }
                System.out.print("Back to previous menu?(y/Y) ");
                backmenu1 = inputUser.next();
            }
            else if(choose2 == 4){
                System.out.print("Please enter the contact name = ");
                String name = inputUser.next();
                contacts.removeIf(c -> c.getName().equals(name));
                System.out.print("Back to previous menu?(y/Y) ");
                backmenu1 = inputUser.next();
            }
            else if(choose2 == 5){
            backMenu++;
            }
            else{
                System.out.println("Input Doesn't Exist");
            }}while(backmenu1.equals("Y") || backmenu1.equals("y"));
        }
        else if(choose1 == 2){
            do{
            System.out.println("1. See the list of all messages");
            System.out.println("2. Send a new message");
            System.out.println("3. Go back to the previous menu");
            System.out.print("Input = ");
            choose2 = inputUser.nextInt();
            if(choose2 == 1){
                for(Messages m:messages){
                    m.getDetails();
                }
                System.out.print("Back to previous menu?(y/Y) ");
                backmenu1 = inputUser.next();
            }
            else if(choose2 == 2){
                System.out.print("Enter ID = ");
                int id = inputUser.nextInt();
                System.out.print("Enter Messages = ");
                String text = inputUser.next();
                System.out.print("Enter Recipient = ");
                String recipient = inputUser.next();
                Messages message = new Messages(text,recipient,id);
                messages.add(message);

                System.out.print("Back to previous menu?(y/Y) ");
                backmenu1 = inputUser.next();
            }
            else if(choose2 == 3){
            backMenu++;
            }
            else{
                System.out.println("Input Doesn't Exist");
            }
        }while(backmenu1.equals("Y") || backmenu1.equals("y"));
        }
        else if(choose1 == 3){
            System.out.println("Thanks for using this program");
        }
        else{
            System.out.println("Input Doesn't Exist");
        }
    }while(backMenu == 1);
    }
}
