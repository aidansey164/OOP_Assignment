
public class main_launcher {
    public static void main(String[] args) {
    	SystemCrypto syst = SystemCrypto.getInstance();

        
        User user1 = new User("Aidan", 19, 1231, 101);
        User user2 = new User("Toni", 21, 1231, 105);
        Admin admin = new Admin("Admin", 20);
      

        CryptoTypes btc = new CryptoTypes("btc", 100, 20100);
        CryptoTypes doge = new CryptoTypes("doge", 1000, 10000);
        CryptoTypes eth = new CryptoTypes("eth", 1000, 10000);
        
        Order order1 = new Order(user1, btc, 30, Order.OrderType.BUY, Order.OrderTypeS.MARKET);
        syst.addOrder(order1);

        Order order2 = new Order(user1, doge, 30, Order.OrderType.BUY, Order.OrderTypeS.MARKET);
        syst.addOrder(order2);

        Order order3 = new Order(user2, btc, 30, Order.OrderType.SELL, Order.OrderTypeS.LIMIT, 1.5);
        syst.addOrder(order3);

        
        for (Order orders : syst.orderbook.order_queue) {
            System.out.println(
            		"User: " + orders.user + "\nOrder Type: " + orders.orderType + "\nOrder Sub-type: " + orders.orderSubType + "\nCryptoType: " + orders.crypto);
        }
  
    }
}
