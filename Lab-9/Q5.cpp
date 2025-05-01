#include "iostream"
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string trackingNum, double wt) : trackingNumber(trackingNum), weight(wt) {}

    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;

    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string trackingNum, double wt) : Shipment(trackingNum, wt) {}

    void estimateDeliveryTime() override {
        cout << "Estimated Delivery (Air): 1-2 days" << endl;
    }

    void showDetails() override {
        cout << "Air Freight - Tracking #: " << trackingNumber << ", Weight: " << weight << " kg" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string trackingNum, double wt) : Shipment(trackingNum, wt) {}

    void estimateDeliveryTime() override {
        cout << "Estimated Delivery (Ground): 3-5 days" << endl;
    }

    void showDetails() override {
        cout << "Ground Shipment - Tracking #: " << trackingNumber << ", Weight: " << weight << " kg" << endl;
    }
};

int main() {
    Shipment* shipment1 = new AirFreight("AIR123", 15.7);
    Shipment* shipment2 = new GroundShipment("GRND456", 42.3);

    shipment1->showDetails();
    shipment1->estimateDeliveryTime();
    cout << endl;
    shipment2->showDetails();
    shipment2->estimateDeliveryTime();

    delete shipment1;
    delete shipment2;

    return 0;
}
