#include<iostream>
#include<string>
#include<vector>

using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << "* ";
        }
        cout << endl;
    }

}
void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
}
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern5(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern6(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
}
void pattern7(int n){
    for(int i=0;i<n;i++){
        //spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }

        //stars
        for(int j=0;j<2*i+1;j++){
            cout << "*";
        }

        //spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }

        cout << endl;
    }
}
void pattern8(int n){
    for(int i=0;i<n;i++){

        for(int j=0;j<i;j++){
            cout << " ";
        }

        for(int j = 0;j<2*n-(2*i+1);j++){
            cout << "*";
        }

        for(int j=0;j<i;j++){
            cout << " ";
        }

        cout << endl;
    }
}
void pattern9(int n){
    pattern7(n);
    pattern8(n);
}
void pattern10(int n){
    for(int i=0;i<2*n-1;i++){
        int stars = i;
        if(i >= n){stars = 2*n-(i+1)-1;}
        for(int j=0;j<=stars;j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}
void pattern11(int n){
    int digit = 1;
    for(int i=0;i<n;i++){
        if(i % 2 == 0){digit = 1;}
        else{digit = 0;}
        for(int j=0;j<=i;j++){
            cout << digit << " ";
            (digit == 1) ? (digit = 0) : (digit = 1);
        }
        cout << endl;
    }
}
void pattern12(int n){
    for(int i=0;i<n;i++){

        //numbers
        for(int j=0;j<=i;j++){
            cout << j+1;
        }
        
        //spaces
        for(int j=0;j<2*(n-i-1);j++){
            cout << " ";
        }

        //numbers
        for(int l=i+1;l>0;l--){
            cout << l;
        }
        cout << endl;
    }
}
void pattern13(int n){
    int num = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}
void pattern14(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern15(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+(n-i-1);j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern16(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << char('A'+i) << " ";
        }
        cout << endl;
    }
}
void pattern17(int n){
    for(int i=0;i<n;i++){
        //spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }

        //letters
        char ch='A';
        for(int j=0;j<2*i+1;j++){
            cout << ch;
            if(j<(2*i+1)/2){ch++;}
            else{ ch--;}
        }

        //spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }

        cout << endl;
    }
}
void pattern18(int n){
    for(int i=0;i<n;i++){
        char ch = 'A'+n-1-i;
        for(int j=0;j<=i;j++){
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}
void pattern19(int n){
    int spaces = 0;
    for(int i=0;i<n;i++){
        
        //stars
        for(int j=0;j<n-i;j++){
            cout << "*";
        }

        //spaces
        for(int k=0;k<spaces;k++){
            cout << " ";
        }

        //stars
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        spaces += 2;
        cout << endl;
    }


    int spaces_2 = 2*n-2;
    for(int i=0;i<n;i++){
        
        //stars
        for(int j=0;j<=i;j++){
            cout << "*";
        }

        //spaces
        for(int k=0;k<spaces_2;k++){
            cout << " ";
        }

        //stars
        for(int j=0;j<=i;j++){
            cout << "*";
        }


        spaces_2 -= 2;
        cout << endl;
    }
}
void pattern20(int n){
    int spaces = 2*n-2;
    for(int i=1;i<=2*n-1;i++){
        int stars = i;

        if(i > n){stars = 2*n-i;}

        for(int j=1;j<=stars;j++){
            cout << "*";
        }

        for(int k=0;k<spaces;k++){
            cout << " ";
        }

        for(int j=1;j<=stars;j++){
            cout << "*";
        }

        if(i<n){spaces -= 2;}
        else{spaces += 2;}

        cout << endl;
    }
}
void pattern21(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
void pattern22(int n){
    for(int i=1;i<=(2*n)-1;i++){
        for(int j=1;j<=(2*n)-1;j++){
            int top = i-1;
            int left = j-1;
            int bottom = (2*n-1)-i;
            int right = (2*n-1)-j;
            int num = n - min(min(top,bottom),min(left,right));
            cout << num;
        }
        cout << endl;
    }
}
void pattern23(int n){
    int spaces = 1;
    for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                cout << " ";
            }
            cout << "*";
            
            if(i > 0){
                for(int k=0;k<spaces;k++){
                    cout << " ";
                }
                spaces += 2;
            }
            
            if(i > 0){cout << "*";}
            cout << endl;
        }

        int spaces_2 = 2*n-5;
    for(int i=0;i<n-1;i++){
        
        for(int j=0;j<=i;j++){
            cout << " ";
        }
        cout << "*";
        
        if(i < n-1){
            for(int k=0;k<spaces_2;k++){
                cout << " ";
            }
            spaces_2 -= 2;
        }

        if(i < n-2){cout << "*";}
        cout << endl;
        
    }
}

int main(){
    
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        pattern23(n);
    }


    return 0;
}