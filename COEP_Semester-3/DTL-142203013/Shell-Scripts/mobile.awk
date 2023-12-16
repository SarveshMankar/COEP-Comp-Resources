BEGIN {
    print "Enter a 10 Digit Mobile Number:"
    getline num> "-"
}
{
    print num
    if (num /[0-9]/ && length(num)==10){
        print "Valid!"
    }
    else{
        print "Invalid!"
    }
    exit 0
}
