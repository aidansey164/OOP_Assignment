
public class main_launcher {

	public static void main(String[] args) {
		System.out.println("Main class");
		CryptoTypes btc = new CryptoTypes("btc", 10000, 1000); //symbol, price, stock
		CryptoTypes doge = new CryptoTypes("doge", 10000, 1000);
		System.out.println(btc.symbol);
		System.out.println(doge.symbol);

	}

}
