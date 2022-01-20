import java.util.LinkedList;
import java.util.ArrayList;

public class ORDERBOOK {
    public LinkedList<Order> order_queue; // queue of order
    public ArrayList<Order> orders;  // array list to hold order history of orders

    public ORDERBOOK() {
        orders = new ArrayList<>();
        order_queue = new LinkedList<>();
    }
}
