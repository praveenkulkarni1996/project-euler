def palindrome(string):
    length = len(string)
    for i in range(0, length):
        if(string[i] != string[length - 1 - i]) : return False
    return True

summation = 0
for i in range(1, 1000000 + 1):
    if(palindrome(str(i))):
        if(palindrome(bin(i)[2:])):
            summation += i
print summation
