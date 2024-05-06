#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
using namespace std;

class cProduct {
public:
    int Pd;
    string Pname;
    int stock;
    int price;
    int exp_month;
    int exp_year;
    cProduct* pnext;
};

class clistProduct {
public:
    cProduct* phead;
    cProduct* ptail;

    clistProduct() {
        phead = NULL;
        ptail = NULL;
    }

    ~clistProduct() {
        cProduct* ptrv = phead;
        while (phead != NULL) {
            phead = ptrv->pnext;
            ptrv->pnext = NULL;
            delete ptrv;
            ptrv = phead;
        }
    }

    void prodAttach(cProduct* pnn) {
        if (phead == NULL) {
            phead = pnn;
            ptail = pnn;
        }
        else {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }

    void prodDisplay0() {
        cProduct* ptrap;
        ptrap = phead;
        while (ptrap != NULL) {
            cout << ptrap->Pd << ",";
            cout << ptrap->Pname << ",";
            cout << ptrap->stock << ",";
            cout << ptrap->price << ",";
            cout << ptrap->exp_month << ",";
            cout << ptrap->exp_year << "," << endl;
            ptrap = ptrap->pnext;
        }
    }

    void prodDisplay() {
        cProduct* ptrap;
        ptrap = phead;
        while (ptrap != NULL) {
            if (ptrap->stock > 0) {
                cout << ptrap->Pd << ",";
                cout << ptrap->Pname << ",";
                cout << ptrap->stock << ",";
                cout << ptrap->price << ",";
                cout << ptrap->exp_month << ",";
                cout << ptrap->exp_year << "," << endl;
            }
            ptrap = ptrap->pnext;

        }
    }

    void writeProd() {
        ofstream prodRead;
        prodRead.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Product.txt");

        if (prodRead.is_open()) {
            cProduct* ptrv = phead;
            prodRead << "ID" << ",";
            prodRead << "Product name" << ",";
            prodRead << "stock" << ",";
            prodRead << "price" << ",";
            prodRead << "exp_month" << ",";
            prodRead << "exp_year" << ", " << endl;

            while (ptrv != NULL) {
                prodRead << ptrv->Pd << ",";
                prodRead << ptrv->Pname << ",";
                prodRead << ptrv->stock << ",";
                prodRead << ptrv->price << ",";
                prodRead << ptrv->exp_month << ",";
                prodRead << ptrv->exp_year << "," << endl;
                ptrv = ptrv->pnext;
            }

            prodRead.close();
        }
        else {
            cout << "Error: Unable to open the product file for writing." << endl;
        }
    }
    void removeProd(int productIdToDelete) {
        cProduct* pcurr = phead;
        cProduct* pb = NULL;
        while (pcurr != NULL && pcurr->Pd != productIdToDelete) {
            pb = pcurr;
            pcurr = pcurr->pnext;
        }
        if (pcurr != NULL) {
            if (pb == NULL) {
                phead = pcurr->pnext;
            }
            else {
                pb->pnext = pcurr->pnext;
            }
            if (ptail == pcurr) {
                ptail = pb;
            }
            delete pcurr;
        }
        else {
            cout << "Product not found." << endl;
        }
    }
};

class orders {
public:
    int Pid;
    int Cid;
    orders* pnext;
};

class clistOrder {
public:
    orders* Ordphead;
    orders* Ordptail;
    clistProduct* prodList;

    clistOrder() {
        Ordphead = NULL;
        Ordptail = NULL;
    }

    ~clistOrder() {
        orders* ptrv = Ordphead;
        while (Ordphead != NULL) {
            Ordphead = ptrv->pnext;
            ptrv->pnext = NULL;
            delete ptrv;
            ptrv = Ordphead;
        }
    }

    void orderAttach(orders* pnn) {
        if (Ordphead == NULL) {
            Ordphead = pnn;
            Ordptail = pnn;
        }
        else {
            Ordptail->pnext = pnn;
            Ordptail = pnn;
        }
    }

    void Display() {
        orders* ptrap;
        ptrap = Ordphead;
        while (ptrap != NULL) {
            cout << ptrap->Cid << ",";
            cout << ptrap->Pid << ",";
            ptrap = ptrap->pnext;
        }
    }

    void writOrder() {
        ofstream orderRead;
        orderRead.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Orders.txt");
        if (orderRead.is_open()) {
            orders* ptrv = Ordphead;
            orderRead << "CustomerID" << ",";
            orderRead << "ProductID" << "," << endl;
            while (ptrv != NULL) {
                orderRead << ptrv->Cid << ",";
                orderRead << ptrv->Pid << "," << endl;
                ptrv = ptrv->pnext;
            }
            orderRead.close();
        }
    }

    void removeOrder(int prodId) {
        orders* pcurr = Ordphead;
        orders* pb = NULL;
        while (pcurr != NULL && pcurr->Pid != prodId) {
            pb = pcurr;
            pcurr = pcurr->pnext;
        }
        if (pcurr == NULL) {
            cout << "Order not fount" << endl;
            return;
        }
        if (pb == NULL) {
            Ordphead = pcurr->pnext;
        }
        else {
            pb->pnext = pcurr->pnext;
        }
        delete pcurr;
    }
};

class Customer {
public:
    int Pid;
    string cname;
    string pass;
    Customer* pnext;
};

class clistCustomer {
public:
    Customer* phead;
    Customer* ptail;

    clistCustomer() {
        phead = NULL;
        ptail = NULL;
    }

    ~clistCustomer() {
        Customer* ptrv = phead;
        while (phead != NULL) {
            phead = ptrv->pnext;
            ptrv->pnext = NULL;
            delete ptrv;
            ptrv = phead;
        }
    }

    void custAttach(Customer* pnn) {
        if (phead == NULL) {
            phead = pnn;
            ptail = pnn;
        }
        else {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }

    void custDisplay() {
        Customer* ptrap;
        ptrap = phead;
        while (phead != NULL) {
            cout << ptrap->Pid << ",";
            cout << ptrap->cname << ",";
            cout << ptrap->pass << ",";
            ptrap = ptrap->pnext;
        }
    }

    void writeCust() {
        ofstream custRead;
        custRead.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Customer.txt");
        if (custRead.is_open()) {
            Customer* ptrv = phead;
            custRead << "ID" << ",";
            custRead << "Name" << ",";
            custRead << "Password" << "," << endl;
            while (ptrv != NULL) {
                custRead << ptrv->Pid << ",";
                custRead << ptrv->cname << ",";
                custRead << ptrv->pass << "," << endl;
                ptrv = ptrv->pnext;
            }
            custRead.close();
        }

    }

};

class Admin {
public:
    int Pid;
    string cname;
    string pass;
    Admin* pnext;
};

class clistAdmin {
public:
    Admin* phead;
    Admin* ptail;

    clistAdmin() {
        phead = NULL;
        ptail = NULL;
    }

    ~clistAdmin() {
        Admin* ptrv = phead;
        while (phead != NULL) {
            phead = ptrv->pnext;
            ptrv->pnext = NULL;
            delete ptrv;
            ptrv = phead;
        }
    }

    void adminAttach(Admin* pnn) {
        if (phead == NULL) {
            phead = pnn;
            ptail = pnn;
        }
        else {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }

    void adminDisplay() {
        Admin* ptrap;
        ptrap = phead;
        while (phead != NULL) {
            cout << ptrap->Pid << ",";
            cout << ptrap->cname << ",";
            cout << ptrap->pass << ",";
        }
    }

    void writeAdmin() {
        ofstream adminRead;
        adminRead.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Admin.txt");
        if (adminRead.is_open()) {
            Admin* ptrv = phead;
            adminRead << "ID" << ",";
            adminRead << "Name" << ",";
            adminRead << "Passwor" << "," << endl;
            while (ptrv != NULL) {
                adminRead << ptrv->Pid << ",";
                adminRead << ptrv->cname << ",";
                adminRead << ptrv->pass << "," << endl;
                ptrv = ptrv->pnext;
            }
            adminRead.close();
        }
    }
};

void readFromAdmin(clistAdmin& adminList) {
    string AdminsText;
    ifstream AdminsFile;

    AdminsFile.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Admin.txt");
    if (AdminsFile.is_open()) {
        string temp = "";
        string temp1[3];
        int k = 0;
        int ct = 0;

        while (getline(AdminsFile, AdminsText)) {
            if (ct > 0) {
                for (int i = 0; i < AdminsText.length(); i++) {
                    if (AdminsText[i] == ',') {
                        temp.clear();
                        k++;
                    }
                    else {
                        temp += AdminsText[i];
                        temp1[k] += AdminsText[i];
                    }
                }
                k = 0;
                Admin* pnn = new Admin;
                pnn->Pid = stoi(temp1[0]);
                pnn->cname = temp1[1];
                pnn->pass = temp1[2];
                pnn->pnext = NULL;
                adminList.adminAttach(pnn);

                for (int h = 0; h < 3; h++) {
                    temp1[h].clear();
                }
            }
            ct++;
        }
    }
    AdminsFile.close();
}

void readFromCust(clistCustomer& custList) {
    string CustomersText;
    ifstream CustomersFile;

    CustomersFile.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Customer.txt");
    if (CustomersFile.is_open()) {
        string temp = "";
        string temp1[3];
        int k = 0;
        int ct = 0;
        //cout << "File is Open" << endl;

        while (getline(CustomersFile, CustomersText)) {
            if (ct > 0) {
                for (int i = 0; i < CustomersText.length(); i++) {
                    if (CustomersText[i] == ',') {
                        temp.clear();
                        k++;
                    }
                    else {
                        temp += CustomersText[i];
                        temp1[k] += CustomersText[i];
                    }
                }
                k = 0;
                Customer* pnn = new Customer;
                pnn->Pid = stoi(temp1[0]);
                pnn->cname = temp1[1];
                pnn->pass = temp1[2];
                pnn->pnext = NULL;
                custList.custAttach(pnn);

                for (int h = 0; h < 3; h++) {
                    temp1[h].clear();
                }
            }
            ct++;
        }
    }
    CustomersFile.close();
}

void readFromOder(clistOrder& orderList) {
    string OrdersText;
    ifstream OrdersFile;

    OrdersFile.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Orders.txt");
    if (OrdersFile.is_open()) {
        string temp = "";
        string temp1[2];
        int k = 0;
        int ct = 0;
        //cout << "File is Open" << endl;

        while (getline(OrdersFile, OrdersText)) {
            if (ct > 0) {
                for (int i = 0; i < OrdersText.length(); i++) {
                    if (OrdersText[i] == ',') {
                        temp.clear();
                        k++;
                    }
                    else {
                        temp += OrdersText[i];
                        temp1[k] += OrdersText[i];
                    }
                }
                k = 0;
                orders* pnn = new orders;
                pnn->Cid = stoi(temp1[0]);
                pnn->Pid = stoi(temp1[1]);
                pnn->pnext = NULL;
                orderList.orderAttach(pnn);
                for (int h = 0; h < 2; h++) {
                    temp1[h].clear();
                }
            }
            ct++;
        }
    }
    OrdersFile.close();
}

void readFromProd(clistProduct& prodList) {
    string prodText;
    ifstream product;
    product.open("C:/Users/HP/OneDrive/Desktop/data_strctuer_project/text files_project/Product.txt");

    if (product.is_open()) {
        string temp = "";
        string temp1[6];
        int k = 0;
        int ct = 0;
        while (getline(product, prodText)) {

            if (ct > 0) {
                for (int i = 0; i < prodText.length(); i++) {
                    if (prodText[i] == ',') {
                        temp.clear();
                        k++;
                    }
                    else {
                        temp += prodText[i];
                        temp1[k] += prodText[i];
                    }

                }
                k = 0;
                cProduct* pnn = new cProduct;
                pnn->Pd = stoi(temp1[0]);
                pnn->Pname = temp1[1];
                pnn->stock = stoi(temp1[2]);
                pnn->price = stoi(temp1[3]);
                pnn->exp_month = stoi(temp1[4]);
                pnn->exp_year = stoi(temp1[5]);
                pnn->pnext = NULL;
                prodList.prodAttach(pnn);

                for (int h = 0; h < 6; h++) {
                    temp1[h].clear();
                }
            }
            ct++;

        }
    }
    product.close();


}

void displayReceipt(clistOrder& orderList, clistProduct& prodList, int custId, int qunt) {
    float tot = 0;
    orders* pcurr = orderList.Ordphead;
    cout << "-----------------------------------------" << endl;
    cout << "Receipt for Customer ID: " << custId  << endl;
    cout << "-----------------------------------------" << endl;
    cProduct* prod = prodList.phead;
    while (pcurr != NULL) {
        if (pcurr->Cid == custId) {
            while (prod != NULL && prod->Pd != pcurr->Pid) {
                prod = prod->pnext;
            }
            if (prod != NULL) {
                cout << "Product ID: " << prod->Pd << endl;
                cout << "Product Name: " << prod->Pname << endl;
                cout << "Quantity: " << qunt << endl;
                cout << "Price: " << prod->price << endl;
                tot += prod->price;
                cout << "-----------------------------------------" << endl;
            }
        }
        pcurr = pcurr->pnext;
    }
    cout << "Total Amount: " << tot << endl;
    cout << "-----------------------------------------" << endl;
}

void buyProduct(clistProduct& prodList, clistOrder& orderList, int customerId, int productId, int quantity) {
    cProduct* product = prodList.phead;
    while (product != NULL && product->Pd != productId) {
        product = product->pnext;
    }

    if (product == NULL || product->stock < quantity) {
        cout << "Product not found or insufficient stock." << endl;
        return;
    }

    product->stock -= quantity;
    orders* newOrder = new orders;
    newOrder->Cid = customerId;
    newOrder->Pid = productId;
    newOrder->pnext = NULL;
    orderList.orderAttach(newOrder);
    orderList.writOrder();
    cout << "Purchase successful!" << endl;
}

void returnProduct(clistProduct& prodList, clistOrder& orderList, int productId) {
    cProduct* product = prodList.phead;
    while (product != NULL && product->Pd != productId) {
        product = product->pnext;
    }

    if (product == NULL) {
        cout << "Product not found." << endl;
        return;
    }

    product->stock += 1;
    orderList.removeOrder(productId);
    prodList.writeProd();
    cout << "Return successful!" << endl;
}

void adjustProduct(clistProduct& prodList)
{
        int productIdToUpdate;
        cout << "Enter the Product ID to update: ";
        cin >> productIdToUpdate;

        cProduct* productToUpdate = prodList.phead;
        while (productToUpdate != NULL && productToUpdate->Pd != productIdToUpdate)
        {
            productToUpdate = productToUpdate->pnext;
        }

        if (productToUpdate == NULL) 
        {
            cout << "Product not found." << endl;
        }
        else 
        {
            int updateChoice;
            cout << "Choose what to update:" << endl;
            cout << "1. Update stock" << endl;
            cout << "2. Update price" << endl;
            cin >> updateChoice;

            if (updateChoice == 1)
            {
                int newStock;
                cout << "Enter the new stock value: ";
                cin >> newStock;
                productToUpdate->stock = newStock;
                cout << "Stock updated successfully." << endl;
            }
            else if (updateChoice == 2) 
            {
                int newPrice;
                cout << "Enter the new price: ";
                cin >> newPrice;
                productToUpdate->price = newPrice;
                cout << "Price updated successfully." << endl;
            }
            else {
                cout << "Invalid update choice." << endl;
            }
        }
    prodList.writeProd();
}

void deleteProduct(clistProduct& prodList, int productIdToDelete) {
    if (prodList.phead == NULL) {
        cout << "No products available to delete." << endl;
        return;
    }

    cProduct* current = prodList.phead;
    cProduct* previous = NULL;
    while (current != NULL && current->Pd != productIdToDelete) {
        previous = current;
        current = current->pnext;
    }
    if (current == NULL) {
        cout << "Product with ID " << productIdToDelete << " not found." << endl;
        return;
    }
    if (previous == NULL) {
        prodList.phead = current->pnext;
    }
    else {
        previous->pnext = current->pnext;
    }
    if (current == prodList.ptail) {
        prodList.ptail = previous;
    }
    delete current;
    cout << "Product with ID " << productIdToDelete << " has been deleted." << endl;
    prodList.writeProd();
}

void dispQunt(clistProduct& prodList) {
    int quantityThreshold;
    cout << "Enter the quantity threshold: ";
    cin >> quantityThreshold;
    cProduct* product = prodList.phead;
    bool found = false;
    cout << "Products with stock less than " << quantityThreshold << ":" << endl;
    while (product != NULL) {
        if (product->stock < quantityThreshold)
        {
            cout << "-----------------------------------------" << endl;
            cout << "Product ID: " << product->Pd << endl;
            cout << "Product Name: " << product->Pname << endl;
            cout << "Stock: " << product->stock << endl;
            cout << "Price: " << product->price << endl;
            cout << "Expiration Date: " << product->exp_month << "/" << product->exp_year << endl;
            cout << "-----------------------------------------" << endl;
            found = true;
        }
        product = product->pnext;
    }
    if (!found) {
        cout << "No products found with stock less than " << quantityThreshold << "." << endl;
    }
}

void dispOrder(clistOrder& orderList) {
    int customerId;
    cout << "-----------------------------------------" << endl;
    cout << "Enter the customer ID: ";
    cin >> customerId;
    orders* order = orderList.Ordphead;
    int orderCount = 0;
    while (order != NULL) {
        if (order->Cid == customerId) {
            orderCount++;
        }
        order = order->pnext;
    }
    cout << "Customer with ID " << customerId << " has placed " << orderCount << " orders." << endl;
    cout << "-----------------------------------------" << endl;
}

int main() 
{
    clistProduct prodList;
    clistAdmin adminList;
    clistCustomer custList;
    clistOrder orderList;
    readFromAdmin(adminList);
    readFromCust(custList);
    readFromOder(orderList);
    readFromProd(prodList);
    int c, id, flag, l, el, cId, choice, f, chooseAdmine;
    int prdId, qunt, fOut = 0, choice2;
    string name, pass;
    Customer* ptrv;
    int flag1 = 0;
    while (true)
    {
        cout << "please choose one" << endl;
        cout << "1-Customer" << endl;
        cout << "2-Amdin" << endl;
        cout << "3-exit" << endl;
        cin >> c;
        if (c != 3) 
        {
            while (true)
            {
                if (c == 1)
                {
                    cout << "please choose one" << endl;
                    cout << "1-login" << endl;
                    cout << "2-Regster" << endl;
                    cin >> l;
                    if (l == 1) 
                    {
                        cout << "enter your id" << endl;
                        cin >> id;
                        cout << "enter your name" << endl;
                        cin >> name;
                        cout << "enter your passowrd" << endl;
                        cin >> pass;
                        Customer* ptrv;
                        ptrv = custList.phead;
                        while (ptrv != NULL) 
                        {
                            if (id == ptrv->Pid && name == ptrv->cname && pass == ptrv->pass) 
                            {
                                cout << "login succsesfuly" << endl;
                                flag = 1;
                                flag1 = 1;
                                cId = ptrv->Pid;
                                break;
                            }
                            ptrv = ptrv->pnext;
                        }
                        if (flag1 == 0) 
                        {
                            cout << "choose one" << endl;
                            cout << "1-try again" << endl;
                            cout << "2-regster" << endl;
                            cin >> el;
                            if (el == 1) 
                            {
                                cout << "enter your id" << endl;
                                cin >> id;
                                cout << "enter your name" << endl;
                                cin >> name;
                                cout << "enter your passowrd" << endl;
                                cin >> pass;
                                while (ptrv != NULL)
                                {
                                    if (name == ptrv->cname && pass == ptrv->pass)
                                    {
                                        cout << "login succsesfuly" << endl;
                                        flag = 1;
                                        cId = ptrv->Pid;
                                        break;
                                    }
                                }
                             
                            }
                            if (el == 2) 
                            {
                                cout << "enter name" << endl;
                                cin >> name;
                                cout << endl << "enter password" << endl;
                                Customer* pnn = new Customer;
                                pnn->Pid = custList.ptail->Pid + 1;
                                cId = pnn->Pid;
                                pnn->cname = name;
                                pnn->pass = pass;
                                pnn->pnext = NULL;
                                custList.custAttach(pnn);
                                flag = 1;
                                custList.writeCust();
                            }
                        }
                    }
                    if (l == 2) 
                    {
                        cout << "enter name" << endl;
                        cin >> name;
                        cout << endl << "enter password" << endl;
                        cin >> pass;
                        Customer* pnn = new Customer;
                        pnn->Pid = custList.ptail->Pid + 1;
                        cId = pnn->Pid;
                        pnn->cname = name;
                        pnn->pass = pass;
                        pnn->pnext = NULL;
                        custList.custAttach(pnn);
                        flag = 1;
                        custList.writeCust();
                    }
                    while (flag == 1) 
                    {
                        cout << "choose one" << endl;
                        cout << "1-Display products" << endl;
                        cout << "2-Buy a Product" << endl;
                        cout << "3-Return a Product" << endl;
                        cout << "4- Display Receipt" << endl;
                        cout << "5-Logout" << endl;
                        cin >> choice;
                        if (choice > 0 || choice <= 5)
                        {
                            if (choice == 1) {
                                prodList.prodDisplay();
                                f = 1;
                            }
                            if (choice == 2 || f == 1) 
                            {
                                cout << "Enter Product ID" << endl;
                                cin >> prdId;
                                cout << endl << "Enter Quantity" << endl;
                                cin >> qunt;
                                buyProduct(prodList, orderList, cId, prdId, qunt);
                                prodList.writeProd();
                                f = 2;
                            }
                            if (choice == 3)
                            {
                                int prodId;
                                cout << "Enter Product ID to return" << endl;
                                cin >> prodId;
                                returnProduct(prodList, orderList, prodId);
                            }
                            if (f == 2 || choice == 4) 
                            {
                                displayReceipt(orderList, prodList, cId, qunt);
                            }
                            if (choice == 5) 
                            {
                                cout << "Logging out" << endl;
                                flag = 0;
                                fOut = 1;
                                custList.writeCust();
                                prodList.writeProd();
                                orderList.writOrder();
                            }
                        }
                    }
                    if (fOut == 1) 
                    {
                        break;
                    }
                }
                else if (c == 2)
                {

                    cout << "enter your admin id" << endl;
                    cin >> id;
                    cout << "enter your name" << endl;
                    cin >> name;
                    cout << "enter your passowrd" << endl;
                    cin >> pass;
                    Admin* ptrv;
                    ptrv = adminList.phead;
                    while (ptrv != NULL) 
                    {
                        if (name == ptrv->cname && pass == ptrv->pass)
                        {
                            cout << "admin entered succsesfuly" << endl;
                            flag = 1;
                            cId = ptrv->Pid;
                        }
                        else {
                            cout << "choose one" << endl;
                            cout << "1-try again" << endl;
                            cout << "2-Log Out" << endl;
                            cin >> el;
                            if (el == 1) 
                            {
                                cout << "enter your admin id" << endl;
                                cin >> id;
                                cout << "enter your name" << endl;
                                cin >> name;
                                cout << "enter your admin passowrd" << endl;
                                cin >> pass;
                                if (name == ptrv->cname && pass == ptrv->pass) 
                                {
                                    cout << "login succsesfuly" << endl;
                                    flag = 1;
                                    cId = ptrv->Pid;
                                    break;
                                }
                            }
                        }
                        if (flag == 1) 
                        {
                            cout << "choose one" << endl;
                            cout << "1-Display products" << endl;
                            cout << "2-Adjust any Product" << endl;
                            cout << "3-Delete any Product" << endl;
                            cout << "4-Display all products that the stock is less than a specific quantity" << endl;
                            cout << "5-Display how many orders are done by a specific customer" << endl;
                            cout << "6-Logout" << endl;
                            cin >> chooseAdmine;
                            if (chooseAdmine == 1) 
                            {
                                prodList.prodDisplay0();

                            }
                            if (chooseAdmine == 2) 
                            {
                                adjustProduct(prodList);
                            }
                            if (chooseAdmine == 3) 
                            {
                                int choose1;
                                cout << "Enter product ID to delete: ";
                                cin >> choose1;
                                deleteProduct(prodList, choose1);
                            }
                            if (chooseAdmine == 4) 
                            {
                                dispQunt(prodList);
                            }
                            if (chooseAdmine == 5) 
                            {
                                dispOrder(orderList);
                            }
                            if (chooseAdmine == 6) 
                            {
                                cout << "Logging out" << endl;
                                flag = 0;
                                fOut = 1;
                                adminList.writeAdmin();
                                custList.writeCust();
                                prodList.writeProd();
                                orderList.writOrder();
                                break;
                            }
                        }
                        if (fOut == 1)
                        {
                            break;
                        }
                    }
                    if (fOut == 1)
                    {
                        break;
                    }

                }
            }
        }
        if (c == 3)
        {
            break;
        }
       
        
    }
}