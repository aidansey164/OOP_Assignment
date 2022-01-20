

public class SystemCrypto { 
    private static SystemCrypto single_instance = null;

    public ORDERBOOK orderbook = new ORDERBOOK();
    private SystemCrypto() {
    }

    public static SystemCrypto getInstance() { 
        if (single_instance == null) {
            single_instance = new SystemCrypto();
        }
        return single_instance;
    }

    public int count = 0;
    public void addOrder(Order order) { 
        if (order.quantity <= 0) {
            System.out.println("Invalid order quantity.");
            return;
        }
        orderbook.orders.add(order);
        orderbook.order_queue.add(order);
        count++;
    }
}