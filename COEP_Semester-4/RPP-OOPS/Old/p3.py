"""
# Define a class to represent a bank account. Include the following details like name of 
the depositor, account number, type of account, balance amount in the account. Write 
methods to assign initial values, to deposit an amount, withdraw an amount after 
checking the balance, to display name, account number, account type and balance.
 You have to write menu driven program for this problem statment
"""

class BankAccount:
    def __init__(self, name, acc_no, acc_type, balance):
        self.name = name
        self.acc_no = acc_no
        self.acc_type = acc_type
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if self.balance < amount:
            print("Insufficient balance")
        else:
            self.balance -= amount

    def display(self):
        print("Name: ", self.name)
        print("Account number: ", self.acc_no)
        print("Account type: ", self.acc_type)
        print("Balance: ", self.balance)

def main():
    name = input("Enter name: ")
    acc_no = input("Enter account number: ")
    acc_type = input("Enter account type: ")
    balance = int(input("Enter balance: "))
    b = BankAccount(name, acc_no, acc_type, balance)
    while True:
        print("1. Deposit")
        print("2. Withdraw")
        print("3. Display")
        print("4. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            amount = int(input("Enter amount to deposit: "))
            b.deposit(amount)
        elif choice == 2:
            amount = int(input("Enter amount to withdraw: "))
            b.withdraw(amount)
        elif choice == 3:
            b.display()
        elif choice == 4:
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
