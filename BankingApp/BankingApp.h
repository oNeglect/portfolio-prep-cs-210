#pragma once
#ifndef BANKING_APP_H
#define BANKING_APP_H

using namespace std;


//Class which is constructed to delcare variables and methods for cpp file
class BankingApp {
    //Public Attributes for class ContactNode
public:
    BankingApp();
    void setInitialInvestment(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setInterestRate(double t_interestRate);
    void setNumberOfYears(int t_numberOfYears);
    void setOtherTable(bool t_printOtherTable);
    double getInitialInvestment();
    double getMonthlyDeposit();
    double getInterestRate();
    int getNumberOfYears();
    void displayDataInput();
    void displayStaticReportWith();
    void displayStaticReportWithout();
    double calculateBalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);
    double calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears);
    string continueProgram();
    void printDetails(int t_year, double t_yearEndBalance, double t_interestEarned);
    bool getOtherTable();
  
    //Private Attributes for class BankingApp
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_numberOfYears;
    bool m_printOtherTable;
};
#endif
