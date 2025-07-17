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
protected:
    CartSRP* cart;
public:
    CartRepository(CartSRP* c) : cart(c) {}

    virtual void saveToDb() = 0;
};

class SaveToMongo : public CartRepository {
public:
    SaveToMongo(CartSRP* c) : CartRepository(c) {}

    void saveToDb() override {
        cout << "SaveToMongo: Saving cart data to MongoDB." << endl;
    }
};

class SaveToFile : public CartRepository {
public:
    SaveToFile(CartSRP* c) : CartRepository(c) {}

    void saveToDb() override {
        cout << "SaveToFile: Saving cart data to a file." << endl;
    }
};

class SaveToSQL : public CartRepository {
public:
    SaveToSQL(CartSRP* c) : CartRepository(c) {}

    void saveToDb() override {
        cout << "SaveToSQL: Saving cart data to SQL Database." << endl;
    }
};

class InvoiceGenerator {
private:
    CartSRP* cart;
public:
    InvoiceGenerator(CartSRP* c) : cart(c) {}

    string generateInvoice(double totalPrice) {
        cout << "InvoiceGenerator: Generating invoice..." << endl;
        string invoiceContent = "--- Invoice ---\n";
        for (size_t i = 0; i < cart->getProducts().size(); ++i) {
            invoiceContent += to_string(i + 1) + ". " + cart->getProducts()[i].name + " - $" +
                              to_string(cart->getProducts()[i].price) + "\n";
        }
        invoiceContent += "----------------\nTotal: $" + to_string(totalPrice) + "\n";
        cout << invoiceContent;
        return invoiceContent;
    }
};

int main() {
    Product laptop("Laptop", 1200.00);
    Product mouse("Mouse", 25.50);

    cout << "--- Demonstrating SRP & OCP ---" << endl;

    CartSRP myCart;
    myCart.addProduct(laptop);
    myCart.addProduct(mouse);

    PriceCalculator calculator(&myCart);
    double total = calculator.calculateTotal();

    CartRepository* mongoRepo = new SaveToMongo(&myCart);
    mongoRepo->saveToDb();

    CartRepository* fileRepo = new SaveToFile(&myCart);
    fileRepo->saveToDb();

    CartRepository* sqlRepo = new SaveToSQL(&myCart);
    sqlRepo->saveToDb();

    delete mongoRepo;
    delete fileRepo;
    delete sqlRepo;

    InvoiceGenerator invoiceGen(&myCart);
    invoiceGen.generateInvoice(total);

    return 0;
}
