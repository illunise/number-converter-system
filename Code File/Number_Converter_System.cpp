/*
    Creator :- Manish Kushwaha (@illunise)
    Created At :- 16 Nov, 2022

    -------- Social Media Links ----------
    GitHub :- https://github.com/illunise
    Linkedin :- https://www.linkedin.com/in/illunise
    Project Link :- https://github.com/illunise/number-converter-system
    
*/


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string decimaltoany(long long int n, int base);   // Common Function to convert Decimal ----> Any
long long int anytodecimal(long long int n, int base);  // Common Function to convert Any ----> Decimal


// Function Prototype
void welcomeScreen();           // Welcome Screen When User Interact With Conversion
void exitScreen();              // Exit Screen Texts
void clearScreen();             // Clear the Output Screen
void conversion(int);           // Start the conversion process
void tryAgainFun();             // After Successful Conversion Ask for another conversion
void resultContext();           // After Successful Conversion Show them result context first
int check_digit(long long int, int, int); // Check the digit that is valid or not



//Any to Octal
string binarytooctal(long long int s); // Binary ----> Octal
string decimaltooctal(long long int n);   // Decimal ----> Octal
string hexatooctal(string n);   // Hexadecimal ----> Octal

//Any to Hexadecimal
string binarytohexa(long long int n);     // Binary ----> Hexadecimal
string decimaltohexa(long long int n);    // Decimal ----> Hexadecimal
string octaltohexa(long long int n);      // Octal ----> Hexadecimal


//Any to Decimal
long long int binarytodecimal(long long int n);     // Binary ----> Decimal
long long int octaltodecimal(long long int n);      // Octal ----> Decimal
long long int hexatodecimal(string n);    // Hexadecimal ----> Decimal


//Any to Binary
string decimaltobinary(long long int n);  // Decimal ----> Binary
string octaltobinary(long long int s); // Octal ----> Binary
string hexadecimaltobinary(string s); // Hexadecimal ----> Binary


int main()
{
    clearScreen();
    welcomeScreen();
 
    return 0;
}

/*
Show Welcome screen which contain menu, conversions, etc
*/
void welcomeScreen(){


    int selection;

start:
    cout<<endl<<"-------------------  Welcome  -------------------"<<endl;
    cout<<"-------------------     To    -------------------"<<endl;
    cout<<"-----------  Number Conversion System  ----------"<<endl<<endl<<endl;

    cout<<"1) Binary        -->    Decimal, Octal, Hexadecimal"<<endl;
    cout<<"2) Decimal       -->    Binary, Octal, Hexadecimal"<<endl;
    cout<<"3) Octal         -->    Binary, Decimal, Hexadecimal"<<endl;
    cout<<"4) Hexadecimal   -->    Binary, Decimal, Octal"<<endl;
    cout<<"5) Exit From Program"<<endl<<endl;

    cout<<"Enter Your Option :- ";
    cin>>selection;

    if(selection > 0 && selection < 5){
        conversion(selection);

    }else if(selection == 5){

        exitScreen();
    }else{
        clearScreen();
        cout<<"Please Enter Proper Option From Below List"<<endl;
        goto start;
    }


}

void conversion(int selection){

    clearScreen();

    switch(selection){
        case 1:
        {
            long long int binary;

            cout<<endl<<"Enter Binary Number :- ";
            cin>>binary;

            int check = check_digit(binary, 0, 1);
            

            if(check==1){
                resultContext();
                cout<<"Decimal Number : "<<binarytodecimal(binary)<<endl;
                cout<<"Octal Number : "<<binarytooctal(binary)<<endl;
                cout<<"HexaDecimal Number : "<<binarytohexa(binary)<<endl<<endl;
                tryAgainFun();
            }else{
                clearScreen();
                cout<<"Enter Proper Binary Number"<<endl;
                welcomeScreen();
            }

        }
        case 2:
        {

            long long int decimal;

            cout<<endl<<"Enter Decimal Number :- ";
            cin>>decimal;

            int check = check_digit(decimal, 0, 9);
            

            if(check==1){
                resultContext();
                cout<<"Binary Number : "<<decimaltobinary(decimal)<<endl;
                cout<<"Octal Number : "<<decimaltooctal(decimal)<<endl;
                cout<<"HexaDecimal Number : "<<decimaltohexa(decimal)<<endl<<endl;
                tryAgainFun();
            }else{
                clearScreen();
                cout<<"Enter Proper Decimal Number"<<endl;
                welcomeScreen();
            }
        }
        case 3:
        {

            long long int octal;

            cout<<endl<<"Enter Octal Number :- ";
            cin>>octal;

            int check = check_digit(octal, 0, 7);
            

            if(check==1){
                resultContext();
                cout<<"Binary Number : "<<octaltobinary(octal)<<endl;
                cout<<"Decimal Number : "<<octaltodecimal(octal)<<endl;
                cout<<"HexaDecimal Number : "<<octaltohexa(octal)<<endl<<endl;
                tryAgainFun();
            }else{
                clearScreen();
                cout<<"Enter Proper Octal Number"<<endl;
                welcomeScreen();
            }
        }
        case 4:
        {

            string hexaDecimal;
            int check = 1;

            cout<<endl<<"Enter Hexadecimal Number :- ";
            cin>>hexaDecimal;


            for(int i = 0; i<hexaDecimal.size(); i++){
                if((hexaDecimal[i] >= '0' && hexaDecimal[i] <= '9') || (hexaDecimal[i] >= 'a' && hexaDecimal[i] <= 'f') || (hexaDecimal[i] >= 'A' && hexaDecimal[i] <= 'F')){
                    
                }else{
                    check = 0;
                }
            }
            

            if(check==1){
                resultContext();
                cout<<"Binary Number : "<<hexadecimaltobinary(hexaDecimal)<<endl;
                cout<<"Decimal Number : "<<hexatodecimal(hexaDecimal)<<endl;
                cout<<"Octal Number : "<<hexatooctal(hexaDecimal)<<endl<<endl;
                tryAgainFun();
            }else{
                // clearScreen();
                cout<<"Enter Proper Hexadecimal Number"<<endl;
                welcomeScreen();
            }
        }
        default:
        cout<<"Unexpected Error!"<<endl;
    }

}

void resultContext(){
    cout<<endl<<"------------------------------------"<<endl;
    cout<<"               Results              "<<endl;
    cout<<"------------------------------------"<<endl<<endl;
                
}

void tryAgainFun(){
    string isTry;

    cout<<"Want Another Conversion [Y/N]? ";
    cin>>isTry;

    if(isTry == "y" || isTry == "Y"){
        clearScreen();
        welcomeScreen();
    }else{
        exitScreen();
    }



}

int check_digit(long long int num, int min, int max){

    int isRight = 1;
    long long int temp = num;

    while(temp != 0){
        int last_digit = temp%10;
        
        if(last_digit >= min && last_digit <= max){
            temp /= 10;
        }else{
            isRight = 0;
            break;
        }
    }
        
    return isRight;
}

void exitScreen(){

    clearScreen();

    cout<<endl;
    cout<<"*********************************************************"<<endl;
    cout<<"                          Exited                         "<<endl;
    cout<<"*********************************************************"<<endl;
    cout<<"Copyright © 2022 by Manish Kushwaha. All rights reserved."<<endl<<endl;
    cout<<"------------Useful Links------------"<<endl;
    cout<<"GitHub :- https://github.com/illunise"<<endl;
    cout<<"Linkedin :- https://www.linkedin.com/in/illunise"<<endl<<endl;
    exit(0);
}

void clearScreen(){
    system("clear");
}

string binarytohexa(long long int n){
    long long int decimal = binarytodecimal(n);
    string hexa = decimaltohexa(decimal);

    return hexa;
}

string octaltohexa(long long int n){
    long long int decimal = octaltodecimal(n);
    string hexa = decimaltohexa(decimal);

    return hexa;
}


string decimaltohexa(long long int n){
    string remainder = "";
    long long int quotient = n;

    
    while(quotient != 0){
        // remainder += to_string(quotient%16);
        int new_remainder = quotient%16;
        if(new_remainder > 9 && new_remainder < 16){
            int ascii = new_remainder + 55;
            remainder += char(ascii);
        }else{
            remainder += to_string(quotient%16);
        }
        quotient /= 16;
    }

    reverse(remainder.begin(), remainder.end());

    return remainder;
}

string hexatooctal(string s){
    // string binary = hexadecimaltobinary(n);
    // cout<<"Hexa to Binary Done :- "<<binary;
    // string octal = binarytooctal(stoi(binary));

    // return octal;

    string binary_Num, octal_Num;
    
    for(int i=0; i<s.size(); i++){
        switch(s[i])
        {
            case '0':
                binary_Num.append("0000");
                break;
            case '1':
                binary_Num.append("0001");
                break;
            case '2':
                binary_Num.append("0010");
                break;
            case '3':
                binary_Num.append("0011");
                break;
            case '4':
                binary_Num.append("0100");
                break;
            case '5':
                binary_Num.append("0101");
                break;
            case '6':
                binary_Num.append("0110");
                break;
            case '7':
                binary_Num.append("0111");
                break;
            case '8':
                binary_Num.append("1000");
                break;
            case '9':
                binary_Num.append("1001");
                break;
            case 'a':
            case 'A':
                binary_Num.append("1010");
                break;
            case 'b':
            case 'B':
                binary_Num.append("1011");
                break;
            case 'c':
            case 'C':
                binary_Num.append("1100");
                break;
            case 'd':
            case 'D':
                binary_Num.append("1101");
                break;
            case 'e':
            case 'E':
                binary_Num.append("1110");
                break;
            case 'f':
            case 'F':
                binary_Num.append("1111");
                break;
         }
    }


    for (int i = 1; i <= (3 - binary_Num.size() % 3) % 3; i++){
		binary_Num = "0" + binary_Num;
    }

    int i = binary_Num.size();
    while(binary_Num.empty() == 0){
        string last_three = "";
        
        last_three.append(1, binary_Num[i-3]);
        last_three.append(1, binary_Num[i-2]);
        last_three.append(1, binary_Num[i-1]);
        

        if(last_three == "000"){
            octal_Num += '0';
        }else if(last_three == "001"){
            octal_Num += '1';
        }else if(last_three == "010"){
            octal_Num += '2';
        }else if(last_three == "011"){
            octal_Num += '3';
        }else if(last_three == "100"){
            octal_Num += '4';
        }else if(last_three == "101"){
            octal_Num += '5';
        }else if(last_three == "110"){
            octal_Num += '6';
        }else if(last_three == "111"){
            octal_Num += '7';
        }


        if(binary_Num.size() == 2){
            binary_Num.erase(i-2, 2);
        }else if(binary_Num.size() == 1){
            binary_Num.erase(i-1, 1);
        }else{
            binary_Num.erase(i-3, 3);
        }

        i -= 3;
    }

    reverse(octal_Num.begin(), octal_Num.end());
    
    return octal_Num;
}

string decimaltooctal(long long int n){
    string octal = decimaltoany(n, 8);

    return octal;
}

string binarytooctal(long long int s){
    long long int decimal = binarytodecimal(s);
    string octal = decimaltooctal(decimal);

    return octal;

}

long long int hexatodecimal(string s){
    long long int decimal = 0;
    int power = 0;
    for(int i = s.length()-1; i >= 0 ; i--){
        if(s[i] >= '0' && s[i] <= '9'){
            int multi_val = int(s[i])-48;
            int mul = multi_val * pow(16,power);
            decimal += mul;
        }else if(s[i] >= 'a' && s[i] <= 'f'){
            int multi_val = int(s[i])-87;
            int mul = multi_val * pow(16,power);
            decimal += mul;
            
        }else if(s[i] >= 'A' && s[i] <= 'F'){
            int multi_val = int(s[i])-55;
            int mul = multi_val * pow(16,power);
            decimal += mul;
        }

        power++;
    }
    return decimal;
}

long long int octaltodecimal(long long int n){
    
    long long int decimal = anytodecimal(n, 8);
    
    return decimal;
}

long long int binarytodecimal(long long int n){
    
    long long int decimal = anytodecimal(n, 2);
    
    return decimal;
}

long long int anytodecimal(long long int n, int base){

    long long int decimal = 0;
    int size = to_string(n).size();
    for(int i=0; i<size; i++){
        int last_digit = n%10;
        int mul = last_digit * pow(base,i);
        decimal += mul;
        n /= 10;
    }
    
    return decimal;

}

string hexadecimaltobinary(string s){

    string binary_Num;
    
    for(int i=0; i<s.size(); i++){
        switch(s[i])
        {
            case '0':
                binary_Num.append("0000");
                break;
            case '1':
                binary_Num.append("0001");
                break;
            case '2':
                binary_Num.append("0010");
                break;
            case '3':
                binary_Num.append("0011");
                break;
            case '4':
                binary_Num.append("0100");
                break;
            case '5':
                binary_Num.append("0101");
                break;
            case '6':
                binary_Num.append("0110");
                break;
            case '7':
                binary_Num.append("0111");
                break;
            case '8':
                binary_Num.append("1000");
                break;
            case '9':
                binary_Num.append("1001");
                break;
            case 'A':
            case 'a':
                binary_Num.append("1010");
                break;
            case 'B':
            case 'b':
                binary_Num.append("1011");
                break;
            case 'C':
            case 'c':
                binary_Num.append("1100");
                break;
            case 'D':
            case 'd':
                binary_Num.append("1101");
                break;
            case 'E':
            case 'e':
                binary_Num.append("1110");
                break;
            case 'F':
            case 'f':
                binary_Num.append("1111");
                break;
            default:
                cout<<endl<<"Enter Proper Hexadecimal Number"<<endl;
        }
    }
    
    return binary_Num;
}

string octaltobinary(long long int n){
    string s = to_string(n);
    string binary_Num = "";
    
    for(int i=0; i<s.size(); i++){
        switch(s[i])
        {
            case '0':
                binary_Num.append("000");
                break;
            case '1':
                binary_Num.append("001");
                break;
            case '2':
                 binary_Num.append("010");
                break;
            case '3':
                binary_Num.append("011");
                break;
            case '4':
                binary_Num.append("100");
                break;
            case '5':
                binary_Num.append("101");
                break;
            case '6':
                binary_Num.append("110");
                break;
            case '7':
                binary_Num.append("111");
                break;
            default:
                cout<<"\nEnter Proper Octal Number!"<<endl;
                return "";
         }
    }
    
    return binary_Num;

}

string decimaltobinary(long long int n){
    string binary = decimaltoany(n, 2);

    return binary;
}

string decimaltoany(long long int n, int base){
    string remainder = "";
    long long int quotient = n;

    
    while(quotient != 0){
        remainder += to_string(quotient%base);
        quotient /= base;
    }

    reverse(remainder.begin(), remainder.end());

    return remainder;
}