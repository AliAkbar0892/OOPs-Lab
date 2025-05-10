#include "iostream"
#include "stdexcept"
#include "string"

using namespace std;

class DatabaseException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {
};

class QueryTimeoutException : public DatabaseException {
};

template <typename T>
class DatabaseConnector {
public:

    void connect(const string& dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw DatabaseException(); 
        } else {
            cout << "Connected to " << dbName << endl;
        }
    }

    void query(const string& dbName) {
        if (dbName == "slow_db") {
            throw QueryTimeoutException(); 
        } else {
            cout << "Query executed on " << dbName << endl;
        }
    }
};

int main() {
    DatabaseConnector<int> dbConnector;

    try {
        cout << "Attempting to connect to invalid_db ..." << endl;
        dbConnector.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to connect to slow_db ..." << endl;
        dbConnector.connect("slow_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to query on slow_db ..." << endl;
        dbConnector.query("slow_db");
    } catch (const QueryTimeoutException& e) {
        cout << "Caught QueryTimeoutException - what(): " << e.what() << endl;
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
