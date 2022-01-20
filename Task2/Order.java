import java.util.concurrent.atomic.AtomicInteger;

public class Order {
	
    public enum OrderType { 
        BUY, SELL
    }

    public enum OrderTypeS { 
        MARKET, LIMIT
    }

    
    private static final AtomicInteger count = new AtomicInteger(0);
    public final OrderType orderType;
    public final OrderTypeS orderSubType;
    public double price;
    public double quantity;
    public final User user;
    public final CryptoTypes crypto;
    public int order_id;



    public Order(User user, CryptoTypes crypto, double quantity, OrderType orderType, OrderTypeS orderSubType, double price) { 
        this.user = user;
    	this.crypto = crypto;
        this.quantity = quantity;
        this.orderType = orderType;
        this.orderSubType = orderSubType;
        this.price = price;
        this.order_id = count.incrementAndGet();
    }

    public Order(User user, CryptoTypes crypto, double quantity, OrderType orderType, OrderTypeS orderSubType) {
        this.user = user;
        this.crypto = crypto;
        this.quantity = quantity;
        this.orderType = orderType;
        this.orderSubType = orderSubType;
        this.order_id = count.incrementAndGet();
    }
}