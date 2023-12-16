# Write a program to raise a exception and handle it

class LessThanZeroError(Exception):
    def __init__(self, value):
        self.value = value


def main():
    try:
        a = int(input("Enter a number: "))
        b = int(input("Enter a number: "))
        if a < 0 or b < 0:
            raise LessThanZeroError("Value is less than zero")
        c = a/b
        print(c)
    except ZeroDivisionError:
        print("Division by zero is not possible")
    except LessThanZeroError as e:
        print(e)
    except:
        print("Some error occured")
    else:
        print("No error")
    finally:
        print("Code Executed")


if __name__ == "__main__":
    main()
