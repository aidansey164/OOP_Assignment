
public class User {
    public  int userid;
    public int age;public String name;
    public double FIAT_balance;
    public double Crypto_balance = 0;
    public boolean admin_status = false;

    public User(String name, int age, double FIAT_balance, int userid) {
        this.name = name;
        this.age = age;
        this.FIAT_balance = FIAT_balance;
        this.userid = userid;
    }
}
