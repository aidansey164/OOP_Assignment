public class Order {
	
    public enum OrderType { 
        BUY, SELL
    }

    public enum OrderTypeS { 
        MARKET, LIMIT
    }

    public final OrderType orderType;
    public final OrderTypeS orderSubType;
    public double price;
    public double quantity;
    public final User user;
    public final CryptoTypes crypto;
    public boolean isFilled = false;



    public Order(User user, CryptoTypes crypto, double quantity, OrderType orderType, OrderTypeS orderSubType, double price) { 
        this.user = user;
    	this.crypto = crypto;
        this.quantity = quantity;
        this.orderType = orderType;
        this.orderSubType = orderSubType;
        this.price = price;
    }

    public Order(User user, CryptoTypes crypto, double quantity, OrderType orderType, OrderTypeS orderSubType) {
        this.user = user;
        this.crypto = crypto;
        this.quantity = quantity;
        this.orderType = orderType;
        this.orderSubType = orderSubType;
    }
}