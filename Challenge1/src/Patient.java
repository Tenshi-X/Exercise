public class Patient {
    String name;
    int age;
    Eye eye;
    Stomach stomach;
    Skin skin;
    Heart heart;

    public Patient(String name, int age, Eye eye, Stomach stomach, Skin skin, Heart heart) {
        this.name = name;
        this.age = age;
        this.eye = eye;
        this.stomach = stomach;
        this.skin = skin;
        this.heart = heart;
    }
}
