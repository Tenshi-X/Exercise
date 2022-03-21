public class Contact {
    String name;
    int number;
    String email;

    public Contact(String name, int number, String email) {
        this.name = name;
        this.number = number;
        this.email = email;
    }
    public void getDetails(){
        System.out.println("Name = " + this.name);
        System.out.println("Number = " + this.number);
        System.out.println("Email = " + this.email);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
