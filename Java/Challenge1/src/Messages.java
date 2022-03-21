public class Messages {
    String text;
    String recipient;
    int id;

    public Messages(String text, String recipient, int id) {
        this.text = text;
        this.recipient = recipient;
        this.id = id;
    }
    public void getDetails(){
        System.out.println("ID = " + this.id);
        System.out.println("Recipient = " + this.recipient);
        System.out.println("Messages = " + this.text);
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public String getRecipient() {
        return recipient;
    }

    public void setRecipient(String recipient) {
        this.recipient = recipient;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
