#include <bits/stdc++.h>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) : name(name), price(price) {}
};

class CartSRP {
public:
    vector<Product> products;

    void addProduct(Product product) {
        products.push_back(product);
        cout << "Added " << product.name << " to cart." << endl;
    }

    vector<Product>& getProducts() {
        return products;
    }
};

class PriceCalculator {
private:
    CartSRP* cart;
public:
    PriceCalculator(CartSRP* c) : cart(c) {}

    double calculateTotal() {
        if (!cart) {
            cout << "Error: Cart not set for PriceCalculator." << endl;
            return 0.0;
        }
        vector<Product>& products = cart->getProducts();
        double total = 0.0;
        for (auto& product : products) {
            total += product.price;
        }
        cout << "PriceCalculator: Total calculated: $" << fixed << setprecision(2) << total << endl;
        return total;
    }
};

class CartRepository {
private:
    CartSRP* cart;
public:
    CartRepository(CartSRP* c) : cart(c) {}

    void save() {
        if (!cart) {
            cout << "Error: Cart not set for CartRepository." << endl;
            return;
        }
        cout << "CartRepository: Saving cart data to DB (simulated)." << endl;
    }
};

class InvoiceGenerator {
private:
    CartSRP* cart;
public:
    InvoiceGenerator(CartSRP* c) : cart(c) {}

    string generateInvoice(double totalPrice) {
        if (!cart) {
            cout << "Error: Cart not set for InvoiceGenerator." << endl;
            return "";
        }
        cout << "InvoiceGenerator: Generating invoice..." << endl;
        string invoiceContent = "--- Invoice ---\n";
        for (size_t i = 0; i < cart->getProducts().size(); ++i) {
            invoiceContent += to_string(i + 1) + ". " + cart->getProducts()[i].name + " - $" +
                              to_string(cart->getProducts()[i].price) + "\n";
        }
        invoiceContent += "-----------\nTotal: $" + to_string(totalPrice) + "\n";
        cout << invoiceContent;
        return invoiceContent;
    }
};

int main() {
    Product laptop("Laptop", 1200.00);
    Product mouse("Mouse", 25.50);

    cout << "--- Demonstrating SRP ---" << endl;

    CartSRP myCart;
    myCart.addProduct(laptop);
    myCart.addProduct(mouse);

    PriceCalculator calculator(&myCart);
    double total = calculator.calculateTotal();

    CartRepository repo(&myCart);
    repo.save();

    InvoiceGenerator invoiceGen(&myCart);
    invoiceGen.generateInvoice(total);

    return 0;
}
