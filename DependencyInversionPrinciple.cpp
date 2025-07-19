#include <bits/stdc++.h>
using namespace std;

class IDatabase {
public:
    virtual ~IDatabase() = default;
    virtual void save(const string& data) const = 0;
};

class MongoDB : public IDatabase {
public:
    void save(const string& data) const override {
        cout << "Saving '" << data << "' to MongoDB." << endl;
    }
};

class SQLDB : public IDatabase {
public:
    void save(const string& data) const override {
        cout << "Saving '" << data << "' to SQL Database." << endl;
    }
};

class CassandraDB : public IDatabase {
public:
    void save(const string& data) const override {
        cout << "Saving '" << data << "' to Cassandra Database." << endl;
    }
};

class Application {
private:
    const IDatabase& db;

public:
    Application(const IDatabase& database) : db(database) {
        cout << "Application initialized with a database." << endl;
    }

    void performSave(const string& data) const {
        cout << "Application is performing save operation..." << endl;
        db.save(data);
    }
};

int main() {
    cout << "Demonstrating Dependency Inversion Principle (DIP)\n";
    cout << "---------------------------------------------------\n\n";

    MongoDB mongo_db;
    Application app_with_mongo(mongo_db);
    app_with_mongo.performSave("User data for MongoDB");
    cout << endl;

    SQLDB sql_db;
    Application app_with_sql(sql_db);
    app_with_sql.performSave("Product catalog for SQLDB");
    cout << endl;

    CassandraDB cassandra_db;
    Application app_with_cassandra(cassandra_db);
    app_with_cassandra.performSave("Sensor readings for CassandraDB");
    cout << endl;

    return 0;
}
