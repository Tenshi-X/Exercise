public class Car extends Vehicle {
    int years;
    String name;

    Car(String name,int years, double speed){
        super(speed);
        this.years = years;
        this.name = name;
    }
    public String gas(){
        return this.name + super.go();
    }
}
