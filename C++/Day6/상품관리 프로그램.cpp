#include <iostream>
#include <string>
#include <vector>

class Product {
protected:
    std::string id;
    int price;
    std::string producer;

public:
    Product(const std::string& _id, int _price, const std::string& _producer)
        : id(_id), price(_price), producer(_producer) {
    }

    std::string getId() const { return id; }
    int getPrice() const { return price; }
    std::string getProducer() const { return producer; }

    void setId(const std::string& _id) { id = _id; }
    void setPrice(int _price) { price = _price; }
    void setProducer(const std::string& _producer) { producer = _producer; }


    virtual void display() const {
        std::cout << "ID: " << id << ", Price: " << price << ", Producer: " << producer << std::endl;
    }

    virtual ~Product() = default;
};


class Book : public Product {
private:
    std::string author;

public:
    Book(const std::string& _id, int _price, const std::string& _producer, const std::string& _author)
        : Product(_id, _price, _producer), author(_author) {
    }

    std::string getAuthor() const { return author; }
    void setAuthor(const std::string& _author) { author = _author; }

    void display() const override {
        Product::display();
        std::cout << "Author: " << author << std::endl;
    }
};

class HandPhone : public Product {
private:
    std::string model;

public:
    HandPhone(const std::string& _id, int _price, const std::string& _producer, const std::string& _model)
        : Product(_id, _price, _producer), model(_model) {
    }

    std::string getModel() const { return model; }
    void setModel(const std::string& _model) { model = _model; }

    void display() const override {
        Product::display();
        std::cout << "Model: " << model << std::endl;
    }
};

class Computer : public Product {
private:
    std::string cpu;

public:
    Computer(const std::string& _id, int _price, const std::string& _producer, const std::string& _cpu)
        : Product(_id, _price, _producer), cpu(_cpu) {
    }

    std::string getCpu() const { return cpu; }
    void setCpu(const std::string& _cpu) { cpu = _cpu; }

    void display() const override {
        Product::display();
        std::cout << "CPU: " << cpu << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Product>> products;

    products.push_back(std::make_unique<Book>("DF021", 15000, "한국출판사", "석동준"));
    products.push_back(std::make_unique<HandPhone>("A012", 1300000, "Apple", "iPHONE14 PRO"));
    products.push_back(std::make_unique<Computer>("C024", 1500000, "Samsung", "Intel i9"));

    std::cout << "--- 상품 목록 ---" << std::endl;
    for (size_t i = 0; i < products.size(); ++i) {
        products[i]->display();
        std::cout << "------------------" << std::endl;
    }

    return 0;
}
