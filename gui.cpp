//
// Created by David Berbecar on 20.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"

#include "Bill.h"
#include "ui_gui.h"
#include <QMessageBox>
#include<QListWidgetItem>
#include<QBrush>

gui::gui(QWidget *parent, Service& service) : service{service},
    QWidget(parent), ui(new Ui::gui) {
    ui->setupUi(this);
    populateList();
    connect(ui->paidCheck,&QCheckBox::clicked,this,&gui::paidBills);
    connect(ui->unpaidCheck, &QCheckBox::clicked, this, &gui::unpaidBills);
    connect(ui->allCheck,&QCheckBox::clicked,this,&gui::populateList);
    connect(ui->totalPButton,&QPushButton::clicked,this,&gui::totalByCompany);
}

void gui::populateList() {
    ui->billsList->clear();
    std::vector<Bill> bills = this->service.getAllBills();
    for (auto bill: bills) {
        QListWidgetItem* item = new QListWidgetItem(bill.toString().c_str());
        if (bill.paid()) {
            item->setBackground(QBrush(Qt::green));
        }else {
            item->setBackground(QBrush(Qt::red));
        }
        ui->billsList->addItem(item);
    }
}

void gui::paidBills(){
    ui->billsList->clear();
    std::vector<Bill> bills = this->service.getPaidBills();
    for (auto bill: bills) {
        QListWidgetItem* item = new QListWidgetItem(bill.toString().c_str());
        item->setBackground(QBrush(Qt::green));
        ui->billsList->addItem(item);
    }
}

void gui::unpaidBills() {
    ui->billsList->clear();
    std::vector<Bill> bills = this->service.getUnpaidBills();
    for (auto bill: bills) {
        QListWidgetItem* item = new QListWidgetItem(bill.toString().c_str());
        item->setBackground(QBrush(Qt::red));
        ui->billsList->addItem(item);    }
}

void gui::totalByCompany() {
    try {
        std::string companyName=ui->companyLE->text().toStdString();
        double total = this->service.getCompanyTotal(companyName);
        ui->totalLE->setText(std::to_string(total).c_str());
    }catch (std::invalid_argument& e) {
        QMessageBox mb;
        mb.setText(e.what());
        mb.exec();
    }
}

gui::~gui() {
    delete ui;
}
